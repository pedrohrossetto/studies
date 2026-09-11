/*
    Autor: Pedro H.C Rossetto
    Data: 08/09/2025
    Descrição: Escreva um programa para calcular imc
    Algoritimos 2, Trabalho prático 5, Exercício 1
*/



#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>


using namespace std; 


float calcular_imc(float altura, char sexo){
    float peso_ideal = 0.0, coeficiente_sexo = 0, subtraidor_sexo = 0;
    if (sexo == 'm')
    {
        coeficiente_sexo = 72.7;
        subtraidor_sexo = 58.0;
    }
    if (sexo == 'f')
    {
        coeficiente_sexo = 62.1;
        subtraidor_sexo = 44.7;
    }

    peso_ideal = altura * coeficiente_sexo - subtraidor_sexo;
    if (peso_ideal == 0)
    {
        cout << "Parametros nao informados.";
    }
    
    return peso_ideal;
}


int main () {
    system("chcp 1252 > nul");
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    float altura, peso_ideal;
    char sexo;
    do
    {
    system("cls");
    cout << "Informe sua altura em metros (até 2.5 metros): ";
    cin >> altura;
    } while (altura < 0 && altura >= 2.5);

    do
    {
        system("cls");
        cout << "Informe seu sexo (f/m): ";
        cin >> sexo;
        sexo = tolower(sexo);
    } while (sexo != 'f' && sexo != 'm');
    
    
    system("cls");
    cout << "Altura considerada: " << altura << "\n";
    cout << "Sexo informado: " << sexo << "\n\n";
    cout << "Seu peso ideal é: " << fixed << setprecision(2) << calcular_imc(altura, sexo);
    
}