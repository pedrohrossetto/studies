#ifndef _HPP_FILA_DINAMICA_TEMPLATE
#define _HPP_FILA_DINAMICA_TEMPLATE

#include <iomanip>
#include <iostream>
#include <string>

template<typename T>
struct NoFila
{
    T dado;
    NoFila *prox;
};

template<typename T>
struct Fila
{
    NoFila<T> *inicio;
    NoFila<T> *fim;

    Fila(){
        inicio = nullptr;
        fim = nullptr;
    }
};

template<typename T>
bool vaziaF(Fila<T> *f)
{
    return (f->inicio == nullptr);
}

// Enfileirar (Entra no final da fila)
template<typename T>
bool enfileiraF(Fila<T> *f, T dado)
{
    NoFila<T> *novo = new NoFila<T>();
    if (novo == nullptr) 
        return false;

    novo->dado = dado;
    novo->prox = nullptr;

    if (vaziaF(f)) {
        f->inicio = novo;
    } else {
        f->fim->prox = novo;
    }
    
    f->fim = novo;
    return true;
}

// Desenfileirar (Sai do início da fila)
template<typename T>
T desenfileiraF(Fila<T> *f)
{
    T dado = T(); // Retorna o valor padrão caso a fila esteja vazia

    if (vaziaF(f) == false)
    {
        dado = f->inicio->dado;
        NoFila<T> *apagar = f->inicio;
        
        f->inicio = f->inicio->prox;
        
        // Se a fila esvaziou, o fim também deve ser nulo
        if (f->inicio == nullptr) {
            f->fim = nullptr;
        }

        delete apagar;
    }

    return dado;
}

// Espiar (Olha quem é o primeiro da fila)
template<typename T>
T espiaF(Fila<T>* f)
{
    T dado = T();

    if (vaziaF(f) == false)
        dado = f->inicio->dado;

    return dado;
}

template<typename T>
void mostraF(Fila<T> *f, std::string tipo="") 
{
    std::cout << "FILA: " << tipo << std::endl;

    if(vaziaF(f) == false)
    {
        std::cout << "--------------------------------------------" << std::endl;
        std::cout << std::setfill(' ') << std::setw(13) << "No" << " | ";
        std::cout << std::setfill(' ') << std::setw(13) << "Prox" << " | ";
        std::cout << std::setfill(' ') << std::setw(10) << "Dado" << " |" << std::endl;
        std::cout << "--------------------------------------------" << std::endl;
        
        NoFila<T> *no = f->inicio;
        while (no != nullptr)
        {
            std::cout << std::setfill(' ') << std::setw(13) << no << " | ";
            std::cout << std::setfill(' ') << std::setw(13) << no->prox << " | ";
            std::cout << std::setfill(' ') << std::setw(10) << no->dado << " |" << std::endl;

            no = no->prox;
        }
        std::cout << "--------------------------------------------" << std::endl;
    }
}

template<typename T>
bool buscaF(Fila<T> *f, T dado)
{
    NoFila<T> *no = f->inicio;
    while (no != nullptr)
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
    while(vaziaF(f) == false)
        desenfileiraF(f); 
}

template<typename T>
void percorreF(Fila<T> *f) 
{
    if(vaziaF(f) == false)
    {
        NoFila<T> *no = f->inicio;
        while (no != nullptr)
        {            
            std::cout << no->dado << " | " << no << " | " << no->prox << std::endl;
            no = no->prox;
        }
    }
}

// ==========================================
// NOVAS FUNÇÕES ADAPTADAS PARA FILA
// ==========================================

// 1. Percorrer fila inversamente
template<typename T>
void percorreInversoAuxF(NoFila<T> *no)
{
    if (no == nullptr) return;
    percorreInversoAuxF(no->prox);
    std::cout << no->dado << " | " << no << " | " << no->prox << std::endl;
}

template<typename T>
void percorreFilaInversamenteF(Fila<T> *f)
{
    if(vaziaF(f) == false) {
        percorreInversoAuxF(f->inicio);
    }
}

// 2. Ordena fila crescente (Bubble sort trocando dados diretamente na estrutura)
template<typename T>
void ordenaFilaCrescenteF(Fila<T> *f)
{
    if(vaziaF(f) || f->inicio->prox == nullptr) return;

    bool trocou;
    do {
        trocou = false;
        NoFila<T> *atual = f->inicio;
        while(atual->prox != nullptr) {
            if(atual->dado > atual->prox->dado) {
                T temp = atual->dado;
                atual->dado = atual->prox->dado;
                atual->prox->dado = temp;
                trocou = true;
            }
            atual = atual->prox;
        }
    } while(trocou);
}

