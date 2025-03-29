// Autor: Pedro H.C Rossetto
// Data: 29/03/2025
// Descrição: Código para verificar ano bissexto
// Lista EAD 3, Exercício 5, Algoritimos 1


#include <iostream>
#include <string>
using namespace std;

int main() {
    int ano, mes,dias;
    bool is_bissexto;
    
    // Input year and check if it's a leap year
    cout << "Digite um ano: ";
    cin >> ano;
    
    is_bissexto = ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0));
    
    if (is_bissexto) {
        cout << ano << " é um ano bissexto." << endl;
    } else {
        cout << ano << " não é um ano bissexto." << endl;
    }

    // Input month and validate
    cout << "Digite um Mês (1-12): ";
    cin >> mes;
    
    if (mes < 1 || mes > 12) {
        cout << "Mês inválido." << endl;
        return 1; // Exit if invalid
    }

    // Determine days in the month
    switch (mes) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            dias = 31;
            break;
        case 4: case 6: case 9: case 11:
            dias = 30;
            break;
        case 2:
            dias = (is_bissexto) ? 29 : 28; // Ternary operator for simplicity
            break;
    }

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

    // Output result
    cout << "O mês de " << mes_nome << " tem " << dias << " dias." << endl;

    return 0;
}