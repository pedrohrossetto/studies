#ifndef _HPP_CLIENTE
#define _HPP_CLIENTE

#include <string>
using namespace std;

struct Cliente
{
    int codigo;
    string nome;
    int idade;
    float saldo;

    Cliente()
    {
        codigo = 0;
        nome="";
        idade=0;
        saldo = 0.0f;
    }

    Cliente(int cod, string nom, int ida, float sal)
    {
        codigo = cod;
        nome= nom;
        idade=ida;
        saldo = sal;
    }

};


#endif // _HPP_CLIENTE





