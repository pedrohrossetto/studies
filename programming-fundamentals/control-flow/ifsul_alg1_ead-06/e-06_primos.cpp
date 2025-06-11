// Autor: Pedro H.C Rossetto
// Data: 21/04/2025
// Descrição: // Leia e verifique se o número lido é um número primo ou não.
// Lista de Exercícios, Exercício 6, EAD6

#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main()
{
    int num;
    bool is_primo = true;

    cout << "Digite um número: ";
    cin >> num;

    if (num <= 1)
    {
        is_primo = false;
    }
    else
    {
        for (int i = 2; i <= num / 2; i++)
        {
            // cout << "Dividindo por: " << i << endl;
            if (num % i == 0)
            {
                is_primo = false;
                break;
            }
        }
    }

    if (is_primo)
    {
        cout << num << " é um número primo." << endl;
    }
    else
    {
        cout << num << " não é um número primo." << endl;
    }
}