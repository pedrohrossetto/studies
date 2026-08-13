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

        cout << "Escolha sua forma de pagamento, selecione o número respectivo: " << endl << "1 - Pix ou dinheiro" << endl << "2 - Cartão de débito" << endl << "3 - Cartão de crédito" << endl << "" << endl;
        cin >> payment_method;

        if (payment_method < 1 || payment_method > 3) {
        cout << "Forma de pagamento inválida." << endl;
        return 1;
        }
    
    float buy_value, discount_porcentage, discount_value,buy_final_value;

    discount_value = buy_value * discount_porcentage;
    buy_final_value = buy_value - discount_value;

    cout << "Informe valor da compra: ";
    cin >> buy_value;

    if (buy_value < 1) {
        cout << "Valor de compra não pode ser menor que um.";
    }   
    cout << fixed << setprecision(2);

    if (buy_value >= 1 && buy_value <= 100)
    {
        if ( payment_method == 1){
            discount_porcentage = 0.05;
            discount_value = buy_value * discount_porcentage;
            buy_final_value = buy_value - discount_value;
            cout << "Valor da compra: R$" << buy_value <<endl;
            cout << "Valor do desconto: R$" << discount_value <<endl;
            cout << "Valor final da compra: R$" << buy_final_value <<endl;
        }
        if ( payment_method == 2){
            discount_porcentage = 0.02;
            discount_value = buy_value * discount_porcentage;
            buy_final_value = buy_value - discount_value;
            cout << "Valor da compra: R$" << buy_value <<endl;
            cout << "Valor do desconto: R$" << discount_value <<endl;
            cout << "Valor final da compra: R$" << buy_final_value <<endl;
        }
        if ( payment_method == 3){
            discount_porcentage = 0.00;
            discount_value = buy_value * discount_porcentage;
            buy_final_value = buy_value - discount_value;
            cout << "Valor da compra: R$" << buy_value <<endl;
            cout << "Valor do desconto: R$" <<  setprecision(0) << discount_value <<endl;
            cout << "Valor final da compra: R$" <<  setprecision(2) << buy_final_value <<endl;
        }
    }

    if (buy_value > 100 && buy_value <= 500)
    {
        if ( payment_method == 1){
            discount_porcentage = 0.10;
            discount_value = buy_value * discount_porcentage;
            buy_final_value = buy_value - discount_value;
            cout << "Valor da compra: R$" << buy_value <<endl;
            cout << "Valor do desconto: R$" << discount_value <<endl;
            cout << "Valor final da compra: R$" << buy_final_value <<endl;
        }
        if ( payment_method == 2){
            discount_porcentage = 0.08;
            discount_value = buy_value * discount_porcentage;
            buy_final_value = buy_value - discount_value;
            cout << "Valor da compra: R$" << buy_value <<endl;
            cout << "Valor do desconto: R$" << discount_value <<endl;
            cout << "Valor final da compra: R$" << buy_final_value <<endl;
        }
        if ( payment_method == 3){
            discount_porcentage = 0.04;
            discount_value = buy_value * discount_porcentage;
            buy_final_value = buy_value - discount_value;
            cout << "Valor da compra: R$" << buy_value <<endl;
            cout << "Valor do desconto: R$" << discount_value <<endl;
            cout << "Valor final da compra: R$" << buy_final_value <<endl;
        }
    }

    if (buy_value > 500)
    {
        if ( payment_method == 1){
            discount_porcentage = 0.15;
            discount_value = buy_value * discount_porcentage;
            buy_final_value = buy_value - discount_value;
            cout << "Valor da compra: R$" << buy_value <<endl;
            cout << "Valor do desconto: R$" << discount_value <<endl;
            cout << "Valor final da compra: R$" << buy_final_value <<endl;
        }
        if ( payment_method == 2){
            discount_porcentage = 0.10;
            discount_value = buy_value * discount_porcentage;
            buy_final_value = buy_value - discount_value;
            cout << "Valor da compra: R$" << buy_value <<endl;
            cout << "Valor do desconto: R$" << discount_value <<endl;
            cout << "Valor final da compra: R$" << buy_final_value <<endl;
        }
        if ( payment_method == 3){
            discount_porcentage = 0.075;
            discount_value = buy_value * discount_porcentage;
            buy_final_value = buy_value - discount_value;
            cout << "Valor da compra: R$" << buy_value <<endl;
            cout << "Valor do desconto: R$" << discount_value <<endl;
            cout << "Valor final da compra: R$" << buy_final_value <<endl;
        }
    }
}
