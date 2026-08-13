/* * MODELO DE STRUCT REUTILIZÁVEL (100% HEAP / PONTEIROS)
 * Bibliotecas permitidas: <iostream>, <cstdio>, <cstdlib>, <fstream>, <cstring>, <cmath>, <iomanip>
 */

#include <iostream>
#include <cstdio>
#include <cstdlib> 
#include <cstring>
#include <cmath>
#include <iomanip>

using namespace std;

// ================================================================
// 1. DEFINIÇÃO DA STRUCT (O "CONTAINER" DE DADOS)
// ================================================================
// Adapte os tipos internos conforme o exercicio (int, float, char...)
struct ContextoDados {
    int* vetor;       // Ponteiro para o array de dados
    int* qtdAtual;    // Quantos elementos estao preenchidos
    int* capacidade;  // Tamanho total alocado na memoria
};

// ================================================================
// 2. FUNÇÕES DE GERENCIAMENTO DE MEMÓRIA (LIFECYCLE)
// ================================================================

/**
 * Inicializa a estrutura no Heap.
 * @param capInicial: Capacidade inicial do vetor (ex: 10)
 * @return Ponteiro para a struct alocada e configurada.
 */
ContextoDados* criarContexto(int capInicial) {
    // 1. Aloca a "caixa" (a struct)
    ContextoDados* ctx = new ContextoDados;

    // 2. Aloca e configura as variaveis internas
    ctx->capacidade = new int(capInicial);
    ctx->qtdAtual   = new int(0); // Comeca vazio
    
    // 3. Aloca o array dinamicamente
    ctx->vetor = new int[*ctx->capacidade];

    // 4. Limpa o vetor (Seguranca)
    for (int* p = ctx->vetor; p < ctx->vetor + *ctx->capacidade; p++) {
        *p = 0;
    }

    return ctx;
}

/**
 * Libera TODA a memoria utilizada pela struct.
 * Deve ser chamada antes de fechar o programa.
 */
void destruirContexto(ContextoDados* ctx) {
    if (ctx != NULL) {
        delete[] ctx->vetor;      // 1. Libera o array
        delete ctx->qtdAtual;     // 2. Libera contadores
        delete ctx->capacidade;
        delete ctx;               // 3. Libera a struct
        
        cout << "[MEMORIA]: Contexto liberado com sucesso." << endl;
    }
}

/**
 * (Opcional) Realoca o vetor para um novo tamanho sem perder dados.
 * Util para exercicios onde o tamanho do vetor nao é conhecido no inicio.
 */
void redimensionarContexto(ContextoDados* ctx, int novaCapacidade) {
    // 1. Aloca novo espaco
    int* novoVetor = new int[novaCapacidade];
    
    // 2. Copia os dados antigos (Aritmetica de ponteiros)
    int* pAntigo = ctx->vetor;
    int* pNovo   = novoVetor;
    int* fim     = ctx->vetor + *ctx->qtdAtual; // Copia apenas o que tem dados

    while (pAntigo < fim) {
        *pNovo = *pAntigo;
        pAntigo++;
        pNovo++;
    }

    // 3. Deleta o vetor antigo e atualiza os ponteiros da struct
    delete[] ctx->vetor;
    ctx->vetor = novoVetor;
    *ctx->capacidade = novaCapacidade;

    cout << "[SISTEMA]: Vetor redimensionado para " << novaCapacidade << endl;
}

// ================================================================
// 3. FUNÇÕES UTILITÁRIAS (EXEMPLOS DE USO)
// ================================================================

// Adiciona um valor ao final do vetor (Push Back manual)
void adicionarDado(ContextoDados* ctx, int valor) {
    // Verifica se precisa crescer
    if (*ctx->qtdAtual >= *ctx->capacidade) {
        // Dobra o tamanho se estiver cheio
        redimensionarContexto(ctx, *ctx->capacidade * 2);
    }

    // Aritmetica: vetor + deslocamento
    int* pDestino = ctx->vetor + *ctx->qtdAtual;
    *pDestino = valor;

    // Incrementa contador
    (*ctx->qtdAtual)++;
}

void imprimirContexto(ContextoDados* ctx) {
    cout << "Dados [" << *ctx->qtdAtual << "/" << *ctx->capacidade << "]: { ";
    
    int* p = ctx->vetor;
    int* fim = ctx->vetor + *ctx->qtdAtual;

    while (p < fim) {
        cout << *p << " ";
        p++;
    }
    cout << "}" << endl;
}

// ================================================================
// 4. EXEMPLO DE USO NO MAIN
// ================================================================

int main() {
    // --- CONFIGURACAO ---
    // Apenas 1 ponteiro principal no main
    ContextoDados* meuProblema = criarContexto(5); // Comeca com espaco para 5

    // --- USO ---
    cout << "--- Inserindo dados ---" << endl;
    adicionarDado(meuProblema, 10);
    adicionarDado(meuProblema, 20);
    adicionarDado(meuProblema, 30);
    imprimirContexto(meuProblema);

    cout << "--- Estourando a capacidade inicial (Trigger Realocacao) ---" << endl;
    adicionarDado(meuProblema, 40);
    adicionarDado(meuProblema, 50);
    adicionarDado(meuProblema, 60); // Aqui ele dobra de 5 para 10 automaticamente
    imprimirContexto(meuProblema);

    // --- LIMPEZA ---
    destruirContexto(meuProblema);

    return 0;
}