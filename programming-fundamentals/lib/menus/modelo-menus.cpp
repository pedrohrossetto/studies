/* * MODELO DE MENU INTERATIVO
 * Bibliotecas permitidas: <iostream>, <cstdio>, <cstdlib>, <fstream>, <cstring>, <cmath>, <iomanip>
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>  // Para system("cls") ou exit()
#include <fstream>
#include <cstring>
#include <cmath>
#include <iomanip>

using namespace std;

// --- PROTOTIPOS DAS FUNCOES ---
// Declare suas funcoes aqui para manter o codigo organizado
void exibirMenu();
void limparBuffer();
void executarTarefa1();
void executarTarefa2();
// void executarTarefa3(); ...

int main() {
    char opcao;
    bool rodando = true;

    while (rodando) {
        // Opcional: Limpa a tela (funciona em Windows). 
        // Para Linux/Mac use system("clear"). Se der erro, remova esta linha.
        system("cls"); 

        exibirMenu();

        cout << "\n> Escolha uma opcao: ";
        cin >> opcao;

        // Limpa o buffer caso o usuario digite "1abc" para nao travar o loop
        limparBuffer(); 

        cout << "\n--------------------------------------------------\n";

        switch (opcao) {
            case '1':
                executarTarefa1();
                break;

            case '2':
                executarTarefa2();
                break;

            // Exemplo de caso com letra (aceita 'a' ou 'A')
            case 'a':
            case 'A':
                cout << "Voce escolheu a opcao secreta A." << endl;
                // logica aqui...
                break;

            case '0':
            case 's': // Opcao para Sair
            case 'S':
                cout << "Encerrando o programa..." << endl;
                rodando = false;
                break;

            default:
                cout << "Opcao invalida! Tente novamente." << endl;
                break;
        }

        if (rodando) {
            cout << "\n--------------------------------------------------\n";
            cout << "Pressione ENTER para voltar ao menu...";
            // O cin.get() pausa a tela ate o usuario dar Enter
            cin.get(); 
        }
    }

    return 0;
}

// --- IMPLEMENTACAO DAS FUNCOES ---

void exibirMenu() {
    cout << "==================================================" << endl;
    cout << "                MENU PRINCIPAL                    " << endl;
    cout << "==================================================" << endl;
    cout << " [1] - Calcular operacao X (Exemplo)" << endl;
    cout << " [2] - Ler arquivo de dados (Exemplo)" << endl;
    cout << " [A] - Opcao Extra" << endl;
    cout << " [0] - Sair" << endl;
    cout << "==================================================" << endl;
}

void limparBuffer() {
    // Ignora caracteres restantes no buffer de entrada ate encontrar uma quebra de linha
    // Isso evita bugs se o usuario digitar "10" em vez de "1" num menu de char
    while (cin.peek() != '\n' && cin.peek() != EOF) {
        cin.ignore();
    }
}

void executarTarefa1() {
    cout << "Executando a TAREFA 1..." << endl;
    // Insira a logica do exercicio aqui
    // Ex: cout << setprecision(2) << fixed << ...
}

void executarTarefa2() {
    cout << "Executando a TAREFA 2..." << endl;
    // Insira a logica do exercicio aqui
}