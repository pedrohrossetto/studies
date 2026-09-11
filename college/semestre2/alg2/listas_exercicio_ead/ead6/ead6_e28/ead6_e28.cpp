/*
    Autor: Pedro H.C Rossetto
    Data: 30/09/2025
    Descrição: Faça  um  programa  que  implemente  uma  função  recursiva  que  receba  dois  números 
positivos por parâmetro e retorne a soma dos N números inteiros existentes entre eles.
    Trabalho prático 6, Exercício 28, Algoritimos 2
*/

#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <locale.h>

using namespace std;

int valores(int soma, int n1, int n2);

int main() {
    int soma = 0, num1 = 0, num2 = 0;

    cout << "Digite o primeiro numero: ";
    cin >> num1;

    cout << "Digite o segundo numero: ";
    cin >> num2;

    if (num1 > num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }

    cout << "A soma dos valores entre " << num1 << " e " << num2 << " é " << valores(0, num1, num2);

    return 0;
}

int valores(int soma, int n1, int n2)
{
    if (n1 >= n2 - 1) {
        return soma;
    } else {
        soma += (n1 + 1);
        return valores(soma, n1 + 1, n2);
    }
}



