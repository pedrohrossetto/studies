#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "pilha-dinamica-template.hpp"

int main(void)
{
    Pilha<string> p1;
    Pilha<string> p2;

    setlocale(LC_ALL, "Portuguese");
    stringstream strBuffer;
    string frase, palavra = "";

    cout << "Digite uma frase:";
    getline(cin, frase);

    strBuffer = stringstream(frase);

    int cont_palavras = 0;
    while (getline(strBuffer, palavra, ' '))
    {

        int j = 0;
        string aux;
        aux = palavra;
        while (j < palavra.size())
        {
            aux[j] = palavra[(palavra.size() - 1) - j];
            j++;
        }
        palavra = aux;
        empilhaP(&p1, palavra);
    }
    while (!vaziaP(&p1))
    {
        empilhaP(&p2, desempilhaP(&p1));
    }

     while (!vaziaP(&p2))
    {
        cout<< desempilhaP(&p2)<<" ";
    }

    return EXIT_SUCCESS;

} // final do main
