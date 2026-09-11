/*
 * CÓDIGO ADAPTADO AO MODELO DE MENU/CONTEXTO DINÂMICO
 * Bibliotecas permitidas: <iostream>, <cstdio>, <cstdlib>, <fstream>, <cstring>, <cmath>, <iomanip>
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

// ============================================================================
// 1. DEFINIÇÃO DO CONTEXTO (STRUCT)
// ============================================================================
struct AppContext {
    // Dados Principais
    int* vetor;
    int* tamanho;
    int* maxRand;

    // Flags de Estado (Controle de Fluxo)
    bool* flagGerado;
    bool* flagOrdenado;
};

// ============================================================================
// 2. PROTOTIPOS
// ============================================================================

// Gestão
AppContext* inicializarContexto();
void destruirContexto(AppContext* ctx);

// Interface
void exibirMenu();
void lerOpcao(char* ptrOpcao);
void pausarSistema();

// Lógica de Controle
void processarEscolha(char* ptrOpcao, bool* ptrRodando, AppContext* ctx);

// Tarefas (Sua lógica original adaptada)
void tarefaGerarValores(AppContext* ctx);
void tarefaOrdenarVetor(AppContext* ctx);
void tarefaSalvarArquivo(AppContext* ctx);
void tarefaMostrarTela(AppContext* ctx); // Extra: Para visualizar no console

// ============================================================================
// 3. MAIN
// ============================================================================
int main() {
    // Variáveis de controle no Heap
    bool* ptrRodando = new bool(true);
    char* ptrOpcao   = new char(' ');

    // Inicializa o contexto
    AppContext* contexto = inicializarContexto();

    while (*ptrRodando) {
        // system("cls"); // Opcional

        exibirMenu();
        lerOpcao(ptrOpcao);

        processarEscolha(ptrOpcao, ptrRodando, contexto);

        if (*ptrRodando) {
            pausarSistema();
        }
    }

    // Limpeza final
    std::cout << "\n[SISTEMA]: Encerrando e liberando memoria..." << std::endl;
    destruirContexto(contexto);
    delete ptrRodando;
    delete ptrOpcao;

    return 0;
}

// ============================================================================
// 4. IMPLEMENTAÇÃO - GESTÃO DE MEMÓRIA
// ============================================================================

AppContext* inicializarContexto() {
    AppContext* ctx = new AppContext;

    // Alocação dos valores de configuração
    ctx->tamanho = new int(20);
    ctx->maxRand = new int(101); // 0 a 100
    
    // Alocação do Vetor
    ctx->vetor = new int[*ctx->tamanho];

    // Inicialização segura (zeros)
    for (int* p = ctx->vetor; p < ctx->vetor + *ctx->tamanho; p++) {
        *p = 0;
    }

    // Inicialização das Flags
    ctx->flagGerado = new bool(false);
    ctx->flagOrdenado = new bool(false);

    return ctx;
}

void destruirContexto(AppContext* ctx) {
    if (ctx != NULL) {
        delete[] ctx->vetor;
        delete ctx->tamanho;
        delete ctx->maxRand;
        delete ctx->flagGerado;
        delete ctx->flagOrdenado;
        delete ctx;
    }
}

// ============================================================================
// 5. IMPLEMENTAÇÃO - INTERFACE
// ============================================================================

void exibirMenu() {
    std::cout << "==================================================" << std::endl;
    std::cout << "          SISTEMA DE ORDENACAO E ARQUIVO          " << std::endl;
    std::cout << "==================================================" << std::endl;
    std::cout << " [1] - Gerar Valores (0-100, Unicos)" << std::endl;
    std::cout << " [2] - Ordenar Vetor (Bubble Sort)" << std::endl;
    std::cout << " [3] - Salvar em Arquivo (exer_61.txt)" << std::endl;
    std::cout << " [4] - Mostrar na Tela (Visualizar)" << std::endl;
    std::cout << " [0] - Sair" << std::endl;
    std::cout << "==================================================" << std::endl;
}

void lerOpcao(char* ptrOpcao) {
    std::cout << "> Escolha: ";
    std::cin >> *ptrOpcao;
    char lixo;
    while (std::cin.get(lixo) && lixo != '\n'); // Limpeza de buffer
}

void pausarSistema() {
    std::cout << "\n--------------------------------------------------" << std::endl;
    std::cout << "Pressione ENTER para continuar...";
    std::cin.get();
}

void processarEscolha(char* ptrOpcao, bool* ptrRodando, AppContext* ctx) {
    std::cout << "\n--------------------------------------------------\n";

    switch (*ptrOpcao) {
        case '1':
            tarefaGerarValores(ctx);
            break;

        case '2':
            // Só ordena se já gerou
            if (*ctx->flagGerado) {
                tarefaOrdenarVetor(ctx);
            } else {
                std::cout << "[ERRO]: Gere o vetor (Opcao 1) primeiro." << std::endl;
            }
            break;

        case '3':
            // Só salva se tiver dados
            if (*ctx->flagGerado) {
                tarefaSalvarArquivo(ctx);
            } else {
                std::cout << "[ERRO]: O vetor esta vazio." << std::endl;
            }
            break;
        
        case '4':
            if (*ctx->flagGerado) {
                tarefaMostrarTela(ctx);
            } else {
                std::cout << "[ERRO]: O vetor esta vazio." << std::endl;
            }
            break;

        case '0':
            *ptrRodando = false;
            break;

        default:
            std::cout << "Opcao Invalida!" << std::endl;
    }
}

// ============================================================================
// 6. IMPLEMENTAÇÃO - TAREFAS (SUA LÓGICA ORIGINAL)
// ============================================================================

void tarefaGerarValores(AppContext* ctx) {
    std::cout << "-> Gerando 20 valores unicos..." << std::endl;

    // Variaveis temporárias no Heap (Exigencia do exercicio)
    int* i = new int;
    int* j = new int;
    int* temp = new int;
    bool* duplicado = new bool;

    // Ponteiros auxiliares para clareza
    int* V = ctx->vetor;
    int* size = ctx->tamanho;
    int* maxRand = ctx->maxRand;

    // Loop principal
    for (*i = 0; *i < *size; (*i)++) {
        do {
            *duplicado = false;
            *temp = rand() % *maxRand; 

            for (*j = 0; *j < *i; (*j)++) {
                if (*(V + *j) == *temp) {
                    *duplicado = true;
                    break;
                }
            }
        } while (*duplicado);

        *(V + *i) = *temp;
    }

    // Atualiza Flags
    *ctx->flagGerado = true;
    *ctx->flagOrdenado = false; // Se gerou novos, perdeu a ordenação antiga

    std::cout << "-> Vetor gerado com sucesso." << std::endl;

    // Libera temp
    delete i; delete j; delete temp; delete duplicado;
}

void tarefaOrdenarVetor(AppContext* ctx) {
    std::cout << "-> Ordenando (Bubble Sort)..." << std::endl;

    int* i = new int;
    int* j = new int;
    int* temp = new int;

    int* V = ctx->vetor;
    int* size = ctx->tamanho;

    for (*i = 0; *i < *size - 1; (*i)++) {
        for (*j = 0; *j < *size - *i - 1; (*j)++) {
            if (*(V + *j) > *(V + *j + 1)) {
                // Swap
                *temp = *(V + *j);
                *(V + *j) = *(V + *j + 1);
                *(V + *j + 1) = *temp;
            }
        }
    }

    *ctx->flagOrdenado = true;
    std::cout << "-> Vetor ordenado." << std::endl;

    delete i; delete j; delete temp;
}

void tarefaSalvarArquivo(AppContext* ctx) {
    std::cout << "-> Salvando em disco..." << std::endl;

    // Ponteiro para ofstream alocado dinamicamente
    std::ofstream* saida = new std::ofstream("exer_61.txt");

    if (saida->is_open()) {
        int* i = new int;
        int* V = ctx->vetor;
        int* size = ctx->tamanho;

        for (*i = 0; *i < *size; (*i)++) {
            // Mantida a lógica original: Endereço - Valor
            *saida << (void*)(V + *i) << " - " << *(V + *i) << "\n";
        }

        saida->close();
        std::cout << "-> Arquivo 'exer_61.txt' gerado com sucesso." << std::endl;
        delete i;
    } else {
        std::cout << "-> Erro ao abrir arquivo." << std::endl;
    }

    delete saida; // Destroi o objeto ofstream
}

void tarefaMostrarTela(AppContext* ctx) {
    std::cout << "Vetor: [ ";
    int* p = ctx->vetor;
    int* fim = ctx->vetor + *ctx->tamanho;
    while(p < fim) {
        std::cout << *p << " ";
        p++;
    }
    std::cout << "]" << std::endl;
}