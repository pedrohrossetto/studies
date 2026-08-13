
#ifndef _HPP_FILA
#define _HPP_FILA

struct aviao
{
    int codigo;
    int num_pas;
    string empresa;
};

struct Fila
{
    int tam;      // tamanho do vetor de dados
    int total;    // total de elementos armazenados na fila
    int inicio;   // ponteiro para o elemento armazenado no inicio da fila
    int fim;      // ponteiro para o fim da fila (posi��o do vetor onde ser� armazenado o pr�ximo elemento)
    aviao *dados; // ponteiro para o vetor que ser� alocado para armazenar os dados

    Fila() // Construtor. Usado para inicializar os dados das vari�veis da struct
    {
        tam = 0;
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
    f->dados = new aviao[tam]; /// aloca mem�ria para vetor
}

bool verificaInicializacaoF(Fila *f) // verifica de a fila foi inicializada
{
    if (f->dados != NULL)
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

    if (verificaInicializacaoF(f) == true)
    {
        delete[] (f->dados);
        f->dados = nullptr;
    }
}

bool vaziaF(Fila *f) // fila vazia
{
    if (f->total == 0)
        return true;
    else
        return false;
}

bool cheiaF(Fila *f) // fila cheia
{
    if (f->total == f->tam)
        return true;
    else
        return false;
}

// Enqueue
bool enfileiraF(Fila *f, aviao valor) /// incluir valor na fila
{
    if (verificaInicializacaoF(f) == false || cheiaF(f) == true) // retorna false se a fila n�o foi inicializada ou se cheia
        return false;

    // inserir no final da fila
    f->dados[f->fim] = valor;

    // incrementa a quantidade de elementos armazenados na fila
    f->total++;

    // avan�a o ponteiro fim
    f->fim++;

    if (f->fim >= f->tam)
        f->fim = 0; // circular

    return true;
}

// Dequeue
aviao desenfileiraF(Fila *f) // retirar da fila
{
    int valor = 0;

    if (f->total == 0)
    {
        return {-1, 0, ""};
    }
    // remover do inicio da fila
    aviao removido = f->dados[f->inicio];

    // diminui a quantidade de elementos armazenados na fila
    f->total--;

    // avan�a o ponteiro in�cio
    f->inicio++;

    if (f->inicio >= f->tam)
        f->inicio = 0; // circular

    return removido;
}

// Peek
aviao espiaF(Fila *f) /// peek
{
    aviao valor = {-1, 0, ""};

    if (f->total == 0)
        return {0, 0, ""};

    valor = f->dados[f->inicio];
    return valor;
}

aviao cadastrarAviao(Fila *f)
{
    aviao novo; // Struct local

    cout << "Digite o codigo do aviao: ";
    cin >> novo.codigo;

    cout << "Digite o numero de passageiros: ";
    cin >> novo.num_pas;

    cout << "Digite o nome da empresa: ";
    cin >> novo.empresa;

    // Agora envia a struct preenchida para a função que você criou
    if (enfileiraF(f, novo))
    {
        cout << "Aviao cadastrado com sucesso!" << endl;
    }
    else
    {
        cout << "Erro: Fila cheia ou nao inicializada." << endl;
    }
}

bool mostraTotal(Fila *f)
{
    if (vaziaF(f) == true)
    {
        return false;
    }
    else
        cout << "\nNum de avioes a espera de decolar: " << f->total;
    return true;
}

void MostraTudo(Fila *f)
{

    if (vaziaF(f) == true)
    {
        cout << "\nsem avioes!!!";
    }
    else
        for (int i = 0; i < f->total; i++)
        {
            cout << "\n\nAviao [" << i + 1 << "]:\n codigo: " << f->dados[f->inicio + i].codigo;
            cout << "\n num passageiros: " << f->dados[f->inicio + i].num_pas;
            cout << "\n empresa: " << f->dados[f->inicio + i].empresa;
        }
}

#endif // _HPP_FILA
