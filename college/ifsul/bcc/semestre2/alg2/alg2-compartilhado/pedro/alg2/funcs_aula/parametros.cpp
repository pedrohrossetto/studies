/*
    Autor: Pedro H.C Rossetto
    Data: 01/09/2025
    Descrição: Escreva um programa para controlar a venda de ingresso de um estádio de futebol
    Trabalho prático 4, Exercício 1, Algoritimos 2
*/

#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>


using namespace std; 


int leitura(char texto[]){

    int temp;
    cout << texto;
    cin >> temp;
    return temp;
}

int main () {
    system("chcp 1252 > nul");
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    int i, j;
    i = leitura("Informe o valor de i: ");
    cin >> i;

}