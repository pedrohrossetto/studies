#ifndef _HPP_LISTA_DUPLA_TEMPLATE
#define _HPP_LISTA_DUPLA_TEMPLATE

#include <stdexcept>
#include <iostream>
using namespace std;

template<typename T>
struct No
{
    T dado;
    No *prox;
    No *ant;
    No() // construtor
    {
        prox = nullptr;
        ant = nullptr;
    }
};

template<typename T>
struct Lista
{
    No<T> *inicio;
    No<T> *fim;
    int tamanho;
    Lista() /// construtor
    {
        //cout << "\n executando o construtor...\n";
        inicio = nullptr;
        fim = nullptr;
        tamanho =0;
    }
};


template<typename T>
void destroiL(Lista<T> *l)
{
    No<T> *n = l->inicio;
    while(n)
    {
        No<T> *aux = n;
        n = n->prox;
        delete aux;
    }
    l->fim = NULL;
    l->inicio = NULL;
    l->tamanho = 0;
}

template<typename T>
bool vaziaL(Lista<T> *lista)
{
    if(! (lista->inicio) )
        return true;
    else
        return false;
}


template<typename T>
void mostraL(Lista<T> *lista)
{
    No<T> *n = lista->inicio;
    cout << "L[" << lista->tamanho << "]:{";
    while(n)
    {
        cout << n->dado;
        n = n->prox;

        if(n)
            cout << ", ";
    }
    cout << "}" << endl;
}

template<typename T>
void mostrarInversoL(Lista<T> *lista)
{
    No<T> *n = lista->fim;
    cout << "L[" << lista->tamanho << "]:{";
    while(n)
    {
        cout << n->dado;
        n = n->ant;

        if(n)
            cout << ", ";
    }
    cout << "}" << endl;
}


///insere no in�cio da lista
template<typename T>
bool insereInicioL(Lista<T> *lista, T valor)
{

    No<T> *novo = new No<T>();
    if (!novo)
        return false;

    novo->dado = valor;
    novo->ant = nullptr; //Se o novo n� ser� adicionado no in�cio da lista, o ponteiro *ant do primeiro n� sempre � nulo
    novo->prox = lista->inicio;

    if (!lista->fim) //lista vazia?
        lista->fim = novo;
    else
        lista->inicio->ant = novo;

    lista->inicio = novo;
    lista->tamanho++;

    return true;
}

///insere no fim da lista
template<typename T>
bool insereFimL(Lista<T> *lista, T valor)
{

    // Insercao do no na lista

    No<T> *novo = new No<T>();
    if (!novo)
        return false;

    novo->dado = valor;
    novo->ant = lista->fim;
    novo->prox = nullptr;

    // Atualização do descritor da lista

    if (vaziaL(lista)) //lista vazia?
        lista->inicio = novo;
    else
        lista->fim->prox = novo;

    lista->fim = novo;
    lista->tamanho++;

    return true;
}


template<typename T>
T removePrimeiroNo(Lista<T> *lista){

    // 1. Teste se a lista está vazia lançando uma exceção
    if (vaziaL(lista)) {
        throw std::underflow_error("Erro: Tentativa de remover um elemento de uma lista vazia.");
    }

    No<T> *aux = lista->inicio; 
    T retorno_t = aux->dado;

    // Teste se possui apenas um elemento na lista
    if (!(lista->inicio->prox)) {
        lista->inicio = nullptr; // Garantindo que o início também aponte para null
        lista->fim = nullptr;
    }
    else {
        lista->inicio = lista->inicio->prox; 
        lista->inicio->ant = nullptr;
    }

    lista->tamanho--;
    delete aux;
    
    return retorno_t;
}

template<typename T>
T removeUltimoNo(Lista<T> *lista){

    // 1. Teste se a lista está vazia lançando uma exceção
    if (vaziaL(lista)) {
        throw std::underflow_error("Erro: Tentativa de remover um elemento de uma lista vazia.");
    }

    No<T> *aux = lista->fim; 
    T retorno_t = aux->dado;

    // Teste se possui apenas um elemento na lista
    if (!(lista->fim->ant)) {
        lista->inicio = nullptr; // Garantindo que o início também aponte para null
        lista->fim = nullptr;
    }
    else {
        lista->fim = lista->fim->ant; 
        lista->fim->prox = nullptr;   // O novo último nó agora aponta para o vazio
    }

    lista->tamanho--;
    delete aux;
    
    return retorno_t;
}




template<typename T>
No<T>* buscaL(Lista<T> *lista, T valor)
{
    No<T> *n = lista->inicio;
    while (n)
    {
        if (n->dado == valor)
            return n;

        n = n->prox;
    }

    return nullptr;
}

template<typename T>
bool removerNoL(Lista<T> *lista, No<T> *no)
{
    if(!no || !lista || vaziaL(lista))
        return false;

    if (!no->ant) /// se anterior � igual a NULL, o elemento a ser exclu�do est� no in�cio da lista
    {
        lista->inicio = no->prox;
        if (!lista->inicio) ///lista ficou vazia ?
            lista->fim = nullptr;
        else
            lista->inicio->ant = nullptr;

    }else{ /// elemento est� no meio ou no fim

        no->ant->prox = no->prox;
        if (!no->prox)/// se for retirado �ltimo da lista
            lista->fim = no->ant;
        else
            no->prox->ant = no->ant;

    }

    /// libera a mem�ria do elemento
    lista->tamanho--;
    delete(no);
    return true;
}

template<typename T>
bool removeL(Lista<T> *lista, T valor)
{
    No<T>* no = buscaL(lista, valor);

    if(!no)
        return false;

    removerNoL(lista, no);

    return true;
}


#endif // _HPP_LISTA_DUPLA_TEMPLATE



