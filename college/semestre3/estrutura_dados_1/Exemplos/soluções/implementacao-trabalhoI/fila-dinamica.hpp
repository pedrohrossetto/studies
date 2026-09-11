#ifndef _HPP_FILA_DINAMICA
#define _HPP_FILA_DINAMICA


struct NoFila
{
    Pacote dado; //informacao do nó
    NoFila *prox; //proximo elemento da fila
};

struct Fila
{
    NoFila *inicio;
    NoFila *fim;

    Fila()  //Construtor. Usado para inicializar os dados das variáveis da struct
    {
        inicio = nullptr;
        fim = nullptr;
    }
};


bool vaziaF(Fila *f)
{
    if (f->inicio == NULL) //verifica se a fila está vazia, ou seja, (f->inicio == NULL)
        return true;
    else
        return false;
}


//Enqueue
bool enfileiraF(Fila *f, Pacote dado)
{
    NoFila *novo = new NoFila();
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
Pacote desenfileiraF(Fila *f)
{
    Pacote dado;

    // se não estiver vazia, retira valor
    if (vaziaF(f) == false) //verifica se a fila não está vazia, ou seja, (f->inicio != NULL)
    {
        dado = f->inicio->dado; //pega o dado armazenado no primeiro nó
        NoFila *apagar = f->inicio; //guarda o primeiro nó em uma variável auxiliar;
        f->inicio = f->inicio->prox; // atualiza o início da fila
        delete apagar;  // libera a memória

        if (f->inicio == NULL) //verifica se a fila está vazia, ou seja, (f->inicio == NULL)
            f->fim = nullptr;
    }

    return dado;
}

//peek
Pacote espiaF(Fila* f)
{
    Pacote dado;

    if (vaziaF(f) == false) //verifica se a fila não está vazia, ou seja, (f->inicio != NULL)
    {
        dado = f->inicio->dado;
    }

    return dado;
}

//show
void mostraF(Fila *f, string nome="")
{
    cout << "Fila " << nome << ": ";


    cout << "{";

    NoFila *no = f->inicio;
    while (no != NULL) //faça enquanto (no != NULL)
    {
        cout << "[cod="<< no->dado.codigo << ", peso=" << no->dado.peso << "]";
        no = no->prox;

        if(no != NULL) //verifica se o próximo nó não é nulo (no != NULL)
            cout << ", ";
    }
    cout << "}" << endl;

}

// retorna true se o valor existe na fila
// retorna false se o valor não existe na fila
bool buscaF(Fila *f, int codigo)
{

    NoFila *no = f->inicio;
    while (no != NULL) //faça enquanto (no != NULL)
    {
        if(no->dado.codigo == codigo)
            return true;

        no = no->prox;
    }

    return false;
}

void destroiF(Fila *f)
{

    NoFila *no = f->inicio;
    while (no != NULL) //faça enquanto (no != NULL)
    {
        NoFila *apagar = no; //guarda o nó em uma variável auxiliar;

        no = no->prox;

        delete apagar;
    }

    f->inicio = nullptr;
    f->fim = nullptr;
}

#endif // _HPP_FILA_DINAMICA





