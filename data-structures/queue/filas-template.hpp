#ifndef _HPP_FILA_TEMPLATE
#define _HPP_FILA_TEMPLATE

#include <iostream>

/**
 * @brief Estrutura de Fila Genérica (Template)
 * @tparam T Tipo de dado a ser armazenado na fila
 */
template <typename T>
struct Fila {
    int tam;    // Tamanho do vetor de dados
    int total;  // Total de elementos armazenados
    int inicio; // Índice do primeiro elemento
    int fim;    // Índice para o próximo elemento (fim da fila)
    T *dados;   // Ponteiro para o vetor genérico

    Fila() {
        tam = 0;
        total = 0;
        inicio = 0;
        fim = 0;
        dados = nullptr;
    }
};

// --- Funções Template ---

template <typename T>
void inicializaF(Fila<T> *f, int tam) {
    f->tam = tam;
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
    f->dados = new T[tam]; // Alocação dinâmica do tipo T
}

template <typename T>
bool verificaInicializacaoF(Fila<T> *f) {
    return (f->dados != nullptr);
}

template <typename T>
void destroiF(Fila<T> *f) {
    if (verificaInicializacaoF(f)) {
        delete[] (f->dados);
        f->dados = nullptr;
    }
    f->fim = 0;
    f->inicio = 0;
    f->total = 0;
    f->tam = 0;
}

template <typename T>
bool vaziaF(Fila<T> *f) {
    return (f->total == 0);
}

template <typename T>
bool cheiaF(Fila<T> *f) {
    return (f->total == f->tam);
}

template <typename T>
bool enfileiraF(Fila<T> *f, T valor) {
    if (!verificaInicializacaoF(f) || cheiaF(f))
        return false;

    f->dados[f->fim] = valor;
    f->total++;
    f->fim++;

    if (f->fim >= f->tam)
        f->fim = 0; // Lógica circular

    return true;
}

template <typename T>
T desenfileiraF(Fila<T> *f) {
    if (vaziaF(f)) 
        return T(); // Retorna o construtor padrão do tipo T

    T valor = f->dados[f->inicio];
    f->total--;
    f->inicio++;

    if (f->inicio >= f->tam)
        f->inicio = 0; // Lógica circular

    return valor;
}

template <typename T>
T espiaF(Fila<T> *f) {
    if (vaziaF(f))
        return T();

    return f->dados[f->inicio];
}


#endif // _HPP_FILA_TEMPLATE