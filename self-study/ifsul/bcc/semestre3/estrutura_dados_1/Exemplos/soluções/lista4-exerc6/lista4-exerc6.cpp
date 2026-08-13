#include <iostream>
using namespace std;

#include "pilha-dinamica.hpp"

void empilhaOrd(Pilha *p, Cliente c)
{
    Pilha aux;
    //passo 1: P -> AUX
    while(!vaziaP(p) && p->topo->dado.nome < c.nome)
        empilhaP(&aux, desempilhaP(p));

    //passo 2: empilhar o cliente
    empilhaP(p, c);

    //passo 3: AUX -> P
    while(!vaziaP(&aux))
        empilhaP(p, desempilhaP(&aux));

    destroiP(&aux);
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    string frase;



    Pilha p;


    empilhaOrd(&p, Cliente(1, "Michele", 20, 1500.20));
    empilhaOrd(&p, Cliente(2, "Carlos", 50, 2500.20));
    empilhaOrd(&p, Cliente(3, "Stefani", 10, 3500.20));
    empilhaOrd(&p, Cliente(7, "Ana Paula", 45, 11500.20));
    empilhaOrd(&p, Cliente(6, "Ana Claudia", 42, 10500.20));
    empilhaOrd(&p, Cliente(4, "Otávio", 30, 4500.20));
    empilhaOrd(&p, Cliente(5, "Thiago", 40, 5500.70));


    mostraP(&p);

    //desalocar memória
    destroiP(&p);


    return EXIT_SUCCESS;

}//final do main

