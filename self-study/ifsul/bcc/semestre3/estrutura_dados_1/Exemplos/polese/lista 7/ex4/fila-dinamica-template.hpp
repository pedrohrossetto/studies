#ifndef _HPP_FILA_DINAMICA_TEMPLATE
#define _HPP_FILA_DINAMICA_TEMPLATE

template<typename T>
struct NoFila
{
    T dado; //informacao do nó
    NoFila *prox; //proximo elemento da fila
};

template<typename T>
struct Fila
{
    NoFila<T> *inicio;
    NoFila<T> *fim;

    Fila(){ //Construtor. Usado para inicializar os dados das variáveis da struct
        inicio = nullptr;
        fim = nullptr;
    }
};


template<typename T>
bool vaziaF(Fila<T> *f)
{
    if (f->inicio == NULL) //verifica se a fila está vazia, ou seja, (f->inicio == NULL)
        return true;
    else
        return false;
}


//Enqueue
template<typename T>
bool enfileiraF(Fila<T> *f, T dado)
{
    NoFila<T> *novo = new NoFila<T>();
    if (novo == NULL) /// não conseguiu alocar memória (novo == NULL)
        return false;

    novo->dado = dado;
    novo->prox = nullptr;
    if (f->inicio == NULL) //verifica se a fila está vazia, ou seja, (f->inicio == NULL)
        f->inicio = novo;
    else
        f->fim->prox = novo;

    f->fim = novo;
    return true;
}

//Dequeue
template<typename T>
T desenfileiraF(Fila<T> *f)
{
    T dado;

    // se não estiver vazia, retira valor
    if (vaziaF(f) == false) //verifica se a fila não está vazia, ou seja, (f->inicio != NULL)
    {
        dado = f->inicio->dado; //pega o dado armazenado no primeiro nó
        NoFila<T> *apagar = f->inicio; //guarda o primeiro nó em uma variável auxiliar;
        f->inicio = f->inicio->prox; // atualiza o início da fila
        delete apagar;  // libera a memória

        if (f->inicio == NULL) //verifica se a fila está vazia, ou seja, (f->inicio == NULL)
            f->fim = nullptr;
    }

    return dado;
}

//peek
template<typename T>
T espiaF(Fila<T>* f)
{
    T dado;

    if (vaziaF(f) == false) //verifica se a fila não está vazia, ou seja, (f->inicio != NULL)
    {
        dado = f->inicio->dado;
    }

    return dado;
}

//show
template<typename T>
void mostraF(Fila<T> *f, string nome="")
{
    cout << "Fila " << nome << " : ";

    if(vaziaF(f) == false) //verifica se a fila não está vazia
    {

        cout << "[";

        NoFila<T> *no = f->inicio;
        while (no != NULL) //faça enquanto (no != NULL)
        {
            cout << no->dado;
            no = no->prox;

            if(no != NULL) //verifica se o próximo nó não é nulo (no != NULL)
                cout << ", ";
        }
        cout << "]" << endl;
    }
    else
        cout << "vazia!\n";
}

// retorna true se o valor existe na fila
// retorna false se o valor não existe na fila
template<typename T>
bool buscaF(Fila<T> *f, T dado)
{

    NoFila<T> *no = f->inicio;
    while (no != NULL) //faça enquanto (no != NULL)
    {
        if(no->dado == dado)
            return true;

        no = no->prox;
    }

    return false;
}

template<typename T>
void destroiF(Fila<T> *f)
{

    NoFila<T> *no = f->inicio;
    while (no != NULL) //faça enquanto (no != NULL)
    {
        NoFila<T> *apagar = no; //guarda o nó em uma variável auxiliar;

        no = no->prox;

        delete apagar;
    }

    f->inicio = nullptr;
    f->fim = nullptr;
}

#endif // _HPP_FILA_DINAMICA





