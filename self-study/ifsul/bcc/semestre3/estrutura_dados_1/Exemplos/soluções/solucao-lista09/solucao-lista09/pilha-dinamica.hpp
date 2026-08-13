#ifndef _HPP_PILHA_DINAMICA
#define _HPP_PILHA_DINAMICA

#include <iomanip> //biblioteca usada para formatar a impressão da pilha


struct NoPilha
{
    Ficha dado; //informação do nó
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
bool empilhaP(Pilha *p, Ficha dado)
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
Ficha desempilhaP(Pilha *p)
{
    Ficha dado;

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
Ficha espiaP(Pilha* p)
{
    Ficha dado;

    if (vaziaP(p) == false)
        dado = p->topo->dado;

    return dado;
}
void destroiP(Pilha *p)
{
    Ficha dado;
    while(vaziaP(p) == false)
        dado = desempilhaP(p); //desempilha e descarta o valor desempilhado
}

//########## Funções adaptadas para o trabalho##########
void mostraP(Pilha *p)
{


    if(vaziaP(p) == false)
    {
        cout << "###CADASTRO###" << endl;
        cout << "Código\tNome\tIdade\tSaldo\n";
        NoPilha *no = p->topo;
        while (no != NULL)
        {
            cout << no->dado.codigo << "\t" << no->dado.nome << "\t";
            cout << no->dado.idade << "\t"  << no->dado.saldo << "\n";

            no = no->prox;
        }
        cout << endl;
    }
    else
        cout << "Pilha vazia! Não há clientes cadastrados!\n";
}

bool buscaCodigoP(Pilha *p, int cod)
{

    NoPilha *no = p->topo;
    while (no != NULL)
    {
        if(no->dado.codigo == cod)
            return true;

        no = no->prox;
    }

    return false;
}

Ficha buscaFichaP(Pilha *p, int cod)
{

    NoPilha *no = p->topo;
    while (no != NULL)
    {
        if(no->dado.codigo == cod)
        {
            return no->dado;
        }
        no = no->prox;
    }

    //ficha não foi encontrada na pilha
    Ficha ficha;
    ficha.codigo = -1;
    ficha.nome = "";
    ficha.idade = -1;
    ficha.saldo = 0;
    return ficha;
}


bool empilhaOrdenadoP(Pilha *p, Ficha ficha)
{
    Pilha aux;

    //passo 1
    while(!vaziaP(p) && ficha.nome > p->topo->dado.nome)
    {
        Ficha x = desempilhaP(p);
        empilhaP(&aux, x);
    }

    //passo 2
    empilhaP(p, ficha);

    //passo 3
    while(!vaziaP(&aux))
    {
        Ficha x = desempilhaP(&aux);
        empilhaP(p, x);
    }

    destroiP(&aux);
    return true;
}

float somaSaldoBanco(Pilha *p)
{
    NoPilha *no = p->topo;
    float soma=0;
    while (no != NULL)
    {
        soma += no->dado.saldo;
        no = no->prox;
    }

    return soma;
}

void atualizaSaldo(Pilha *p, char operacao, int cod, float valor){

    NoPilha *no = p->topo;
    while (no != NULL)
    {
        if(no->dado.codigo == cod)
        {
            if(operacao == 'D')
                no->dado.saldo += valor;
            else if(operacao == 'S')
                no->dado.saldo -= valor;

            break;
        }
        no = no->prox;
    }

}


void dadosBanco(Pilha *p, int *contCli, int *contCliNeg, float *saldoM, float *saldoSoma){

    *contCli=0;
    *contCliNeg=0;
    *saldoSoma=0;

    NoPilha *no = p->topo;
    while (no != NULL)
    {
        *saldoSoma += no->dado.saldo;
        (*contCli)++;
        if(no->dado.saldo<0)
            (*contCliNeg)++;

        no = no->prox;
    }

    if(*contCli>0)
        *saldoM = (*saldoSoma) / (*contCli);
    else
        *saldoM  = 0;

}






#endif // _HPP_PILHA_DINAMICA





