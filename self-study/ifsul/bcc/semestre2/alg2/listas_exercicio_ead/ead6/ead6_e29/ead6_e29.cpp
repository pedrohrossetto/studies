/*
    Autor: Pedro H.C Rossetto
    Data: 30/09/2025
    Descrição: Crie um programa que, utilizando uma função recursiva, inverta um número inteiro 
qualquer. 
    Trabalho prático 6, Exercício 29, Algoritimos 2
*/

#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <locale.h>
#include <cmath>


using namespace std; 

int inverter_int(int n);

int main () {
    setlocale(LC_ALL, "Portuguese"); 
    system("cls");
    int v;
    cout << "Informe um valor qualquer: ";
    cin >> v;
    cout << "Valor invertido: " << inverter_int(v) << endl;
    }

    int inverter_int(int n)
    {
    if(n < 10 && n > -10)
    return n;
    else
    {
        int ultimo_digito = n % 10;
        int valor_sem_ultimo_digito = n / 10;
        int numero_digitos = floor(log10(abs(valor_sem_ultimo_digito))) + 1;
        return ultimo_digito * pow(10, numero_digitos) + inverter_int(valor_sem_ultimo_digito);
       }
    }