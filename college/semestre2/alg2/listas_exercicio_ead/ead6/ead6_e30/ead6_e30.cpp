/*
    Autor: Pedro H.C Rossetto
    Data: 30/09/2025
    Descrição: Crie um programa que implemente uma função recursiva para calcular o MDC (Máximo 
Divisor Comum) entre dois números inteiros e positivos.
    Trabalho prático 6, Exercício 30, Algoritimos 2
*/

#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <locale.h>
#include <cmath>


using namespace std; 

int euclides_mdc (int x, int y);

int main () {
    setlocale(LC_ALL, "Portuguese"); 
    system("cls");
    int x, y;

    do
    {
        system("cls");
        cout << "Informe um numero inteiro positivo: ";
        cin >> x;

    } while (x < 0);

    do
    {
        system("cls");
        cout << "Informe um segundo numero inteiro positivo: ";
        cin >> y;

    } while (y < 0);

    system("cls");
    
    int resultado_mdc = euclides_mdc(x, y);
    cout << "O MDC de " << x << " e " << y << " é: " << resultado_mdc << endl;


}


int euclides_mdc (int x, int y){
    if (x == 0 )
    {
        cout << "Erro, x nao pode ser 0";
        return 0;
    }
    if (y == 0){
        return x;
    }
    else{
        return euclides_mdc(y, (x%y));
    }   
}