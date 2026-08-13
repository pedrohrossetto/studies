#include <iostream>
using namespace std;

#include "fila-dinamica.hpp"


int totalF(Fila *f)
{
    int cont = 0;
    NoFila* n = f->inicio;

    while(n)
    {
        cont++;
        n = n->prox;
    }


    return cont;
}

void removeK(Fila *f, int p, int k)
{
    if(p < 0 || p >= totalF(f) || k<=0)
        return;

    Fila aux;
    int contP=0;
    while(!vaziaF(f))
    {
        int val =  desenfileiraF(f);
        if(contP>=p && k>0)
            k--;
        else
            enfileiraF(&aux, val);

        contP++;
    }

    while(!vaziaF(&aux))
        enfileiraF(f, desenfileiraF(&aux));
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Fila f;
    int p, k;

    cout << "\n###Teste 1\n";
    enfileiraF(&f, 5);
    enfileiraF(&f, 10);
    enfileiraF(&f, 3);
    enfileiraF(&f, 1);
    enfileiraF(&f, 2);
    mostraF(&f);
    p=1; k=2;
    removeK(&f, p, k);
    mostraF(&f);
    destroiF(&f);

    cout << "\n###Teste 2\n";
    enfileiraF(&f, 5);
    enfileiraF(&f, 10);
    enfileiraF(&f, 3);
    enfileiraF(&f, 1);
    enfileiraF(&f, 2);
    mostraF(&f);
    p=2; k=2;
    removeK(&f, p, k);
    mostraF(&f);
    destroiF(&f);

    cout << "\n###Teste 3\n";
    enfileiraF(&f, 5);
    enfileiraF(&f, 10);
    enfileiraF(&f, 3);
    enfileiraF(&f, 1);
    enfileiraF(&f, 2);
    mostraF(&f);
    p=2; k=4;
    removeK(&f, p, k);
    mostraF(&f);
    destroiF(&f);


    cout << "\n###Teste 4\n";
    enfileiraF(&f, 5);
    enfileiraF(&f, 10);
    enfileiraF(&f, 3);
    enfileiraF(&f, 1);
    enfileiraF(&f, 2);
    mostraF(&f);
    p=0; k=1;
    removeK(&f, p, k);
    mostraF(&f);
    destroiF(&f);

    cout << "\n###Teste 5\n";
    enfileiraF(&f, 0);
    enfileiraF(&f, 5);
    enfileiraF(&f, 10);
    enfileiraF(&f, 3);
    enfileiraF(&f, 1);
    enfileiraF(&f, 2);
    enfileiraF(&f, 50);
    enfileiraF(&f, 100);
    mostraF(&f);
    p=3; k=5;
    removeK(&f, p, k);
    mostraF(&f);
    destroiF(&f);


    cout << "\n###Teste 6\n";
    enfileiraF(&f, 0);
    enfileiraF(&f, 5);
    enfileiraF(&f, 10);
    mostraF(&f);
    p=-1; k=5;
    removeK(&f, p, k);
    mostraF(&f);
    destroiF(&f);

    cout << "\n###Teste 7\n";
    enfileiraF(&f, 0);
    enfileiraF(&f, 5);
    enfileiraF(&f, 10);
    mostraF(&f);
    p=3; k=5;
    removeK(&f, p, k);
    mostraF(&f);
    destroiF(&f);


     cout << "\n###Teste 8\n";
    enfileiraF(&f, 0);
    enfileiraF(&f, 5);
    enfileiraF(&f, 10);
    mostraF(&f);
    p=1; k=0;
    removeK(&f, p, k);
    mostraF(&f);
    destroiF(&f);

    return EXIT_SUCCESS;

}//final do main

