#ifndef _HPP_PILHA_DINAMICA_TEMPLATE
#define _HPP_PILHA_DINAMICA_TEMPLATE

#include <iomanip> //biblioteca usada para formatar a impress�o da pilha
#include <iostream>
#include <string>
template<typename T>
struct NoPilha
{
    T dado; //informao do no
    NoPilha *prox; //pr�ximo elemento
};

template<typename T>
struct Pilha
{
    NoPilha<T> *topo;

    Pilha(){ //Construtor. Inicializa��o da pilha
        topo = nullptr;
    }
};

template<typename T>
bool vaziaP(Pilha<T> *p)
{
    if (p->topo == NULL)
        return true;
    else
        return false;
}


//push
template<typename T>
bool empilhaP(Pilha<T> *p, T dado)
{
    NoPilha<T> *novo =  new NoPilha<T>(); //cria um novo n�
    if (novo == NULL) /// sistema n�o conseguiu alocar a mem�ria
        return false;

    novo->dado = dado; //armazena a informa��o no n�
    novo->prox = p->topo; //o pr�ximo elemento do n� criado ser� o �ltimo elemento da pilha
    p->topo = novo; //atualiza o topo da pilha para o n� criado.
    return true;
}

//pop
template<typename T>
T desempilhaP(Pilha<T> *p)
{
    T dado;

    // se n�o estiver vazia, retira valor
    if (vaziaP(p) == false)
    {
        dado = p->topo->dado; //pega o dado armazenado no n� do topo
        NoPilha<T> *apagar = p->topo; //guarda o n� do topo em uma vari�vel auxiliar;
        p->topo = p->topo->prox; //atualiza o topo para o pr�ximo elemento;

        delete apagar;  /// libera a mem�ria
    }

    return dado;
}

//peek
template<typename T>
T espiaP(Pilha<T>* p)
{
    T dado;

    if (vaziaP(p) == false)
        dado = p->topo->dado;

    return dado;
}


template<typename T>
// Adicionado std:: antes de string
void mostraP(Pilha<T> *p, std::string tipo="") 
{
    // Adicionado std:: antes de endl em todos os lugares
    std::cout << "PILHA: " << tipo << std::endl;

    if(vaziaP(p) == false)
    {
        std::cout << "--------------------------------------------" << std::endl;
        std::cout << std::setfill(' ') << std::setw(13) << "No" << " | ";
        std::cout << std::setfill(' ') << std::setw(13) << "Prox" << " | ";
        std::cout << std::setfill(' ') << std::setw(10) << "Dado" << " |" << std::endl;
        std::cout << "--------------------------------------------" << std::endl;
        NoPilha<T> *no = p->topo;
        while (no != NULL)
        {
            std::cout << std::setfill(' ') << std::setw(13) << no << " | ";
            std::cout << std::setfill(' ') << std::setw(13) << no->prox << " | ";
            std::cout << std::setfill(' ') << std::setw(10) << no->dado << " |" << std::endl;

            no = no->prox;
        }
        std::cout << "--------------------------------------------" << std::endl;
    }
}

/// retorna true se o valor existe na pilha
/// retorna false se o valor n�o existe na pilha
template<typename T>
bool buscaP(Pilha<T> *p, T dado)
{

    NoPilha<T> *no = p->topo;
    while (no != NULL)
    {
        if(no->dado == dado)
            return true;

        no = no->prox;
    }

    return false;

}

template<typename T>
void destroiP(Pilha<T> *p)
{
    T dado;
    while(vaziaP(p) == false)
        dado = desempilhaP(p); //desempilha e descarta o valor desempilhado
}


template<typename T>
// Adicionado std:: antes de string
void percorreP(Pilha<T> *p) 
{
    if(vaziaP(p) == false)
    {
        NoPilha<T> *no = p->topo;
        while (no != NULL)
        {            
            std::cout << no->dado << " | " << no << " | " << no->prox << std::endl;
            no = no->prox;
        }
    }
}


#endif // _HPP_PILHA_DINAMICA





