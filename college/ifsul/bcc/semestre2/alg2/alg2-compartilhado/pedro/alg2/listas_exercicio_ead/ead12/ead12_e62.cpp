/* * SISTEMA DE VETORES COM CONTROLE DE FLUXO E ESTADOS
 * Requisito: Opcoes dependentes umas das outras.
 * Bibliotecas permitidas: <iostream>, <cstdio>, <cstdlib>, <fstream>, <cstring>, <cmath>, <iomanip>
 */

#include <iostream>
#include <cstdio>
#include <cstdlib> 
#include <cstring>
#include <cmath>
#include <iomanip>

using namespace std;

// ============================================================================
// 1. DEFINIÇÃO DO CONTEXTO
// ============================================================================
struct AppContext {
    // Dados
    int* vetor;
    int* sobra;
    int* tamanho;    
    int* capacidade;
    int* qtdSobra;
    int* rangeMin;
    int* rangeMax;

    // --- NOVOS CONTROLES DE ESTADO (FLAGS) ---
    bool* flagVetorGerado;   // Indica se Opcao 1 ja rodou
    bool* flagBuscaRealizada; // Indica se Opcao 2 ja rodou
};

// ============================================================================
// 2. PROTOTIPOS
// ============================================================================
AppContext* inicializarContexto(int capInicial, int min, int max);
void destruirContexto(AppContext* ctx);
void limparSobra(AppContext* ctx);

void exibirMenu(const char* titulo);
void lerOpcao(char* ptrOpcao);
void pausarSistema();

void processarEscolha(char* ptrOpcao, bool* ptrRodando, AppContext* ctx);
void tarefaGerarVetorUnico(AppContext* ctx);
void tarefaLocalizarValor(AppContext* ctx);
void tarefaMostrarVetor(AppContext* ctx);
void tarefaMostrarSobra(AppContext* ctx);

// ============================================================================
// 3. MAIN
// ============================================================================
int main() {
    bool* ptrRodando = new bool(true);
    char* ptrOpcao   = new char(' ');
    
    // Inicializa contexto (Tamanho 10, Random 1-50)
    AppContext* contexto = inicializarContexto(10, 1, 50);

    const char* titulo = "SISTEMA DE VETORES (COM TRAVAS)";

    while (*ptrRodando) {
        system("cls"); // Windows

        exibirMenu(titulo);
        lerOpcao(ptrOpcao);

        processarEscolha(ptrOpcao, ptrRodando, contexto);

        if (*ptrRodando) {
            pausarSistema();
        }
    }

    cout << "\n[SISTEMA]: Encerrando..." << endl;
    destruirContexto(contexto); 
    delete ptrRodando;          
    delete ptrOpcao;

    return 0;
}

// ============================================================================
// 4. GESTÃO DE MEMÓRIA E ESTADOS
// ============================================================================

AppContext* inicializarContexto(int capInicial, int min, int max) {
    AppContext* ctx = new AppContext;
    
    // Alocação de Dados
    ctx->tamanho    = new int(capInicial);
    ctx->capacidade = new int(capInicial);
    ctx->rangeMin   = new int(min);
    ctx->rangeMax   = new int(max);
    ctx->qtdSobra   = new int(0);

    // Alocação dos Vetores
    ctx->vetor = new int[*ctx->capacidade];
    ctx->sobra = new int[*ctx->capacidade];

    // Inicializa com zeros
    for (int* p = ctx->vetor; p < (ctx->vetor + *ctx->capacidade); p++) *p = 0;
    for (int* p = ctx->sobra; p < (ctx->sobra + *ctx->capacidade); p++) *p = 0;

    // --- INICIALIZAÇÃO DAS FLAGS ---
    ctx->flagVetorGerado    = new bool(false); // Nada feito ainda
    ctx->flagBuscaRealizada = new bool(false);

    return ctx;
}

void destruirContexto(AppContext* ctx) {
    if (ctx != NULL) {
        delete[] ctx->vetor;
        delete[] ctx->sobra;
        delete ctx->qtdSobra;
        delete ctx->tamanho;
        delete ctx->capacidade;
        delete ctx->rangeMin;
        delete ctx->rangeMax;
        // Limpa flags
        delete ctx->flagVetorGerado;
        delete ctx->flagBuscaRealizada;
        delete ctx;
    }
}

void limparSobra(AppContext* ctx) {
    *ctx->qtdSobra = 0;
}

// ============================================================================
// 5. INTERFACE
// ============================================================================

void exibirMenu(const char* titulo) {
    cout << "==================================================" << endl;
    cout << "          " << titulo << "          " << endl;
    cout << "==================================================" << endl;
    cout << " [1] - Gerar Vetor (Obrigatorio inicial)" << endl;
    cout << " [2] - Localizar Valor" << endl;
    cout << " [3] - Mostrar Vetor Principal" << endl;
    cout << " [4] - Mostrar Vetor Sobra" << endl;
    cout << " [0] - Sair" << endl;
    cout << "==================================================" << endl;
}

void lerOpcao(char* ptrOpcao) {
    cout << "> Escolha: ";
    cin >> *ptrOpcao;
    char lixo;
    while (cin.get(lixo) && lixo != '\n'); 
}

