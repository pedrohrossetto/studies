#include <iostream>
using namespace std;

#include "pilha-dinamica.hpp"

void desempilhaTodosMostra(Pilha *p)
{
    while(!vaziaP(p))
    {
        cout << desempilhaP(p);
    }
    cout << " "; //para separar as palavras;
}


int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    string frase;

    cout << "Informe uma frase: ";
    getline(cin, frase);


    Pilha p;

    for (int i=0; i<frase.size(); i++)
    {
        if(frase[i]!=' ')
            empilhaP(&p, frase[i]);


        if(frase[i]==' ' || i==frase.size()-1)
        {
            desempilhaTodosMostra(&p);
        }
    }



    //desalocar memória
    destroiP(&p);


    return EXIT_SUCCESS;

}//final do main

