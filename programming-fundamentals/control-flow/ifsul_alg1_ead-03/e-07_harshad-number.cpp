// Autor: Pedro H.C Rossetto
// Data: 29/03/2025
// Descrição: Código para verificar número de Harshad
// Lista EAD 3, Exercício 7, Algoritimos 1


#include <iostream>
#include <string>
using namespace std;


int main() {
    int number,dezena,unidade;

    cout << "Informe um número entre 10 e 99: " << endl;
    cin >> number;
    if (number > 99 || number < 10) {cout << "Numero inválido.";}

    dezena = number /10;
    unidade = number % 10;

    bool is_harshad;

    is_harshad = (number % (dezena + unidade) == 0);
    
    if(is_harshad){
        cout << "Valor é um número de Harshad.";
    } else {
        cout << "Valor não é um número de Harshad";
    }


}