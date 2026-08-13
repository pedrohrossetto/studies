// Autor: Pedro H.C Rossetto
// Data: 30/03/2025
// Descrição: Código para verificar placa e calcular ipva
// Lista EAD 4, Exercício 4, Algoritimos 1


#include <iostream>
#include <iomanip>
#include <regex>
using namespace std;

int main() {
    regex padrao_mercosul("^[A-Za-z]{3}[0-9][A-Za-z][0-9]{2}$"); // Pesquisado
    string plate;
    bool is_plate_mercosul = false;
    int plate_last_digit;

    do {
        cout << "Informe a placa de seu carro: " << endl;
        cin >> plate;
        is_plate_mercosul = regex_match(plate, padrao_mercosul);
    } 
    while(!is_plate_mercosul);
    plate_last_digit = plate.back() - '0'; // conversão char - int (ASCII) Pesquisado

    switch (plate_last_digit) {
        case 1:
            cout << "Data de vencimento do IPVA: 24 de Abril" << endl;
            break;
        case 2:
            cout << "Data de vencimento do IPVA: 24 de Abril" << endl;
            break;
        case 3:
            cout << "Data de vencimento do IPVA: 25 de Abril" << endl;
            break;
        case 4:
            cout << "Data de vencimento do IPVA: 25 de Abril" << endl;
            break;
        case 5:
            cout << "Data de vencimento do IPVA: 26 de Abril" << endl;
            break;
        case 6:
            cout << "Data de vencimento do IPVA: 26 de Abril" << endl;
            break;
        case 7:
            cout << "Data de vencimento do IPVA: 29 de Abril" << endl;
            break;
        case 8:
            cout << "Data de vencimento do IPVA: 29 de Abril" << endl;
            break;
        case 9:
            cout << "Data de vencimento do IPVA: 30 de Abril" << endl;
            break;
        case 0:
            cout << "Data de vencimento do IPVA: 30 de Abril" << endl;
            break;
        default:
            cout << "Inválido." << endl;
            break;
        }
}