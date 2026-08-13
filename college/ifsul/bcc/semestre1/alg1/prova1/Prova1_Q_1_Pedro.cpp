// Autor: Pedro H.C Rossetto
// Data: 24/04/2025
// Descrição: Código para para calcular ICMS
// PROVA 1, QUESTÃO 1

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float icms;
    int codigo_estado;
    cout << "\nInforme o estado (1-27):\n";
    cin >> codigo_estado;
    switch (codigo_estado)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        icms = 0.17;
        break;
    case 6:
    case 7:
    case 8:
        icms = 0.18;
        break;
    case 9:
    case 10:
    case 11:
    case 12:
        icms = 0.19;
        break;
    case 13:
    case 14:
        icms = 0.195;
        break;
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
        icms = 0.2;
        break;
    case 23:
    case 24:
        icms = 0.205;
        break;
    case 25:
        icms = 0.22;
        break;
    case 26:
        icms = 0.225;
        break;
    case 27:
        icms = 0.23;
        break;
    default:
        cout << "Estado Inválido.";
        return 1;
        break;
    }

    float produto_valor;

    cout << "\nDigite o valor do produto:\n";
    cin >> produto_valor;
    if (produto_valor <= 0){
        cout << "Valor do produto Inválido.\n";
        return 1;
    }


    float valor_icms;
    valor_icms = produto_valor * icms;
    cout << "Valor ICMS: " << valor_icms <<endl;
    return 0;
}
