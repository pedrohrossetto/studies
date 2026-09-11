/* * MODELO AVANÇADO: MENU DINÂMICO COM STRUCT (CONTEXTO)
 * Bibliotecas: <iostream>, <cstdio>, <cstdlib>, <fstream>, <cstring>, <cmath>, <iomanip>
 * * CONCEITO:
 * 1. Tudo é alocado no Heap (new/delete).
 * 2. Zero variáveis normais na stack para armazenamento de dados.
 * 3. Usamos uma Struct 'AppContext' para agrupar os ponteiros e limpar a passagem de parametros.
 */

#include <iostream>
#include <cstdio>
#include <cstdlib> // Para rand(), srand(), system()
#include <fstream>
#include <cstring>
#include <cmath>
#include <iomanip>

using namespace std;

// --- 1. DEFINIÇÃO DO CONTEXTO DE DADOS ---
// Essa estrutura serve apenas como um "envelope" para os ponteiros
struct AppContext {
    int* vetor;    // Ponteiro para o array dinâmico
    int* tamanho;  // Ponteiro para o tamanho do array
};

// --- PROTOTIPOS ---
void exibirMenu(const char* titulo); 
void lerOpcao(char* ptrOpcao);
void limparBuffer();
void pausarSistema();

// Controladora Principal (Recebe apenas o contexto)
void processarEscolha(char* ptrOpcao, bool* ptrRodando, AppContext* ctx);

// Tarefas Específicas (Recebem o contexto)
void tarefaGerarVetor(AppContext* ctx);
void tarefaMostrarVetor(AppContext* ctx);

int main() {
    // ---------------------------------------------------------
    // 1. INICIALIZAÇÃO DO SISTEMA (Tudo via Ponteiros/Heap)
    // ---------------------------------------------------------
    
    // Variáveis de Controle
    bool* p_rodando = new bool(true);
    char* p_opcao   = new char(' ');
    const char* tituloMenu = "SISTEMA DE VETORES (DINAMICO + STRUCT)";

    // ALOCACAO DO CONTEXTO (A "Caixa" de dados)
    AppContext* contexto = new AppContext;

    // Preenchemos a caixa com dados dinâmicos
    contexto->tamanho = new int(10);                 // Tamanho fixo inicial 10
    contexto->vetor   = new int[*contexto->tamanho]; // Aloca o vetor

    // Inicialização segura (Zerar memória)
    // Percorre usando aritmética de ponteiros: p < inicio + tamanho
    for (int* p = contexto->vetor; p < (contexto->vetor + *contexto->tamanho); p++) {
        *p = 0;
    }

    // ---------------------------------------------------------
    // 2. LOOP PRINCIPAL
    // ---------------------------------------------------------
    while (*p_rodando) {
        // system("cls"); // Opcional para Windows

        exibirMenu(tituloMenu);
        lerOpcao(p_opcao);

        // --- ELEGÂNCIA: Passamos apenas 3 ponteiros ---
        // Opcao, Controle de Loop e O Contexto de Dados
        processarEscolha(p_opcao, p_rodando, contexto);

        if (*p_rodando) {
            pausarSistema();
        }
    }

    // ---------------------------------------------------------
    // 3. GARBAGE COLLECTION (LIMPEZA)
    // ---------------------------------------------------------
    cout << "\n[SISTEMA]: Liberando memoria Heap..." << endl;

    // 1. Deleta o conteúdo de dentro da Struct
    delete[] contexto->vetor;
    delete contexto->tamanho;

    // 2. Deleta a própria Struct
    delete contexto;

    // 3. Deleta variáveis de controle
    delete p_rodando;
    delete p_opcao;

    return 0;
}

// --- IMPLEMENTAÇÃO DAS FUNÇÕES AUXILIARES ---

void exibirMenu(const char* titulo) {
    cout << "==================================================" << endl;
    cout << "          " << titulo << "          " << endl;
    cout << "==================================================" << endl;
    cout << " [1] - Gerar Vetor (Randomico sem Repeticao)" << endl;
    cout << " [2] - Mostrar Vetor Atual" << endl;
    cout << " [0] - Sair" << endl;
    cout << "==================================================" << endl;
}

void lerOpcao(char* ptrOpcao) {
    cout << "> Escolha: ";
    cin >> *ptrOpcao;
    
    // Limpeza ROBUSTA do Buffer:
    // Lê caracter por caracter até encontrar o Enter ('\n') e o consome.
    char lixo;
    while (cin.get(lixo) && lixo != '\n');
}

void limparBuffer() {
    while (cin.peek() != '\n' && cin.peek() != EOF) {
        cin.ignore();
    }
}

void pausarSistema() {
    cout << "\n--------------------------------------------------\n";
    cout << "Pressione ENTER para continuar...";
    cin.get();
}

// --- CONTROLADORA DE LÓGICA ---

void processarEscolha(char* ptrOpcao, bool* ptrRodando, AppContext* ctx) {
    cout << "\n--------------------------------------------------\n";

    switch (*ptrOpcao) {
        case '1':
            // Passamos o contexto para a tarefa específica
            tarefaGerarVetor(ctx);
            break;

        case '2':
            tarefaMostrarVetor(ctx);
            break;

        case '0':
            cout << "Encerrando execucao..." << endl;
            *ptrRodando = false; 
            break;

        default:
            cout << "Opcao invalida! Tente novamente." << endl;
            break;
    }
}

// --- IMPLEMENTAÇÃO DAS TAREFAS (LÓGICA PESADA) ---

void tarefaGerarVetor(AppContext* ctx) {
    cout << "-> Gerando valores aleatorios unicos (1 a 50)..." << endl;

    // Alocação temporária no Heap para lógica local
    int* min = new int(1);
    int* max = new int(50);

    // Alias (Apelidos) para facilitar a leitura, apontando para o Heap existente
    int* inicioVetor = ctx->vetor;
    int* fimVetor    = ctx->vetor + *ctx->tamanho;

    // Loop Principal (Percorre o vetor)
    for (int* pAtual = inicioVetor; pAtual < fimVetor; pAtual++) {
        
        bool* existe = new bool(false);
        int* gerado  = new int(0);

        do {
            *existe = false;
            // Lógica: *min + (rand() % (*max - *min + 1))
            *gerado = *min + (rand() % (*max - *min + 1));

            // Loop de Verificação (Percorre do inicio até o atual)
            for (int* pCheck = inicioVetor; pCheck < pAtual; pCheck++) {
                if (*pCheck == *gerado) {
                    *existe = true;
                    break;
                }
            }
        } while (*existe);

        // Atribuição final
        *pAtual = *gerado;

        // Limpeza das variáveis temporárias do loop
        delete existe;
        delete gerado;
    }

    cout << "-> Vetor preenchido com sucesso." << endl;

    // Limpeza das variáveis temporárias da função
    delete min;
    delete max;
}

void tarefaMostrarVetor(AppContext* ctx) {
    cout << "-> Conteudo do Vetor:" << endl;
    cout << "[ ";
    
    // Percorre usando os dados da struct
    int* inicio = ctx->vetor;
    int* fim    = ctx->vetor + *ctx->tamanho;

    for (int* p = inicio; p < fim; p++) {
        cout << *p << " ";
    }
    
    cout << "]" << endl;
}