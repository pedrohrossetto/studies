#include <iostream>

// Adapte a struct conforme o enunciado da prova
struct AppContext {
    int* vetor;
    int* tamanho;
    int* capacidade;
};

/**
 * @brief Inicializa o contexto e aloca memória.
 */
AppContext* ctx_inicializar(int tamInicial) {
    AppContext* ctx = new AppContext;
    
    ctx->tamanho    = new int(tamInicial);
    ctx->capacidade = new int(tamInicial);
    ctx->vetor      = new int[*ctx->capacidade];

    // Inicializa com zeros (segurança)
    for (int* p = ctx->vetor; p < ctx->vetor + *ctx->capacidade; p++) {
        *p = 0;
    }

    return ctx;
}

/**
 * @brief Libera toda a memória alocada.
 */
void ctx_destruir(AppContext* ctx) {
    if (ctx != NULL) {
        delete[] ctx->vetor; // Array usa delete[]
        delete ctx->tamanho;
        delete ctx->capacidade;
        delete ctx;          // Struct usa delete simples
    }
}