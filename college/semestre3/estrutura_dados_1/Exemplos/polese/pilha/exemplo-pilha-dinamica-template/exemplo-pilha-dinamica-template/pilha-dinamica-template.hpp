#ifndef _HPP_PILHA_DINAMICA_TEMPLATE
#define _HPP_PILHA_DINAMICA_TEMPLATE

#include <iomanip> //biblioteca usada para formatar a impressão da pilha

template<typename T>
struct NoPilha
{
    T dado; //informação do nó
    NoPilha *prox; //próximo elemento
};

template<typename T>
struct Pilha
{
    NoPilha<T> *topo;

    Pilha(){ //Construtor. Inicialização da pilha
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
    NoPilha<T> *novo =  new NoPilha<T>(); //cria um novo nó
    if (novo == NULL) /// sistema não conseguiu alocar a memória
        return false;

    novo->dado = dado; //armazena a informação no nó
    novo->prox = p->topo; //o próximo elemento do nó criado será o último elemento da pilha
    p->topo = novo; //atualiza o topo da pilha para o nó criado.
    return true;
}

//pop
template<typename T>
T desempilhaP(Pilha<T> *p)
{
    T dado;

    // se não estiver vazia, retira valor
    if (vaziaP(p) == false)
    {
        dado = p->topo->dado; //pega o dado armazenado no nó do topo
        NoPilha<T> *apagar = p->topo; //guarda o nó do topo em uma variável auxiliar;
        p->topo = p->topo->prox; //atualiza o topo para o próximo elemento;

        delete apagar;  /// libera a memória
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
void mostraP(Pilha<T> *p, string tipo="")
{
    cout << "PILHA: " << tipo << endl;

    if(vaziaP(p) == false)
    {
        cout << "--------------------------------------------" << endl;
        cout << setfill(' ') << std::setw(13) << "Nó" << " | ";
        cout << setfill(' ') << std::setw(13) << "Prox" << " | ";
        cout << setfill(' ') << std::setw(10) << "Dado" << " |" << endl;
        cout << "--------------------------------------------" << endl;
        NoPilha<T> *no = p->topo;
        while (no != NULL)
        {
            cout << setfill(' ') << std::setw(13) << no << " | ";
            cout << setfill(' ') << std::setw(13) << no->prox << " | ";
            cout << setfill(' ') << std::setw(10) << no->dado << " |" << endl;

            no = no->prox;
        }
        cout << "--------------------------------------------" << endl;
    }
}

/// retorna true se o valor existe na pilha
/// retorna false se o valor não existe na pilha
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

#endif // _HPP_PILHA_DINAMICA





