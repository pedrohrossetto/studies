/*
 * EXERCÍCIO 64 - GESTÃO AVANÇADA DE VETORES (SEM SEED / DETERMINÍSTICO)
 * * Requisitos:
 * 1. Qtd (6-24, par).
 * 2. Valores 20-500 (Multiplos de 4 ou 9, ou terminados em 5 ou 8). Sem repetição.
 * 3. Maior/Menor com endereços de memória.
 * 4. Média arredondada para cima (teto).
 * 5. Segundo vetor com valores menores que a média (Ordem Decrescente).
 */

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>    // Para ceil()
#include <iomanip>  // Para setprecision

using namespace std;

// ============================================================================
// 1. DEFINIÇÃO DO CONTEXTO
// ============================================================================
struct AppContext {
    // Vetor Principal
    int* vetor;
    int* tamanho;      // Definido pelo usuário (N)
    
    // Estatísticas
    int* pValorMenor;  // Ponteiro para o menor valor dentro do vetor
    int* pValorMaior;  // Ponteiro para o maior valor dentro do vetor
    int* mediaTeto;    // Média arredondada para cima
    
    // Vetor Secundário (Filtro)
    int* vetorMenores;
    int* tamMenores;
    
    // Flags de Estado
    bool* flagGerado;
    bool* flagCalcRealizado;
};

// ============================================================================
// 2. PROTOTIPOS
// ============================================================================

// Gestão de Memória
AppContext* inicializarContexto();
void destruirContexto(AppContext* ctx);

// Utilitários
void util_limparBuffer();
bool util_validarRegraNumero(int* valor);

// Interface e Controle
void exibirMenu();
void lerOpcao(char* ptrOpcao);
void pausarSistema();
void processarEscolha(char* ptrOpcao, bool* ptrRodando, AppContext* ctx);

// Tarefas
void tarefaConfigurarEGerar(AppContext* ctx);
void tarefaEstatisticas(AppContext* ctx);
void tarefaGerarVetorSecundario(AppContext* ctx);

// ============================================================================
// 3. MAIN
// ============================================================================
int main() {
    bool* ptrRodando = new bool(true);
    char* ptrOpcao   = new char(' ');
    
    AppContext* contexto = inicializarContexto();

    if (!contexto) {
        cout << "Erro fatal de memoria." << endl;
        return 1;
    }

    while (*ptrRodando) {
        system("cls"); // Limpa tela (Opcional)

        exibirMenu();
        lerOpcao(ptrOpcao);

        processarEscolha(ptrOpcao, ptrRodando, contexto);

        if (*ptrRodando) {
            pausarSistema();
        }
    }

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
    
    // Aloca escalares
    ctx->tamanho    = new int(0);
    ctx->mediaTeto  = new int(0);
    ctx->tamMenores = new int(0);
    
    // Ponteiros de arrays iniciam nulos
    ctx->vetor = NULL;
    ctx->vetorMenores = NULL;
    
    // Ponteiros de referencia (apontam para dentro do vetor)
    ctx->pValorMenor = NULL;
    ctx->pValorMaior = NULL;

    // Flags
    ctx->flagGerado = new bool(false);
    ctx->flagCalcRealizado = new bool(false);

    return ctx;
}

void destruirContexto(AppContext* ctx) {
    if (ctx != NULL) {
        if (ctx->vetor) delete[] ctx->vetor;
        if (ctx->vetorMenores) delete[] ctx->vetorMenores;
        
        delete ctx->tamanho;
        delete ctx->mediaTeto;
        delete ctx->tamMenores;
        delete ctx->flagGerado;
        delete ctx->flagCalcRealizado;
        // pValorMenor e pValorMaior não precisam de delete
        
        delete ctx;
    }
}

// ============================================================================
// 5. UTILITÁRIOS
// ============================================================================

void util_limparBuffer() {
    char* lixo = new char;
    while (cin.get(*lixo) && *lixo != '\n');
    delete lixo;
}

