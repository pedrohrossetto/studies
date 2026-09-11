/*
 * EXERCÍCIO 63 - SISTEMA DE SORTEIO E GESTÃO DE VETORES
 * Requisitos:
 * - Alocação 100% Dinâmica (Heap).
 * - Vetor Principal (Tamanho X: 5-50).
 * - Vetor Auxiliar (Tamanho 5).
 * - Funcionalidades: Gerar Unico, Remover se acertar, Inserir/Resetar Aux se errar.
 * - Exibição Decrescente.
 */

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>

using namespace std;

// ============================================================================
// 1. DEFINIÇÃO DO CONTEXTO
// ============================================================================
struct AppContext {
    // Vetor Principal (Dinâmico definido pelo usuário)
    int* vet;
    int* tamVet;     // Quantidade atual de elementos
    int* capVet;     // Capacidade máxima (X)

    // Vetor Auxiliar (Fixo em 5 posições)
    int* aux;
    int* tamAux;
    int* capAux;

    // Controle de Estado
    bool* flagGerado;
};

// ============================================================================
// 2. PROTOTIPOS
// ============================================================================

// Gestão
AppContext* inicializarContexto();
void destruirContexto(AppContext* ctx);

// Utilitários
void util_limparBuffer();
void util_ordenarDecrescente(int* vetor, int* tamanho);

// Interface
void exibirMenu();
void lerOpcao(char* ptrOpcao);
void pausarSistema();
void processarEscolha(char* ptrOpcao, bool* ptrRodando, AppContext* ctx);

// Tarefas
void tarefaGerarVetor(AppContext* ctx);
void tarefaSorteio(AppContext* ctx);
void tarefaExibirVetores(AppContext* ctx);

