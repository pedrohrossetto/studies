// Autor: Pedro H.C Rossetto
// Data: 20/04/2025
// Descrição: Código para para apresentar numeros perfeitos
// Lista de Exercícios, Exercício 4, EAD6

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    int divisor = 1, dividendo = 2, contador = 0;
    for (dividendo; contador < 3; dividendo++)
    {
        // cout << "Dividendo testado: " << dividendo << endl;
        int sum = 0;
        for (divisor = 1; divisor < dividendo; divisor++)
        // cout << "Divisor testado: " << divisor << endl; Ao usar essas duas linhas o comportamento da função muda?
        {
            if (dividendo % divisor == 0)
            {
                sum += divisor;
            }
        }
        if (sum == dividendo)
        {
            contador++;
            cout << "Número perfeito: " << dividendo << endl;
        }
    }
}