// Regra: Múltiplos de 4 ou 9 OU terminam em 5 ou 8
bool util_validarRegraNumero(int* valor) {
    if (*valor % 4 == 0) return true;
    if (*valor % 9 == 0) return true;
    if (*valor % 10 == 5) return true;
    if (*valor % 10 == 8) return true;
    return false;
}

// ============================================================================
// 6. INTERFACE
// ============================================================================

void exibirMenu() {
    cout << "==================================================" << endl;
    cout << "           EXERCICIO 64 - VETORES COMPLEXOS       " << endl;
    cout << "==================================================" << endl;
    cout << " [1] - Configurar e Gerar Vetor Principal" << endl;
    cout << " [2] - Mostrar Vetor, Extremos e Media" << endl;
    cout << " [3] - Gerar Vetor Secundario (Filtro + Sort)" << endl;
    cout << " [0] - Sair" << endl;
    cout << "==================================================" << endl;
}

void lerOpcao(char* ptrOpcao) {
    cout << "> Escolha: ";
    cin >> *ptrOpcao;
    util_limparBuffer();
}

void pausarSistema() {
    cout << "\n--------------------------------------------------" << endl;
    cout << "Pressione ENTER para continuar...";
    cin.get(); 
}

void processarEscolha(char* ptrOpcao, bool* ptrRodando, AppContext* ctx) {
    cout << "\n--------------------------------------------------\n";
    
    switch (*ptrOpcao) {
        case '1': 
            tarefaConfigurarEGerar(ctx); 
            break;

        case '2': 
            if (*ctx->flagGerado) tarefaEstatisticas(ctx);
            else cout << "[ERRO]: Gere o vetor primeiro (Opcao 1)." << endl;
            break;

        case '3': 
            if (*ctx->flagCalcRealizado) tarefaGerarVetorSecundario(ctx);
            else cout << "[ERRO]: Calcule as estatisticas primeiro (Opcao 2)." << endl;
            break;

        case '0': 
            cout << "Encerrando..." << endl;
            *ptrRodando = false; 
            break;

        default: 
            cout << "Opcao Invalida!" << endl;
    }
}

// ============================================================================
// 7. TAREFAS (LÓGICA DO EXERCÍCIO)
// ============================================================================

void tarefaConfigurarEGerar(AppContext* ctx) {
    // 1. Solicitar quantidade (Validação: Par, >=6, <=24)
    bool* entradaValida = new bool(false);
    
    do {
        cout << "Informe a quantidade de elementos (Par, 6 a 24): ";
        cin >> *ctx->tamanho;
        util_limparBuffer();

        if (*ctx->tamanho >= 6 && *ctx->tamanho <= 24 && *ctx->tamanho % 2 == 0) {
            *entradaValida = true;
        } else {
            cout << "[ERRO]: Valor invalido! Deve ser PAR e entre 6 e 24." << endl;
        }
    } while (!*entradaValida);

    delete entradaValida;

    // 2. Realocar vetor principal
    if (ctx->vetor != NULL) delete[] ctx->vetor;
    ctx->vetor = new int[*ctx->tamanho];

    // 3. Gerar valores
    cout << "-> Gerando valores aleatorios..." << endl;

    int* pInicio = ctx->vetor;
    int* pFim    = ctx->vetor + *ctx->tamanho;
    
    int* tempVal = new int(0);
    bool* valido = new bool(false);
    bool* unico  = new bool(false);

    for (int* pAtual = pInicio; pAtual < pFim; pAtual++) {
        do {
            *valido = false;
            *unico = true;

            // Gera entre 20 e 500 -> min + rand() % (max - min + 1)
            *tempVal = 20 + (rand() % (500 - 20 + 1));

            // Verifica regra matematica
            if (util_validarRegraNumero(tempVal)) {
                
                // Verifica duplicidade
                for (int* pCheck = pInicio; pCheck < pAtual; pCheck++) {
                    if (*pCheck == *tempVal) {
                        *unico = false;
                        break;
                    }
                }

                if (*unico) *valido = true;
            }

        } while (!*valido);

        *pAtual = *tempVal;
    }

    // Atualiza flags
    *ctx->flagGerado = true;
    *ctx->flagCalcRealizado = false; // Invalida calculos antigos

    cout << "-> Sucesso: Vetor preenchido com " << *ctx->tamanho << " elementos." << endl;

    delete tempVal;
    delete valido;
    delete unico;
}

