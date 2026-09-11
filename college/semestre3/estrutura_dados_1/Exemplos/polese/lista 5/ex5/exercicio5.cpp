#include <iostream>
#include <string>

using namespace std;
#include "fila-dinamica-template.hpp"
#include "pilha-dinamica-template.hpp"

int main(void)
{

    Pilha<char> p1;
    Fila<char> f1;
    string teste;
    cout << "Insira um anagrama para ser testado: ";
    cin >> teste;

    for (int i = 0; i < teste.size(); i++)
    {
        enfileiraF(&f1, teste[i]);
    }

    mostraF(&f1);

    while (!vaziaF(&f1))
    {
        empilhaP(&p1, desenfileiraF(&f1));
    }

    cout << "Palavra: " << teste << endl;
    cout << "Seu inverso: ";

    while (!vaziaP(&p1))
    {
        cout << desempilhaP(&p1);
    }
}