// ============================================================================
// 3. MAIN
// ============================================================================
int main() {
    // Variáveis de controle no Heap
    bool* ptrRodando = new bool(true);
    char* ptrOpcao   = new char(' ');

    AppContext* contexto = inicializarContexto();

    if (!contexto) {
        cout << "Erro fatal de memoria." << endl;
        return 1;
    }

    while (*ptrRodando) {
        system("cls"); // Limpa tela

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
// 4. GESTÃO DE MEMÓRIA
// ============================================================================

AppContext* inicializarContexto() {
    AppContext* ctx = new AppContext;

    // 1. Define tamanho do Vetor Principal (Validação 5 a 50)
    ctx->capVet = new int(0);
    bool* valido = new bool(false);

    do {
        cout << "Defina o tamanho do vetor 'vet' (5 a 50): ";
        cin >> *ctx->capVet;
        util_limparBuffer();

        if (*ctx->capVet >= 5 && *ctx->capVet <= 50) {
            *valido = true;
        } else {
            cout << "[ERRO]: Tamanho invalido." << endl;
        }
    } while (!*valido);
    delete valido;

    // 2. Aloca Vetor Principal
    ctx->vet = new int[*ctx->capVet];
    ctx->tamVet = new int(0);

    // 3. Aloca Vetor Auxiliar (Fixo 5)
    ctx->capAux = new int(5);
    ctx->aux = new int[*ctx->capAux];
    ctx->tamAux = new int(0);

    // Inicializa com zeros
    for (int* p = ctx->vet; p < ctx->vet + *ctx->capVet; p++) *p = 0;
    for (int* p = ctx->aux; p < ctx->aux + *ctx->capAux; p++) *p = 0;

    // 4. Flags
    ctx->flagGerado = new bool(false);

    return ctx;
}

void destruirContexto(AppContext* ctx) {
    if (ctx != NULL) {
        delete[] ctx->vet;
        delete[] ctx->aux;
        delete ctx->tamVet;
        delete ctx->capVet;
        delete ctx->tamAux;
        delete ctx->capAux;
        delete ctx->flagGerado;
        delete ctx;
    }
}

// ============================================================================
// 5. UTILITÁRIOS E ALGORITMOS DE APOIO
// ============================================================================

void util_limparBuffer() {
    char* lixo = new char;
    while (cin.get(*lixo) && *lixo != '\n');
    delete lixo;
}

void util_ordenarDecrescente(int* vetor, int* tamanho) {
    int* i = new int;
    int* j = new int;
    int* temp = new int;

    for (*i = 0; *i < *tamanho - 1; (*i)++) {
        for (*j = 0; *j < *tamanho - *i - 1; (*j)++) {
            
            int* atual   = (vetor + *j);
            int* proximo = (vetor + *j + 1);

            // Troca se atual < proximo (Decrescente)
            if (*atual < *proximo) {
                *temp    = *atual;
                *atual   = *proximo;
                *proximo = *temp;
            }
        }
    }
    delete i; delete j; delete temp;
}

// ============================================================================
// 6. INTERFACE
// ============================================================================

void exibirMenu() {
    cout << "==================================================" << endl;
    cout << "           EXERCICIO 63 - SORTEIO DINAMICO        " << endl;
    cout << "==================================================" << endl;
    cout << " [1] - Gerar Vetor Principal (Limpa Auxiliar)" << endl;
    cout << " [2] - Sorteio (Adivinhar numero)" << endl;
    cout << " [3] - Exibir Vetores (Decrescente)" << endl;
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
            tarefaGerarVetor(ctx); 
            break;

        case '2': 
            if (*ctx->flagGerado) tarefaSorteio(ctx);
            else cout << "[ERRO]: Gere o vetor primeiro (Opcao 1)." << endl;
            break;

        case '3': 
            if (*ctx->flagGerado) tarefaExibirVetores(ctx);
            else cout << "[ERRO]: Gere o vetor primeiro (Opcao 1)." << endl;
            break;

        case '0': 
            cout << "Saindo..." << endl;
            *ptrRodando = false; 
            break;

        default: 
            cout << "Opcao Invalida!" << endl;
    }
}

// ============================================================================
// 7. TAREFAS (LÓGICA PRINCIPAL)
// ============================================================================

void tarefaGerarVetor(AppContext* ctx) {
    cout << "-> Gerando valores aleatorios (1-50)..." << endl;

    // 1. Limpar Vetor Auxiliar (Exigência do exercício)
    *ctx->tamAux = 0;
    
    // 2. Resetar tamanho lógico do Vetor Principal
    *ctx->tamVet = *ctx->capVet; // Preenche totalmente

    int* pInicio = ctx->vet;
    int* pFim    = ctx->vet + *ctx->tamVet;
    
    int* tempVal = new int(0);
    bool* existe = new bool(false);

    // 3. Preencher Vetor Principal (Sem repetição)
    for (int* pAtual = pInicio; pAtual < pFim; pAtual++) {
        do {
            *existe = false;
            // Gera 1 a 50
            *tempVal = 1 + (rand() % 50);

            for (int* pCheck = pInicio; pCheck < pAtual; pCheck++) {
                if (*pCheck == *tempVal) {
                    *existe = true;
                    break;
                }
            }
        } while (*existe);

        *pAtual = *tempVal;
    }

    *ctx->flagGerado = true;
    cout << "-> Sucesso. Vetor gerado e Auxiliar limpo." << endl;

    delete tempVal;
    delete existe;
}

void tarefaSorteio(AppContext* ctx) {
    // 1. Mostrar Vetor Atual (Facilita testes, como pedido "Exibe o vetor vet")
    cout << "Vetor Atual: [ ";
    for (int* p = ctx->vet; p < ctx->vet + *ctx->tamVet; p++) cout << *p << " ";
    cout << "]" << endl;

    // 2. Ler Palpite (Validar 1-50)
    int* palpite = new int(0);
    bool* entradaOk = new bool(false);
    do {
        cout << "Informe um valor para o sorteio (1-50): ";
        cin >> *palpite;
        util_limparBuffer();
        if (*palpite >= 1 && *palpite <= 50) *entradaOk = true;
        else cout << "[ERRO]: Valor fora do intervalo." << endl;
    } while (!*entradaOk);
    delete entradaOk;

    // 3. Buscar no Vetor Principal
    int* pEncontrado = NULL;
    for (int* p = ctx->vet; p < ctx->vet + *ctx->tamVet; p++) {
        if (*p == *palpite) {
            pEncontrado = p;
            break;
        }
    }

    // 4. Lógica de Encontro
    if (pEncontrado != NULL) {
        // CASO ACHOU: Remover
        // Calcula índice usando aritmética (apenas para exibição)
        // Em C++ pointer diff retorna long, cast para int
        int indice = (int)(pEncontrado - ctx->vet);
        
        cout << "\n[ACHOU!]: Valor " << *palpite << " esta na posicao " << indice << endl;
        cout << "Endereco de memoria: " << pEncontrado << endl;

        // Remoção (Shift Left): Move todos à direita uma casa para a esquerda
        // Começa na posição encontrada e vai até o penultimo
        int* pShift = pEncontrado;
        int* pFimValid = ctx->vet + *ctx->tamVet;
        
        while (pShift < pFimValid - 1) {
            *pShift = *(pShift + 1); // Copia o próximo para o atual
            pShift++;
        }
        
        // Reduz tamanho lógico
        (*ctx->tamVet)--;
        cout << "-> Elemento removido do vetor principal." << endl;

    } else {
        // CASO NÃO ACHOU: Inserir no Auxiliar
        cout << "\n[NAO ACHOU]: O valor " << *palpite << " nao existe em VET." << endl;
        
        // Verifica se Auxiliar está cheio
        if (*ctx->tamAux >= *ctx->capAux) {
            cout << "[AVISO]: Vetor auxiliar cheio! Zerando vetor..." << endl;
            *ctx->tamAux = 0; // Reset lógico (elimina todos)
        }

        // Insere na próxima posição livre (que será 0 se tiver resetado)
        *(ctx->aux + *ctx->tamAux) = *palpite;
        (*ctx->tamAux)++;
        
        cout << "-> Valor inserido no vetor auxiliar." << endl;
        
        // Exibe Auxiliar
        cout << "Vetor Auxiliar Agora: [ ";
        for (int* p = ctx->aux; p < ctx->aux + *ctx->tamAux; p++) cout << *p << " ";
        cout << "]" << endl;
    }

    delete palpite;
}

void tarefaExibirVetores(AppContext* ctx) {
    // Requisito: Mostrar em ordem decrescente.
    // Vamos ordenar "in-place" (no próprio vetor) pois facilita a exibição
    
    cout << "--- Exibicao dos Vetores (Ordem Decrescente) ---" << endl;

    // Vetor Principal
    if (*ctx->tamVet > 0) {
        util_ordenarDecrescente(ctx->vet, ctx->tamVet);
        cout << "Vetor Principal (" << *ctx->tamVet << " itens): [ ";
        for (int* p = ctx->vet; p < ctx->vet + *ctx->tamVet; p++) {
            cout << *p << " ";
        }
        cout << "]" << endl;
    } else {
        cout << "Vetor Principal: [ VAZIO ]" << endl;
    }

    // Vetor Auxiliar
    if (*ctx->tamAux > 0) {
        util_ordenarDecrescente(ctx->aux, ctx->tamAux);
        cout << "Vetor Auxiliar (" << *ctx->tamAux << " itens):  [ ";
        for (int* p = ctx->aux; p < ctx->aux + *ctx->tamAux; p++) {
            cout << *p << " ";
        }
        cout << "]" << endl;
    } else {
        cout << "Vetor Auxiliar:  [ VAZIO ]" << endl;
    }
}