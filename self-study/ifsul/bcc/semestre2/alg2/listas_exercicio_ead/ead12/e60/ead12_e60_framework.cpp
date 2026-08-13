/*
 * ADAPTAÇÃO: CONTROLE DE INGRESSOS (CORRIGIDO E VALIDADO)
 * Correções: Uso correto de delete[] no tratamento de erro e retorno de status.
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <cstdlib>

using namespace std;

// ============================================================================
// 1. DEFINIÇÃO DO CONTEXTO
// ============================================================================
struct AppContext {
    int* v1;
    int* n_v1;       
    long long* s_v1; 

    int* v2;
    int* n_v2;
    long long* s_v2;

    int* capacidade; 
};

// ============================================================================
// 2. PROTOTIPOS
// ============================================================================
AppContext* inicializarContexto();
void destruirContexto(AppContext* ctx);

// Alterado para retornar bool (Sucesso/Falha)
bool executarProcessamento(AppContext* ctx);

// ============================================================================
// 3. MAIN
// ============================================================================
int main() {
    system("cls"); // Limpa tela (Windows)

    bool* sucessoGeral = new bool(false);
    AppContext* contexto = inicializarContexto();

    if (contexto != NULL) {
        cout << "[SISTEMA]: Iniciando processamento de arquivos..." << endl;
        
        // Agora capturamos se o processamento funcionou
        *sucessoGeral = executarProcessamento(contexto);
    } else {
        cout << "[ERRO]: Falha fatal na alocacao de memoria do contexto." << endl;
    }

    if (*sucessoGeral) {
        cout << "[SISTEMA]: Processamento concluido com sucesso." << endl;
        cout << "           Verifique 'arquivo_saida_e60.txt'." << endl;
    } else {
        cout << "[SISTEMA]: O programa foi encerrado devido a erros." << endl;
    }

    destruirContexto(contexto);
    delete sucessoGeral;

    return 0;
}

// ============================================================================
// 4. GESTÃO DE MEMÓRIA
// ============================================================================

AppContext* inicializarContexto() {
    AppContext* ctx = new AppContext;

    // Alocação segura: new(std::nothrow) poderia ser usado, mas padrão lança exceção
    ctx->capacidade = new int(100);
    ctx->n_v1       = new int(0);
    ctx->n_v2       = new int(0);
    ctx->s_v1       = new long long(0);
    ctx->s_v2       = new long long(0);

    ctx->v1 = new int[*ctx->capacidade];
    ctx->v2 = new int[*ctx->capacidade];

    if (!ctx->v1 || !ctx->v2) return NULL;

    return ctx;
}

void destruirContexto(AppContext* ctx) {
    if (ctx != NULL) {
        delete[] ctx->v1;
        delete[] ctx->v2;
        delete ctx->n_v1;
        delete ctx->n_v2;
        delete ctx->s_v1;
        delete ctx->s_v2;
        delete ctx->capacidade;
        delete ctx;
    }
}

// ============================================================================
// 5. LÓGICA DE NEGÓCIO
// ============================================================================

bool executarProcessamento(AppContext* ctx) {
    // Alocação de Arrays Dinâmicos
    char* operador   = new char[20];
    char* vetor_nome = new char[10];
    char* formato    = new char[10];
    
    int* valorTemp   = new int(0);
    bool* status     = new bool(true); // Assume sucesso

    ifstream* entrada = new ifstream("arquivo_entrada_e60.txt");
    ofstream* saida   = new ofstream("arquivo_saida_e60.txt");

    // --- VERIFICAÇÃO DE ERRO CORRIGIDA ---
    if (!(*entrada) || !(*saida)) {
        cout << "[ERRO]: Nao foi possivel abrir os arquivos de entrada/saida." << endl;
        
        // CORREÇÃO CRÍTICA: Usando delete[] para arrays
        delete[] operador; 
        delete[] vetor_nome; 
        delete[] formato; 
        
        delete valorTemp;
        delete entrada; 
        delete saida;
        delete status;
        
        return false; // Retorna falha para o main
    }

    // Loop de Leitura
    while (*entrada >> operador) {
        
        if (strcmp(operador, "adiciona") == 0) {
            *entrada >> vetor_nome >> *valorTemp;

            if (strcmp(vetor_nome, "V1") == 0) {
                if (*ctx->n_v1 < *ctx->capacidade) {
                    *(ctx->v1 + *ctx->n_v1) = *valorTemp;
                    *ctx->s_v1 += *valorTemp;
                    (*ctx->n_v1)++;
                }
            } 
            else if (strcmp(vetor_nome, "V2") == 0) {
                if (*ctx->n_v2 < *ctx->capacidade) {
                    *(ctx->v2 + *ctx->n_v2) = *valorTemp;
                    *ctx->s_v2 += *valorTemp;
                    (*ctx->n_v2)++;
                }
            }
            *saida << "O numero " << *valorTemp << " foi adicionado no vetor " << vetor_nome << "\n";
        }

        else if (strcmp(operador, "mostra") == 0) {
            *entrada >> vetor_nome >> formato;
            *saida << vetor_nome << "(" << formato << "): ";

            int* pInicio = NULL;
            int* pFim    = NULL;

            if (strcmp(vetor_nome, "V1") == 0) {
                pInicio = ctx->v1;
                pFim    = ctx->v1 + *ctx->n_v1;
            } 
            else if (strcmp(vetor_nome, "V2") == 0) {
                pInicio = ctx->v2;
                pFim    = ctx->v2 + *ctx->n_v2;
            }

            if (pInicio != NULL) {
                for (int* p = pInicio; p < pFim; p++) {
                    *saida << *p;
                    if (p < pFim - 1) {
                        *saida << ", ";
                    }
                }
            }
            *saida << "\n";
        }

        else if (strcmp(operador, "qtd") == 0) {
            *entrada >> vetor_nome;
            if (strcmp(vetor_nome, "V1") == 0) {
                *saida << "Total de elementos no vetor V1: " << *ctx->n_v1 << "\n";
            } 
            else if (strcmp(vetor_nome, "V2") == 0) {
                *saida << "Total de elementos no vetor V2: " << *ctx->n_v2 << "\n";
            }
        }

        else if (strcmp(operador, "media") == 0) {
            *entrada >> vetor_nome;
            float* mediaCalc = new float(0.0);

            if (strcmp(vetor_nome, "V1") == 0) {
                *saida << "Media dos elementos do vetor V1: ";
                if (*ctx->n_v1 > 0) {
                    *mediaCalc = (float)(*ctx->s_v1) / (*ctx->n_v1);
                    *saida << fixed << setprecision(1) << *mediaCalc << "\n";
                } else {
                    *saida << "0.0\n";
                }
            } 
            else if (strcmp(vetor_nome, "V2") == 0) {
                *saida << "Media dos elementos do vetor V2: ";
                if (*ctx->n_v2 > 0) {
                    *mediaCalc = (float)(*ctx->s_v2) / (*ctx->n_v2);
                    *saida << fixed << setprecision(1) << *mediaCalc << "\n";
                } else {
                    *saida << "0.0\n";
                }
            }
            delete mediaCalc;
        }
    }

    entrada->close();
    saida->close();

    delete entrada;
    delete saida;
    delete[] operador;
    delete[] vetor_nome;
    delete[] formato;
    delete valorTemp;
    
    bool resultadoFinal = *status;
    delete status;
    
    return resultadoFinal;
}