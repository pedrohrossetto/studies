// Autor: Pedro H.C Rossetto
// Data: 29/03/2025
// Descrição: Código para verificar forma de pagamento e desconto
// Lista EAD 3, Exercício 6, Algoritimos 1


#include <iostream>
#include <string>
using namespace std;

int main() {

int payment_method;

    cout << "Escolha sua forma de pagamento, selecione o número respectivo: " << endl << "1 - Pagamento à vista" << endl << "2 - Pagamento parcelado "<< endl << endl;
    cin >> payment_method;

    if (payment_method < 1 || payment_method > 3) {
        cout << "Forma de pagamento inválida." << endl;
        return 1;
    }
    
    float buy_value, discount_porcentage, discount_value,buy_final_value;



    cout << "Informe valor da compra: ";
    cin >> buy_value;

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

}