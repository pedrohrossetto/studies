
#ifndef _HPP_FILA
#define _HPP_FILA


struct Fila
{
    int tam; //tamanho do vetor de dados
    int total; //total de elementos armazenados na fila
    int inicio; //ponteiro para o elemento armazenado no inicio da fila
    int fim; //ponteiro para o fim da fila (posi��o do vetor onde ser� armazenado o pr�ximo elemento)
    int *dados;//ponteiro para o vetor que ser� alocado para armazenar os dados

    Fila() //Construtor. Usado para inicializar os dados das vari�veis da struct
    {
        tam =0;
        total = 0;
        inicio = 0;
        fim = 0;
        dados = nullptr;
    }
};



void inicializaF(Fila *f, int tam) /// inicializa��o da fila
{
    f->tam = tam;
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
    f->dados = new int[tam];/// aloca mem�ria para vetor
}

bool verificaInicializacaoF(Fila *f) //verifica de a fila foi inicializada
{
    if(f->dados != NULL)
        return true;
    else
        return false;
}

void destroiF(Fila *f)
{
    f->fim = 0;
    f->inicio = 0;
    f->total = 0;
    f->tam = 0;

    if(verificaInicializacaoF(f) == true)
    {
        delete[] (f->dados);
        f->dados = nullptr;
    }
}


bool vaziaF(Fila *f)// fila vazia
{
    if (f->total == 0)
        return true;
    else
        return false;
}

bool cheiaF(Fila *f)// fila cheia
{
    if (f->total == f->tam)
        return true;
    else
        return false;
}

//Enqueue
bool enfileiraF(Fila *f, int valor) /// incluir valor na fila
{
    if (verificaInicializacaoF(f)==false || cheiaF(f) == true) // retorna false se a fila n�o foi inicializada ou se cheia
        return false;

    //inserir no final da fila
    f->dados[f->fim] = valor;

    //incrementa a quantidade de elementos armazenados na fila
    f->total++;

    //avan�a o ponteiro fim
    f->fim++;

    if(f->fim>=f->tam)
       f->fim = 0; //circular

    return true;
}

//Dequeue
int desenfileiraF(Fila *f)  //retirar da fila
{
    int valor = 0;

    if (vaziaF(f) == true) // retorna 0 se fila vazia
        return valor;

    //remover do inicio da fila
    valor = f->dados[f->inicio];

    //diminui a quantidade de elementos armazenados na fila
    f->total--;

    //avan�a o ponteiro in�cio
    f->inicio++;

    if(f->inicio>=f->tam)
       f->inicio = 0; //circular

    return valor;
}

//Peek
int espiaF(Fila *f) ///peek
{
    int valor = 0;

    if(vaziaF(f)==true)// retorna 0 se fila vazia
        return valor;

    valor = f->dados[f->inicio];
    return valor;
}


void mostraF(Fila *f)
{
    std::cout << "\nFila{TAM = " << f->tam << ", TOTAL = " <<  f->total << "} -> ";


    if (vaziaF(f) == false)
    {
        int idx = f->inicio;
        std::cout << "[";
        for(int i = 0; i < f->total; i++)
        {
            std::cout << f->dados[idx]; //imprime o dado armazenado na fila

            if(i < f->total-1)
                std::cout << ", ";

            idx++;
            if(idx >= f->tam)
                idx=0; //circular
        }
        std::cout << "]\n";
    }else
        std::cout << "Fila vazia!\n";
}




#endif // _HPP_FILA