void pausarSistema() {
    cout << "\n--------------------------------------------------" << endl;
    cout << "Pressione ENTER para continuar...";
    cin.get(); 
}

// ============================================================================
// 6. CONTROLE DE FLUXO (AQUI ESTÁ A LÓGICA DAS TRAVAS)
// ============================================================================

void processarEscolha(char* ptrOpcao, bool* ptrRodando, AppContext* ctx) {
    cout << "\n--------------------------------------------------\n";
    
    switch (*ptrOpcao) {
        case '1': 
            tarefaGerarVetorUnico(ctx); 
            break;

        case '2': 
            // TRAVA: Só executa se Opção 1 já foi rodada
            if (*ctx->flagVetorGerado == true) {
                tarefaLocalizarValor(ctx);
            } else {
                cout << "[ERRO]: Voce precisa gerar o vetor (Opcao 1) antes de pesquisar." << endl;
            }
            break;

        case '3': 
            // TRAVA: Só executa se Opção 1 já foi rodada
            if (*ctx->flagVetorGerado == true) {
                tarefaMostrarVetor(ctx);
            } else {
                cout << "[ERRO]: O vetor esta vazio. Execute a Opcao 1 primeiro." << endl;
            }
            break;

        case '4': 
            // TRAVA: Só executa se Opção 2 já foi rodada pelo menos uma vez
            if (*ctx->flagBuscaRealizada == true) {
                tarefaMostrarSobra(ctx);
            } else {
                cout << "[ERRO]: Voce precisa realizar pelo menos uma busca (Opcao 2) antes." << endl;
            }
            break;

        case '0': 
            cout << "Saindo..." << endl;
            *ptrRodando = false; 
            break;

        default: 
            // Requisito: Mensagem explicita ao escolher opcao inválida
            cout << "[AVISO]: Opcao Invalida! Escolha um numero do menu." << endl;
    }
}

// ============================================================================
// 7. TAREFAS
// ============================================================================

void tarefaGerarVetorUnico(AppContext* ctx) {
    cout << "-> Gerando valores..." << endl;
    int* pInicio = ctx->vetor;
    int* pFim    = ctx->vetor + *ctx->tamanho;
    
    int* gerado = new int(0);
    bool* existe = new bool(false);

    for (int* pAtual = pInicio; pAtual < pFim; pAtual++) {
        do {
            *existe = false;
            *gerado = *ctx->rangeMin + (rand() % (*ctx->rangeMax - *ctx->rangeMin + 1));
            for (int* pCheck = pInicio; pCheck < pAtual; pCheck++) {
                if (*pCheck == *gerado) {
                    *existe = true; break;
                }
            }
        } while (*existe);
        *pAtual = *gerado;
    }
    
    // Reset lógico ao gerar novo vetor
    limparSobra(ctx); 
    
    // --- ATUALIZAÇÃO DE ESTADOS ---
    *ctx->flagVetorGerado = true;      // Libera opções 2 e 3
    *ctx->flagBuscaRealizada = false;  // Bloqueia opção 4 (pois é um novo vetor, nova busca necessária)
    
    cout << "-> Sucesso: Vetor preenchido." << endl;
    delete gerado; delete existe;
}

void tarefaLocalizarValor(AppContext* ctx) {
    cout << "Digite o valor para pesquisar: ";
    int* valorBusca = new int(0);
    cin >> *valorBusca;
    char lixo; while (cin.get(lixo) && lixo != '\n');

    bool* encontrado = new bool(false);
    int* p = ctx->vetor;
    int* fim = ctx->vetor + *ctx->tamanho;

    while (p < fim) {
        if (*p == *valorBusca) {
            *encontrado = true;
            cout << "\nValor " << *valorBusca << ", pertence ao vetor." << endl;
            cout << "Endereco: " << p << endl; 
            break;
        }
        p++;
    }

    if (!*encontrado) {
        cout << "\nNao pertence ao vetor." << endl;
        
        if (*ctx->qtdSobra >= *ctx->capacidade) {
            limparSobra(ctx);
        }

        int* pDestino = ctx->sobra + *ctx->qtdSobra;
        *pDestino = *valorBusca;
        (*ctx->qtdSobra)++;

        cout << "Valor inserido no vetor 'sobra'." << endl;
        tarefaMostrarSobra(ctx);
    }

    // --- ATUALIZAÇÃO DE ESTADOS ---
    *ctx->flagBuscaRealizada = true; // Libera opção 4

    delete valorBusca;
    delete encontrado;
}

void tarefaMostrarVetor(AppContext* ctx) {
    cout << "Vetor Principal: [ ";
    int* p = ctx->vetor;
    int* fim = ctx->vetor + *ctx->tamanho;
    while (p < fim) {
        cout << *p << " ";
        p++;
    }
    cout << "]" << endl;
}

void tarefaMostrarSobra(AppContext* ctx) {
    cout << "Vetor Sobra (" << *ctx->qtdSobra << " itens): [ ";
    
    int* p = ctx->sobra;
    int* fim = ctx->sobra + *ctx->qtdSobra; 

    if (*ctx->qtdSobra == 0) {
        cout << "vazio ";
    } else {
        while (p < fim) {
            cout << *p << " ";
            p++;
        }
    }
    cout << "]" << endl;
}