#include <iostream>
#include <cstdio>   // Para setlocale
#include <cstdlib>  // Para rand() e new/delete
#include <ctime>
using namespace std;

// --- PROTÓTIPOS CORRIGIDOS ---
// As funções são 'void' pois apenas manipulam os ponteiros
// Passamos 'tamanho' e 'valor' como int normais
// Passamos contadores (como contSobra) quando a função precisa alterá-los
void gerar(int *pvet, int tamanho);
void procurar(int *pvet, int *psobra, int tamanho, int *contSobra, int valor);
void mostrar_vet1(int *pvet, int tamanho);
void mostrar_sobra(int *psobra, int contSobra); // Mostra só até onde foi preenchido

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "portuguese");

    int opc;
    int tamanho = 0;
    int valor;          // Valor a ser procurado no case 2
    int contSobra = 0;  // Contador para a próxima posição livre do vetor 'sobra'

    // Ponteiros dos vetores (declarados fora do loop)
    int *vet = nullptr;
    int *sobra = nullptr;

    // Flags de controle
    bool vetGerado = false;
    bool sobraUsada = false;

    do
    {
        cout << "\n--- MENU ---\n";
        cout << "0 - Sair\n";
        cout << "1 - Gerar valores para o vetor\n";
        cout << "2 - Localizar Valor\n";
        cout << "3 - Mostrar todos elementos de Vet\n";
        cout << "4 - Mostrar todos elementos de Sobra\n";
        cout << "Escolha: ";
        cin >> opc;

        switch (opc)
        {
        case 0:
            cout << "Encerrando programa...\n";
            break;

        case 1:
            cout << "Insira o tamanho do vetor (entre 5 e 50): ";
            cin >> tamanho;

            // Validação correta (enquanto for inválido, pede de novo)
            while (tamanho < 5 || tamanho > 50)
            {
                cout << "Tamanho invalido! Insira um valor entre 5 e 50: ";
                cin >> tamanho;
            }

            // Se o vetor já existia, limpa a memória antes de criar um novo
            if (vetGerado)
            {
                delete[] vet;
                delete[] sobra;
            }

            // Aloca os vetores dinamicamente
            vet = new int[tamanho];
            sobra = new int[tamanho];

            gerar(vet, tamanho); // Chamada correta

            vetGerado = true; // Seta a flag
            sobraUsada = false; // Reseta as flags
            contSobra = 0;    // Zera o contador do 'sobra'
            cout << "Vetor 'vet' gerado com " << tamanho << " posicoes!\n";
            break;

        case 2:
            // Checagem da flag
            if (vetGerado == false)
            {
                cout << "ERRO: Voce precisa gerar os valores (Opcao 1) primeiro.\n";
            }
            else
            {
                cout << "Digite o valor que deseja localizar: ";
                cin >> valor;

                // Passamos o endereço do contador (&contSobra) para que a função possa alterá-lo
                procurar(vet, sobra, tamanho, &contSobra, valor);

                sobraUsada = true; // Seta a flag
            }
            break;

        case 3:
            // Checagem da flag
            if (vetGerado == false)
            {
                cout << "ERRO: Voce precisa gerar os valores (Opcao 1) primeiro.\n";
            }
            else
            {
                cout << "--- Elementos do Vetor 'vet' ---\n";
                mostrar_vet1(vet, tamanho); // Chamada correta
            }
            break;

        case 4:
            // Checagem da flag
            if (sobraUsada == false)
            {
                cout << "ERRO: Voce precisa usar a (Opcao 2) pelo menos uma vez.\n";
            }
            else
            {
                cout << "--- Elementos do Vetor 'sobra' ---\n";
                mostrar_sobra(sobra, contSobra); // Chamada correta
            }
            break;

        default:
            cout << "Opcao invalida! Tente novamente.\n";
        }
    } while (opc != 0);

    // --- LIMPEZA DE MEMÓRIA ---
    if (vetGerado) // Só deleta se foi alocado
    {
        delete[] vet;
        delete[] sobra;
    }

    return 0;
}

