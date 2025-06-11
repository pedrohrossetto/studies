// Autor: Pedro H.C Rossetto
// Data: 27/03/2025
// Descrição: Código oara calcular valor da compra e valor de desconto.
// Trabalho prático 1, Exercício 1, Algoritimos 1


#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int payment_method;
        do{
        cout << "Escolha sua forma de pagamento, selecione o número respectivo: " << endl << "1 - Pix ou dinheiro" << endl << "2 - Cartão de débito" << endl << "3 - Cartão de crédito" << endl << "" << endl;
        cin >> payment_method;}

        while(payment_method < 1 || payment_method > 3);
    
    float buy_value, discount_porcentage, discount_value,buy_final_value;

    do {cout << "Informe valor da compra: ";
    cin >> buy_value;}
    while (buy_value < 1);

    cout << fixed << setprecision(2);

    if (buy_value <= 100) {
        switch (payment_method) {
            case 1: discount_porcentage = 0.05f; break;
            case 2: discount_porcentage = 0.02f; break;
            case 3: discount_porcentage = 0.00f; break;
        }
    } 
    else if (buy_value <= 500) {
        switch (payment_method) {
            case 1: discount_porcentage = 0.10f; break;
            case 2: discount_porcentage = 0.08f; break;
            case 3: discount_porcentage = 0.04f; break;
        }
    } 
    else {
        switch (payment_method) {
            case 1: discount_porcentage = 0.15f; break;
            case 2: discount_porcentage = 0.10f; break;
            case 3: discount_porcentage = 0.075f; break;
        }
    }
    discount_value = buy_value * discount_porcentage;
    buy_final_value = buy_value - discount_value;

    cout << "Valor da compra: R$" << buy_value <<endl
    << "Valor do desconto: R$" << discount_value <<endl
    << "Valor final da compra: R$" << buy_final_value <<endl;
}