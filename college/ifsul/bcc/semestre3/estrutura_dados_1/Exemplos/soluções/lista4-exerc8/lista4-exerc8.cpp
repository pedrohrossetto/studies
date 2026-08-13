#include <iostream>
using namespace std;

#include "pilha-dinamica.hpp"

bool igualP(Pilha *p1, Pilha *p2)
{
    NoPilha *n1, *n2;
    n1 = p1->topo;
    n2 = p2->topo;

    while(n1!=NULL && n2!=NULL)
    {
        if(n1->dado != n2->dado)
            return false;

        n1 = n1->prox;
        n2 = n2->prox;
    }

    if(n1!=NULL || n2!=NULL)
        return false;

    return true;

}
void inverteP(Pilha *p)
{
   Pilha aux1, aux2;

   while(!vaziaP(p))
        empilhaP(&aux1, desempilhaP(p));

   while(!vaziaP(&aux1))
        empilhaP(&aux2, desempilhaP(&aux1));

   while(!vaziaP(&aux2))
        empilhaP(p, desempilhaP(&aux2));

    destroiP(&aux1);
    destroiP(&aux2);
}

int tamanhoP(Pilha *p)
{
    NoPilha *n;
    int cont=0;
    n = p->topo;
    while(n!=NULL )
    {
        n = n->prox;
        cont++;
    }

    return cont;
}
Pilha copiaIntervalo(Pilha *p, int i, int f)
{
    Pilha aux;

    if(i<0 || f<0 || f<i || f>=tamanhoP(p))
        return aux; //aux está vazio

    int cont=0;
    NoPilha *n;
    n = p->topo;

    while(n!=NULL && cont<=f)
    {

        if(cont>=i && cont<=f)
            empilhaP(&aux, n->dado);
        n = n->prox;
        cont++;
    }


    inverteP(&aux);

    return aux;
}

bool verificaIntervalosInversos(Pilha *p1, Pilha *p2, int i1, int f1, int i2, int f2)
{
    Pilha pInt1 = copiaIntervalo(p1, i1, f1);
    Pilha pInt2 = copiaIntervalo(p2, i2, f2);

    mostraP(&pInt1, "pInt1");
    mostraP(&pInt2, "pInt2");
    inverteP(&pInt2); //inverteu pInt2




    if(igualP(&pInt1, &pInt2) == true)
        return true;
    else
        return false;
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Pilha p1;
    empilhaP(&p1, 5);
    empilhaP(&p1, 10);
    empilhaP(&p1, 20);
    empilhaP(&p1, -1);



    Pilha p2;
    empilhaP(&p2, 5);
    empilhaP(&p2, -1);
    empilhaP(&p2, 20);
    empilhaP(&p2, 10);
    mostraP(&p1, "p1");
    mostraP(&p2, "p2");

    int i1, f1, i2, f2;
    i1 = 1;
    f1 = 2;
    i2 = 0;
    f2 = 1;
    if(verificaIntervalosInversos(&p1, &p2, i1, f1, i2, f2) == true)
    {
        cout << "Intervalos P1[" << i1<<"-" <<f1;
        cout <<"] e P2["<<i2<<"-" <<f2<<"] inversos? SIM\n";
    }
    else{
        cout << "Intervalos P1[" << i1<<"-" <<f1;
        cout <<"] e P2["<<i2<<"-" <<f2<<"] inversos? NAO\n";
    }


    //desalocar memória
    destroiP(&p1);


    return EXIT_SUCCESS;

}//final do main

