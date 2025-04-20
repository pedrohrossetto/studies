// Autor: Pedro H.C Rossetto
// Data: 07/04/2025
// Descrição: Código para para apresentar menu
// Lista de Exercícios, Exercício 1, EAD6

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    int option;
    int number = 0;
    bool valid_number = false;

    do {
        cout << "Selecione uma opção:\n"
             << "0 - Sair\n"
             << "1 - Ler um Valor\n"
             << "2 - Mostrar os números de 1 até o valor lido\n"
             << "3 - Verificar se o número lido é par ou impar\n";
        cin >> option;

        switch (option) {
            case 0:
                cout << "Saindo...\n";
                break;

            case 1: {
                do {
                    cout << "\nInforme um valor numérico inteiro: \n";
                    if (cin >> number) {
                        valid_number = true;
                    } else {
                        cin.clear(); // limpa flags de erro
                        cin.ignore(1000, '\n'); // descarta entrada inválida
                        cout << "Valor inválido. Por favor, tente novamente.\n";
                    }
                } while (!valid_number);
                break;
            }

            case 2:
                if (valid_number) {
                    cout << "Números de 1 até " << number << ":\n";
                    for (int i = 1; i <= number; ++i) {
                        cout << i << " ";
                    }
                    cout << endl;
                } else {
                    cout << "Nenhum valor foi lido ainda. Por favor, selecione a opção 1 primeiro.\n";
                }
                break;

            case 3:
                if (valid_number) {
                    if (number % 2 == 0) {
                        cout << "O número " << number << " é par.\n";
                    } else {
                        cout << "O número " << number << " é ímpar.\n";
                    }
                } else {
                    cout << "Nenhum valor foi lido ainda. Por favor, selecione a opção 1 primeiro.\n";
                }
                break;

            default:
                cout << "Opção inválida. Por favor, tente novamente.\n";
                break;
        }
    } while (option != 0);

    return 0;
}