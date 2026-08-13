/*
Faça um programa que implemente uma função recursiva que receba dois números
positivos por parâmetro e retorne a soma dos N números inteiros existentes entre eles.
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <cstdio>

using namespace std;

int somaRecursiva(int n1, int n2) {
    
    if (n1 > n2) {
        int temp = n1;
        n1 = n2;
        n2 = temp;
    }

    if (n1 == n2) {
        return n1;
    }
    else {
        return n2 + somaRecursiva(n1, n2 - 1);
    }
}

int main() {
    int num1, num2;

    cout << "Digite o primeiro numero inteiro positivo: ";
    cin >> num1;

    cout << "Digite o segundo numero inteiro positivo: ";
    cin >> num2;

    if (num1 <= 0 || num2 <= 0) {
        cout << "\nErro: Por favor, insira apenas numeros inteiros positivos." << endl;
        return 1;
    }

    int resultado = somaRecursiva(num1, num2);

    cout << "\nA soma dos numeros inteiros entre " << num1 << " e " << num2 << " é: " << resultado << endl;

    return 0;
}