void tarefaEstatisticas(AppContext* ctx) {
    // 1. Exibir Elementos
    cout << "Vetor Principal: ";
    int* p = ctx->vetor;
    int* fim = ctx->vetor + *ctx->tamanho;
    
    while (p < fim) {
        cout << *p;
        if (p < fim - 1) cout << ", ";
        p++;
    }
    cout << endl << endl;

    // 2. Encontrar Maior e Menor
    // Inicializa apontando para o primeiro elemento
    ctx->pValorMenor = ctx->vetor;
    ctx->pValorMaior = ctx->vetor;

    p = ctx->vetor + 1; // Começa do segundo
    while (p < fim) {
        if (*p < *ctx->pValorMenor) ctx->pValorMenor = p; // Salva o endereço
        if (*p > *ctx->pValorMaior) ctx->pValorMaior = p; // Salva o endereço
        p++;
    }
    // 3. Calcular Média (Arredondar para cima)
    int* soma = new int(*ctx->pValorMaior + *ctx->pValorMenor);
    *ctx->mediaTeto = (*soma + 1) / 2;  // Arredonda para cima sem ceil()
    delete soma;

    // 4. Exibir Resultados
    cout << "--- Estatisticas ---" << endl;
    
    cout << "Maior Elemento: " << *ctx->pValorMaior;
    cout << " (Endereco: " << ctx->pValorMaior << ")" << endl;

    cout << "Menor Elemento: " << *ctx->pValorMenor;
    cout << " (Endereco: " << ctx->pValorMenor << ")" << endl;

    cout << "Media dos Extremos (Teto): " << *ctx->mediaTeto << endl;

    *ctx->flagCalcRealizado = true;
}

void tarefaGerarVetorSecundario(AppContext* ctx) {
    cout << "-> Gerando Vetor Secundario (Menores que " << *ctx->mediaTeto << ")..." << endl;

    // 1. Contar quantos elementos atendem ao critério
    *ctx->tamMenores = 0;
    int* p = ctx->vetor;
    int* fim = ctx->vetor + *ctx->tamanho;

    while (p < fim) {
        if (*p < *ctx->mediaTeto) {
            (*ctx->tamMenores)++;
        }
        p++;
    }

    if (*ctx->tamMenores == 0) {
        cout << "[AVISO]: Nenhum valor e menor que a media." << endl;
        return;
    }

    // 2. Alocar Vetor Secundário
    if (ctx->vetorMenores != NULL) delete[] ctx->vetorMenores;
    ctx->vetorMenores = new int[*ctx->tamMenores];

    // 3. Preencher Vetor Secundário
    int* pDestino = ctx->vetorMenores;
    p = ctx->vetor;
    
    while (p < fim) {
        if (*p < *ctx->mediaTeto) {
            *pDestino = *p;
            pDestino++;
        }
        p++;
    }

    // 4. Ordenar Decrescente (Bubble Sort)
    int* i = new int;
    int* j = new int;
    int* temp = new int;
    int* tamSec = ctx->tamMenores;

    for (*i = 0; *i < *tamSec - 1; (*i)++) {
        for (*j = 0; *j < *tamSec - *i - 1; (*j)++) {
            
            int* atual   = ctx->vetorMenores + *j;
            int* proximo = ctx->vetorMenores + *j + 1;

            // Decrescente: Se atual < proximo, troca
            if (*atual < *proximo) {
                *temp    = *atual;
                *atual   = *proximo;
                *proximo = *temp;
            }
        }
    }
    delete i; delete j; delete temp;

    // 5. Exibir Vetor Secundário
    cout << "Vetor Secundario (Decrescente): [ ";
    p = ctx->vetorMenores;
    fim = ctx->vetorMenores + *ctx->tamMenores;

    while (p < fim) {
        cout << *p << " ";
        p++;
    }
    cout << "]" << endl;
}