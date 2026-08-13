#ifndef _HPP_PILHA_DINAMICA
#define _HPP_PILHA_DINAMICA

#include <string> //biblioteca usada para formatar a impressão da pilha
#include <iomanip>

#include "cliente.hpp"

struct NoPilha
{
    Cliente dado; //informação do nó
    NoPilha *prox; //próximo elemento
};

struct Pilha
{
    NoPilha *topo;

    Pilha(){ //Construtor. Inicialização da pilha
        topo = nullptr;
    }
};


bool vaziaP(Pilha *p)
{
    if (p->topo == NULL)
        return true;
    else
        return false;
}


//push
bool empilhaP(Pilha *p, Cliente dado)
{
    NoPilha *novo =  new NoPilha(); //cria um novo nó
    if (novo == NULL) /// sistema não conseguiu alocar a memória
        return false;

    novo->dado = dado; //armazena a informação no nó
    novo->prox = p->topo; //o próximo elemento do nó criado será o último elemento da pilha
    p->topo = novo; //atualiza o topo da pilha para o nó criado.
    return true;
}

//pop
Cliente desempilhaP(Pilha *p)
{
    Cliente dado;

    // se não estiver vazia, retira valor
    if (vaziaP(p) == false)
    {
        dado = p->topo->dado; //pega o dado armazenado no nó do topo
        NoPilha *apagar = p->topo; //guarda o nó do topo em uma variável auxiliar;
        p->topo = p->topo->prox; //atualiza o topo para o próximo elemento;

        delete apagar;  /// libera a memória
    }

    return dado;
}

//peek
Cliente espiaP(Pilha* p)
{
    Cliente dado;

    if (vaziaP(p) == false)
        dado = p->topo->dado;

    return dado;
}


void mostraP(Pilha *p, string nome="")
{
    //Ana, código 1, idade 20, saldo 3000



    NoPilha *no = p->topo;
    cout << fixed << setprecision(2);
    while (no != NULL)
    {

        cout << no->dado.nome << ", código " << no->dado.codigo;
        cout << ", idade " << no->dado.idade << ", saldo " << no->dado.saldo << endl;
        no = no->prox;
    }

}

/// retorna true se o valor existe na pilha
/// retorna false se o valor não existe na pilha
bool buscaP(Pilha *p, int codigo)
{

    NoPilha *no = p->topo;
    while (no != NULL)
    {
        if(no->dado.codigo == codigo)
            return true;

        no = no->prox;
    }

    return false;

}

void destroiP(Pilha *p)
{
    Cliente dado;
    while(vaziaP(p) == false)
        dado = desempilhaP(p); //desempilha e descarta o valor desempilhado
}

#endif // _HPP_PILHA_DINAMICA