// --- FUNÇÃO GERAR ---
// Preenche 'pvet' com 'tamanho' números aleatórios sem repetição
void gerar(int *pvet, int tamanho)
{
    int aux;    // Guarda o valor aleatório temporário
    bool achou; // Flag para checar se o valor já existe

    // Ponteiros para controlar o percurso "sem variáveis"
    int *inicio = pvet;       // Guarda o endereço inicial
    int *fim = pvet + tamanho; // Calcula o endereço final (após o último elemento)
    int *percorre;            // Ponteiro auxiliar para o loop de verificação

    // Loop principal: "enquanto o ponteiro atual 'pvet' for menor que o 'fim'"
    // Substitui o "for (int i = 0; i < tamanho; i++)"
    while (pvet < fim)
    {
        do
        {
            aux = rand() % 50 + 1; // Gera um valor entre 1 e 50
            achou = false;
            percorre = inicio; // Reseta o ponteiro 'percorre' para o início

            // Loop de verificação: "enquanto 'percorre' for menor que 'pvet'"
            // (Verifica apenas os elementos já preenchidos)
            while (percorre < pvet)
            {
                if (*percorre == aux) // Compara o valor no endereço
                {
                    achou = true;
                    break;
                }
                percorre++; // Avança 'percorre' para o próximo endereço
            }

            if (achou == false)
            {
                *pvet = aux; // Armazena o valor no endereço atual
                pvet++;      // Avança 'pvet' para a próxima posição (move o loop principal)
            }
        } while (achou == true); // Repete se o número era duplicado
    }
}

// --- FUNÇÃO PROCURAR ---
// Procura 'valor' em 'pvet'. Se não achar, adiciona em 'psobra'
void procurar(int *pvet, int *psobra, int tamanho, int *contSobra, int valor)
{
    // Ponteiros para o percurso do 'pvet'
    int *inicio = pvet;
    int *fim = pvet + tamanho;

    // 1. Loop de busca no vetor 'vet'
    while (pvet < fim)
    {
        if (*pvet == valor)
        {
            // Achou
            cout << "Valor " << *pvet << ", pertence ao vetor esta no endereco de memoria " << pvet << endl;
            return; // Sai da função
        }
        pvet++; // Avança o ponteiro
    }

    // 2. Se o loop terminou, não achou
    cout << "Valor " << valor << " nao pertence ao vetor." << endl;

    // 3. Lógica de adicionar no vetor 'sobra'
    if (*contSobra == tamanho)
    {
        // "eliminar todos os elementos"
        cout << "Vetor 'sobra' esta cheio. Eliminando elementos..." << endl;
        *contSobra = 0; // Zera o contador (começa a sobrescrever do início)
    }

    // Adiciona o valor na próxima posição livre de 'sobra'
    // Usa aritmética de ponteiros: (psobra + *contSobra)
    *(psobra + *contSobra) = valor;
    (*contSobra)++; // Incrementa o contador de 'sobra'

    cout << "Valor " << valor << " adicionado ao vetor 'sobra'." << endl;

    // 4. Exibir valores do vetor 'sobra' (como pedido no enunciado)
    cout << "--- Vetor 'sobra' atual ---" << endl;
    mostrar_sobra(psobra, *contSobra);
}

// --- FUNÇÃO MOSTRAR VET ---
// Mostra os 'tamanho' elementos de 'pvet'
void mostrar_vet1(int *pvet, int tamanho)
{
    int *ponteiro_atual = pvet; // Ponteiro auxiliar para percorrer
    int *fim = pvet + tamanho;

    // Loop "sem variável de índice"
    while (ponteiro_atual < fim)
    {
        // (ponteiro_atual - pvet) calcula o "índice" (offset)
        cout << "vet [" << (ponteiro_atual - pvet) + 1 << "]: " << *ponteiro_atual << endl;
        ponteiro_atual++; // Avança o ponteiro
    }
}

// --- FUNÇÃO MOSTRAR SOBRA ---
// Mostra os 'contSobra' elementos de 'psobra'
void mostrar_sobra(int *psobra, int contSobra)
{
    int *ponteiro_atual = psobra; // Ponteiro auxiliar
    int *fim = psobra + contSobra;  // O fim é baseado em quantos itens temos

    if (ponteiro_atual == fim)
    {
        cout << "(Vetor 'sobra' esta vazio)" << endl;
        return;
    }

    // Loop "sem variável de índice"
    while (ponteiro_atual < fim)
    {
        cout << "sobra [" << (ponteiro_atual - psobra) + 1 << "]: " << *ponteiro_atual << endl;
        ponteiro_atual++; // Avança o ponteiro
    }
}
