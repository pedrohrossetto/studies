#include <iostream>
using namespace std;

#include "pilha-dinamica.hpp"


int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Pilha p1;
    int valor;
    bool resultado;
    int x = 0;

    while(x !=111)
    {
        cout<<"empilhe valores(111 para sair): ";
        cin>>x;
        if(x == 111){break;}
        empilhaP(&p1, x);
    }

    mostraP(&p1);
    cout<<"media: "<< mediaP(&p1)<<endl;
    destroiP(&p1);
    mostraP(&p1);



    return EXIT_SUCCESS;

}//final do main

