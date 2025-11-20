/* * MODELO AVAN�ADO: MENU DIN�MICO COM STRUCT (CONTEXTO)
 * Bibliotecas: <iostream>, <cstdio>, <cstdlib>, <fstream>, <cstring>, <cmath>, <iomanip>
 * * CONCEITO:
 * 1. Tudo � alocado no Heap (new/delete).
 * 2. Zero vari�veis normais na stack para armazenamento de dados.
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

// --- 1. DEFINI��O DO CONTEXTO DE DADOS ---
// Essa estrutura serve apenas como um "envelope" para os ponteiros
struct AppContext {
    int* vetor_musica;    // Ponteiro para o array din�mico
    int* tamanho;  // Ponteiro para o tamanho do array
    int* cod_musica;
    char* nome_musica;
    float* tempo;
    int* vetor_playlist; // ponteiro com id da musica
    int* tamanho_playlist; // Ponteiro para o tamanho da array de playlists deseja pelo usuario
};

// --- PROTOTIPOS ---
void exibirMenu(const char* titulo);
void lerOpcao(char* ptrOpcao);
void limparBuffer();
void pausarSistema();

// Controladora Principal (Recebe apenas o contexto)
void processarEscolha(char* ptrOpcao, bool* ptrRodando, AppContext* ctx);

// Tarefas Espec�ficas (Recebem o contexto)
void tarefaLerArquivoMusic(AppContext* ctx);
void tarefaMostrarvetor_musica(AppContext* ctx);

int main() {
    // ---------------------------------------------------------
    // 1. INICIALIZA��O DO SISTEMA (Tudo via Ponteiros/Heap)
    // ---------------------------------------------------------

    // Vari�veis de Controle
    bool* p_rodando = new bool(true);
    char* p_opcao   = new char(' ');
    const char* tituloMenu = "QUEST�O 1 - A PLAYLIST DE PEDRO MARIO";
    // ALOCACAO DO CONTEXTO (A "Caixa" de dados)
    AppContext* contexto = new AppContext;

    // Preenchemos a caixa com dados din�micos
    //int* tamanho_alias_musicas;
    //int* tamanho_alias_playlist;

    /* cout << "Informe o tamanho da sua lista de músicas: " << endl;

    cin >> *tamanho_alias_musicas;
    contexto->tamanho = tamanho_alias_musicas;
    cout << tamanho_alias_musicas;
    cout << contexto->tamanho;
    */

    contexto->vetor_musica   = new int[*contexto->tamanho]; // Aloca o vetor_musica

    //Inicializa��o segura (Zerar mem�ria)
    // Percorre usando aritm�tica de ponteiros: p < inicio + tamanho
    //for (int* p = contexto->vetor_musica; p < (contexto->vetor_musica + *contexto->tamanho); p++) {
    //  *p = 0;
    //}

    // ---------------------------------------------------------
    // 2. LOOP PRINCIPAL
    // ---------------------------------------------------------
    while (*p_rodando) {
        system("cls"); // Opcional para Windows

        exibirMenu(tituloMenu);
        lerOpcao(p_opcao);

        // --- ELEG�NCIA: Passamos apenas 3 ponteiros ---
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

    // 1. Deleta o conte�do de dentro da Struct
    delete[] contexto->vetor_musica;
    delete contexto->tamanho;

    // 2. Deleta a pr�pria Struct
    delete contexto;

    // 3. Deleta vari�veis de controle
    delete p_rodando;
    delete p_opcao;

    return 0;
}

// --- IMPLEMENTA��O DAS FUN��ES AUXILIARES ---

void exibirMenu(const char* titulo) {
    cout << "==================================================" << endl;
    cout << "          " << titulo << "          " << endl;
    cout << "==================================================" << endl;
    cout << " [1] - Ler Arquivo Music.txt" << endl;
    cout << " [2] - Selecionar Musicas" << endl;
    cout << " [3] - Exibir Musicas Selecionadas" << endl;
    cout << " [4] - Gerar Arquivo Texto com a Playlist" << endl;
    cout << " [0] - Sair" << endl;
    cout << "==================================================" << endl;
}

void lerOpcao(char* ptrOpcao) {
    cout << "> Escolha: ";
    cin >> *ptrOpcao;

    // Limpeza ROBUSTA do Buffer:
    // L� caracter por caracter at� encontrar o Enter ('\n') e o consome.
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

// --- CONTROLADORA DE L�GICA ---

void processarEscolha(char* ptrOpcao, bool* ptrRodando, AppContext* ctx) {
    cout << "\n--------------------------------------------------\n";

    switch (*ptrOpcao) {
        case '1':
            // Passamos o contexto para a tarefa espec�fica
            tarefaLerArquivoMusic(ctx);
            break;

        case '2':
            tarefaMostrarvetor_musica(ctx);
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

// --- IMPLEMENTA��O DAS TAREFAS (L�GICA PESADA) ---


void tarefaLerArquivoMusic (AppContext* ctx) {
    const char* arquivo_entrada = "music.txt";

    //ALIASES
    int* vetor = ctx->vetor_musica;
    int* cod_musica = ctx->cod_musica;
    char* nome_musica = {ctx->nome_musica};
    float* tempo_musica = ctx->tempo;

    // Abertura do Arquivo
    ifstream* entrada = new ifstream(arquivo_entrada);

    if (entrada->is_open()) {

        // Aloca��o tempor�ria no Heap para l�gica local
        int* capacidadeMax = new int(200);
        do {
            cout << "-> Informe a Quantidade de Musicas (1 a 200)..." << endl;
            cin >> *capacidadeMax;
        } while (*capacidadeMax < 1 || *capacidadeMax > 200);


        int* min = new int(1);



        // Lê enquanto houver números e houver espaço
        // Contador alocado no heap
        int* qtdLida = new int(0);
        while (*qtdLida < *capacidadeMax && !(entrada -> eof() ) ) {

            int* tempVal = new int;
            *entrada >> *tempVal;
            cout << tempVal;
                 while (*tempVal.isnumber())
                 {


                 };
            cout << "Qtdlida: " << *qtdLida << endl;
            cout << "Vetor: " << &vetor << endl;
            cout << "Valor " << *tempVal << " no vetor."
            // Aritmética: vetor ++
            (*qtdLida)++;
            (*vetor)++;
        }

        entrada->close();
        delete entrada;
        delete qtdLida;
        delete tempVal;
        delete capacidadeMax;
        delete min;
        pausarSistema();
    } else {
        cout << "Erro ao abrir arquivo para leitura.\n";
        pausarSistema();

    }
}

void tarefaMostrarvetor_musica(AppContext* ctx) {
    cout << "-> Conteudo do vetor_musica:" << endl;
    cout << "[ ";

    // Percorre usando os dados da struct
    int* inicio = ctx->vetor_musica; // ENDEREÇO INICIAL
    int* fim    = ctx->vetor_musica + *ctx->tamanho; // ENDEREÇO FINAL



    while (&inicio < &fim) {
        // Aritmética: vetor++
        cout << *inicio << " - " << &inicio << "\n";
        (inicio)++;
        }

    //for (int* p = inicio; p < fim; p++) {
    //   cout << *p << " ";
    //}

    cout << "]" << endl;
}