// 3. Separa fila
template<typename T>
void separaFilaF(Fila<T> *origem, Fila<T> *f1, Fila<T> *f2)
{
    bool turno = true;
    while(!vaziaF(origem)) {
        if(turno) {
            enfileiraF(f1, desenfileiraF(origem));
        } else {
            enfileiraF(f2, desenfileiraF(origem));
        }
        turno = !turno;
    }
}

// 4. Combina fila
template<typename T>
void combinaFilaF(Fila<T> *destino, Fila<T> *f1, Fila<T> *f2)
{
    while(!vaziaF(f1) || !vaziaF(f2)) {
        if(!vaziaF(f1)) enfileiraF(destino, desenfileiraF(f1));
        if(!vaziaF(f2)) enfileiraF(destino, desenfileiraF(f2));
    }
}

// 5. Fura fila (Insere diretamente no INÍCIO da fila, passando na frente de todos)
template<typename T>
bool furaFilaF(Fila<T> *f, T dado)
{
    NoFila<T> *novo = new NoFila<T>();
    if (novo == nullptr) return false;
    
    novo->dado = dado;
    novo->prox = f->inicio;
    
    f->inicio = novo;
    
    // Se a fila estava vazia, o primeiro também é o último
    if(f->fim == nullptr) {
        f->fim = novo;
    }
    
    return true;
}

// 6. Fila prioritária (Encontra a posição baseada em ordem crescente e insere)
template<typename T>
bool inserePrioridadeF(Fila<T> *f, T dado)
{
    NoFila<T> *novo = new NoFila<T>();
    if (novo == nullptr) return false;
    novo->dado = dado;

    // Se estiver vazia ou o dado for menor que o primeiro, fura a fila
    if (vaziaF(f) || dado <= f->inicio->dado) {
        novo->prox = f->inicio;
        f->inicio = novo;
        if (f->fim == nullptr) f->fim = novo;
        return true;
    }

    // Busca a posição correta
    NoFila<T> *atual = f->inicio;
    while (atual->prox != nullptr && atual->prox->dado < dado) {
        atual = atual->prox;
    }

    novo->prox = atual->prox;
    atual->prox = novo;

    // Se foi inserido no final, atualiza o ponteiro de fim
    if (novo->prox == nullptr) {
        f->fim = novo;
    }

    return true;
}

// 7. Média de fila
template<typename T>
double mediaFilaF(Fila<T> *f)
{
    if(vaziaF(f)) return 0.0;
    
    double soma = 0;
    int contador = 0;
    NoFila<T> *no = f->inicio;
    
    while(no != nullptr) {
        soma += no->dado;
        contador++;
        no = no->prox;
    }
    
    return soma / contador;
}

// 8. Inverte fila (Usando recursão para respeitar a estrutura FIFO sem variáveis extras)
template<typename T>
void inverteFilaF(Fila<T> *f)
{
    if(vaziaF(f)) return;
    
    T dado = desenfileiraF(f); // Tira o primeiro
    inverteFilaF(f);           // Inverte o resto da fila
    enfileiraF(f, dado);       // Coloca o que saiu de volta no final
}

// 9. Busca posição valor fila (0 = Início da fila)
template<typename T>
int buscaPosicaoFilaF(Fila<T> *f, T dado)
{
    int posicao = 0;
    NoFila<T> *no = f->inicio;
    
    while(no != nullptr) {
        if(no->dado == dado) return posicao;
        posicao++;
        no = no->prox;
    }
    return -1;
}

// 10. Busca maior e menor valor
template<typename T>
void buscaMaiorMenorFilaF(Fila<T> *f, T &maior, T &menor)
{
    if(vaziaF(f)) return;
    
    NoFila<T> *no = f->inicio;
    maior = no->dado;
    menor = no->dado;
    no = no->prox;
    
    while(no != nullptr) {
        if(no->dado > maior) maior = no->dado;
        if(no->dado < menor) menor = no->dado;
        no = no->prox;
    }
}

// 11. Verifica se uma fila é igual outra
template<typename T>
bool filasIguaisF(Fila<T> *f1, Fila<T> *f2)
{
    NoFila<T> *no1 = f1->inicio;
    NoFila<T> *no2 = f2->inicio;
    
    while(no1 != nullptr && no2 != nullptr) {
        if(no1->dado != no2->dado) return false;
        no1 = no1->prox;
        no2 = no2->prox;
    }
    
    if(no1 == nullptr && no2 == nullptr) return true;
    
    return false;
}

// 12. Concatena 2 filas (Fila origem entra atrás da fila destino)
template<typename T>
void concatenaFilasF(Fila<T> *destino, Fila<T> *origem)
{
    while(!vaziaF(origem)) {
        enfileiraF(destino, desenfileiraF(origem));
    }
}

#endif // _HPP_FILA_DINAMICA_TEMPLATE