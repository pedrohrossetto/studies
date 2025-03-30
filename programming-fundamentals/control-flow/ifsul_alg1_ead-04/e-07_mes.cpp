// Autor: Pedro H.C Rossetto
// Data: 30/03/2025
// Descrição: Código para transformar número mês em nome do mês
// Lista EAD 3, Exercício 7, Algoritimos 1


#include <iostream>
#include <string>
using namespace std;

int main() {
    int mes;
    do {
        // Input month and validate
        cout << "Digite um Mês (1-12): ";
        cin >> mes;

        if (mes < 1 || mes > 12) {
            cout << "Mês inválido. Tente novamente." << endl;
        }
    } while (mes < 1 || mes > 12);

    // Continue with the rest of the program
    cout << "Mês válido: " << mes << endl;
    // Get month name
    string mes_nome;
    switch (mes) {
        case 1: mes_nome = "janeiro"; break;
        case 2: mes_nome = "fevereiro"; break;
        case 3: mes_nome = "março"; break;
        case 4: mes_nome = "abril"; break;
        case 5: mes_nome = "maio"; break;
        case 6: mes_nome = "junho"; break;
        case 7: mes_nome = "julho"; break;
        case 8: mes_nome = "agosto"; break;
        case 9: mes_nome = "setembro"; break;
        case 10: mes_nome = "outubro"; break;
        case 11: mes_nome = "novembro"; break;
        case 12: mes_nome = "dezembro"; break;
    }

    cout << "O mês de número "<< mes << " é o mês de " << mes_nome << "." << endl;
}