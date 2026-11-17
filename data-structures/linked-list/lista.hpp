#ifndef _HPP_LISTA_DINAMICA
#define _HPP_LISTA_DINAMICA
#include <iostream>
using namespace std;


struct No
{
    int dado;
    struct No *prox;

    No(){};
    No(int dado, No *prox){
        this->dado = dado;
        this->prox = prox;
    }
};


void inicializaL(No **lista)
{
    *lista = NULL;
}

bool vaziaL(No **lista)
{
    if( (*lista) == NULL )
        return true;
    else
        return false;
}

/// excluir todos os elementos da lista
void destroiL(No **lista)
{
    No *n = *lista;
    while (n != NULL)
    {
        No *aux  = n;
        n = n->prox;
        delete aux;
    }
    *lista = NULL;
}

void mostraL(No **lista)
{
    No *n = *lista;

    cout << "L:{";
    while(n != NULL ) /// enquanto n n�o for NULL fica no la�o
    {
        cout << n->dado;
        n = n->prox;

        if(n != NULL)
            cout << ", ";
    }
    cout << "}\n";
}

//insere no in�cio da lista
bool insereInicioL(No **lista, int valor)
{

    No *novo = new No(); // aloca mem�ria para o n�
    if (novo == NULL)
        return false;

    novo->dado = valor;
    novo->prox = *lista;
    *lista = novo;

    return true;
}

//retorna o valor do primeiro elemento da lista SEM remov�-lo
int leInicioL(No **lista)
{
    int dado =0;

    if(vaziaL(lista) == false)
        dado = (*lista)->dado; //atribui o dado do in�cio da lista para a vari�vel dado

    return dado;
}

//retorna o valor do primeiro elemento da lista e REMOVE o elemento
int removeInicioL(No **lista)
{
    No* aux;
    int dado;

    if(vaziaL(lista) == false)
    {
        dado = (*lista)->dado; //atribui o dado do in�cio da lista para a vari�vel dado
        aux = *lista; //pega a referenccia do primeiro n�, o qual ser� removido

        *lista = (*lista)->prox; //atualiza o in�cio da lista para o pr�ximo elemento

        delete aux;
    }

    return dado;
}




///remover um n� da lista com um valor espec�fico
bool removeL(No **lista, int valor)
{
    No *anterior = NULL;
    No *atual = *lista;
    ///fica no la�o enquanto tiver elementos na lista
    /// e n�o encontrar o valor procurado
    while(atual!=NULL && atual->dado != valor)
    {
        anterior = atual;
        atual = atual->prox;
    }
    /// pode sair do la�o sem encontrar o valor (atual==NULL)
    /// se encontrar -> atual tem o endere�o do elemento para excluir
    if(atual == NULL) /// se atual � NULL -> n�o encontrou
        return false;

    if (anterior == NULL)
    {
        /// o elemento a ser exclu�do est� no in�cio da lista
        *lista = atual->prox;
    }
    else   /// elemento est� no meio ou no fim
    {
        anterior->prox = atual->prox;
    }

    /// libera a mem�ria do elemento
    delete(atual);
    return true;
}


No* buscaL(No **lista, int valor)
{
    No *n = *lista;
    while (n != NULL)
    {
        if (n->dado == valor)
            return n;

        n = n->prox;
    }

    return NULL;
}

void mapearNovoNoApos(No *no, int valor){
    // Reendereçaento de ponteiro inserindo novo nó apos o nó passado como argumento
    // no -> novo -> prox
    No *novo = new No(valor,no->prox); // aloca memoria para o no
    no->prox = novo;
}

//insere “valor” após a primeira ocorrência de um valor par na lista 
  void inserePrimeiroPar(No **lista, int valor)
{
    No *atual = *lista;
    ///fica no while enquanto tiver elementos na lista
    /// e nao encontrar no com valor par
    while(atual!=NULL && atual->dado % 2 != 0)
    {
        atual = atual->prox;
    }
    // Lista Vazia e se não possui pares
    if (atual != NULL) 
    {
        mapearNovoNoApos(atual, valor);
    }
    return;
    
}

void insereAntesPrimeiroPar(No **lista, int valor){
    No *atual = *lista;
    No *anterior = NULL;
    ///fica no while enquanto tiver elementos na lista
    /// e nao encontrar no com valor par
    while(atual!=NULL && atual->dado % 2 != 0)
    {
        anterior = atual;
        atual = atual->prox;
    }
    // Lista Vazia e se não possui pares
    if (atual) // anterior != NULL 
    {
        No *novo = new No(valor, atual);
        if(!anterior) // anterior == NULL
        {
            *lista = novo;
        }
        else
        {
            anterior->prox = novo;
        }
    }
    return;
}

#endif // _HPP_LISTA_DINAMICA









