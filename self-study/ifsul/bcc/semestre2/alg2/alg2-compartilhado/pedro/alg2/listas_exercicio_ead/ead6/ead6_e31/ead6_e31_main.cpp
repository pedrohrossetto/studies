// main.cpp

/*
    Autor: Pedro H.C Rossetto
    Data: 30/09/2025
    Descrição: Programa principal para validação de Quadrado Mágico.
    Trabalho prático 6, Exercício 31, Algoritimos 2
*/

#include <iostream>
#include <ctime>
#include <cctype>
#include "ead6_e31.hpp"

using namespace std;

int main() {
    srand(time(0));

    char opcao;
    int matriz[10][10];
    int ordem = 0;
    bool matriz_preenchida = false;

    do {
        system("cls");
        cout << "- MENU -\n";
        cout << "1. Gerar novo arquivo de valores\n";
        cout << "2. Preencher matriz\n";
        cout << "3. Mostrar Matriz\n";
        cout << "4. Verificar se e um Quadrado Magico\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case '1':
                gerar_novo_arquivo_valores();
                break;

            case '2':
                do {
                    cout << "Informe o valor da Ordem (entre 3 e 10): ";
                    cin >> ordem;
                } while (ordem < 3 || ordem > 10);

                if (preencher_matriz(matriz, ordem)) {
                    cout << "Matriz preenchida com sucesso!\n";
                    matriz_preenchida = true;
                } else {
                    matriz_preenchida = false;
                }
                break;
            
            case '3':
                system("cls");
                cout << "\n\n-----------------------------------------------------\n\n";
                if (matriz_preenchida) {
                    mostrar_matriz(matriz, ordem);
                } else {
                    cout << "Primeiro preencha a matriz (Opcao 2).\n";
                }
                break;

            case '4':
                if (matriz_preenchida) {
                    if (validar_quadrado_magico(matriz, ordem)) {
                        cout << "\n\n-----------------------------------------------------\n\n";
                        cout << "\n\tForma um quadrado magico.\n";
                        cout << "\n\n-----------------------------------------------------\n\n";
                    } else {
                        cout << "\n\n-----------------------------------------------------\n\n";
                        cout << "\n\tNao forma um quadrado magico.\n";
                        cout << "\n\n-----------------------------------------------------\n\n";
                    }
                } else {
                    cout << "\nPrimeiro preencha a matriz (Opcao 2).\n";
                }
                char reiniciar;
                    do
                    {
                        cout << "\n\nVerificar  outra  matriz ou encerrar o programa? (S/N)\n\n";
                        cin >> reiniciar;
                        reiniciar = toupper(reiniciar);
                    } while (reiniciar != 'S' && reiniciar != 'N');
                    if (reiniciar == 'S')
                    {
                        break;
                    }
                    if (reiniciar == 'N')
                    {
                        system("cls");
                        cout << "Encerrando o programa.";
                        return 0;
                    }
                break;

            case '0':
                system("cls");
                cout << "Encerrando o programa." << endl;
                break;
            
            default:
                cout << "Opcao invalida!" << endl;
                break;
        }

        if (opcao != '0') {
             cout << "\nPressione Enter para continuar...";
             cin.ignore();
             cin.get();
        }

    } while (opcao != '0');

    return 0;
}