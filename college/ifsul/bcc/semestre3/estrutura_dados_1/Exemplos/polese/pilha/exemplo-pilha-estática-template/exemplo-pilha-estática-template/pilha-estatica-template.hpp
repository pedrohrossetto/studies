#ifndef _HPP_PILHA_ESTATICA_TEMPLATE
#define _HPP_PILHA_ESTATICA_TEMPLATE

#include <iomanip> //biblioteca usada para formatar a impressão da pilha

template<typename T>
struct Pilha
{
    int tam;
    int base;
    int topo;
    T *dados; //Vetor que será alocado para armazenar os elementos da pilha

    Pilha() //Construtor. Usado para inicializar os dados das variáveis da struct
    {
        tam=0;
        base = -1;
        topo = -1;
        dados = NULL;
    }
};



///inicialização dos dados da pilha
template<typename T>
void inicializaP(Pilha<T> *p, int tam)
{
    p->base = -1; ///  (*p).base = -1;  /// p->base  p.topo
    p->topo = -1;
    p->tam  =  tam;
    p->dados = new T[tam];///aloca memória dinamicamente
}


//retorna true se a pilha foi inicializada
//retorna false se a pilha não foi inicializada
template<typename T>
bool verificaInicializacaoP(Pilha<T> *p) //verifica de a pilha foi inicializada
{
    if(p->dados != NULL)
        return true;
    else
        return false;
}


template<typename T>
void destroiP(Pilha<T> *p)
{
    p->base = -1;
    p->topo = -1;
    p->tam = 0;

    if(p->dados != NULL)
    {
        delete[] (p->dados);
        p->dados = NULL;
    }
}

template<typename T>
bool cheiaP(Pilha<T> *p)
{
    if (p->topo == p->tam - 1)
        return true;
    else
        return false;
}

template<typename T>
bool vaziaP(Pilha<T> *p)
{
    if (p->topo == p->base)
        return true;
    else
        return false;
}

///push
template<typename T>
bool empilhaP(Pilha<T> *p, T valor) ///push
{
    /// retorna false se a pilha não foi inicializada ou se ela está cheia
    if (verificaInicializacaoP(p)==false || cheiaP(p)==true)
        return false;
    else{
        p->topo++;
        p->dados[p->topo] = valor;
        return true;
    }
}

///pop
template<typename T>
T desempilhaP(Pilha<T> *p) ///pop
{

    T valor; //inicializar a variável valor, a qual será retornada

    ///se a pilha foi inicializada && se não estiver vazia, retira valor
    if (vaziaP(p)==false)
    {
        valor = p->dados[p->topo];
        p->topo--;
    }

    return valor;
}



///peek
template<typename T>
T espiaP(Pilha<T> *p) ///peek
{
    T valor; //inicializar a variável valor, a qual será retornada

    if (vaziaP(p)==false)
    {
        valor = p->dados[p->topo];
    }

    return valor;
}


template<typename T>
void mostraP(Pilha<T> *p, string nome="")
{

    cout << "PILHA: " << nome << endl;
    cout << "TAM: " << p->tam << endl;
    cout << "TOPO: " << p->topo << endl;
    if(vaziaP(p) == false)
    {
        cout << "------------------------" << endl;
        for(int i = p->topo; i > p->base; i--)
        {
            cout << i << "- " << p->dados[i] << endl;
            cout << "------------------------" << endl;
        }
    }
    cout << endl;
    fflush(stdout);
}

/// retorna true se o valor existe na pilha
/// retorna false se o valor não existe na pilha
template<typename T>
bool buscaP(Pilha<T> *p, T valor)
{

   for(int i = p->topo ; i > p->base; i--)
   {
       if (valor == p->dados[i])
          return true;
   }
   return false;

}



#endif // _HPP_PILHA_ESTATICA_TEMPLATE





