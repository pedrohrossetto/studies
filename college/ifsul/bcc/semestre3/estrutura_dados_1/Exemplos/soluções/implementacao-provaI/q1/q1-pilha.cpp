#include <iostream>
#include <string>
using namespace std;

struct Pessoa {
    string nome;
    float peso;
    float altura;
    Pessoa(){
        nome= "";
        peso = 0;
        altura = 0;
    }
    Pessoa(string n, int p, float a){
        nome= n;
        peso = p;
        altura = a;
    }
};


#include "pilha-dinamica.hpp"

void inverter(Pilha *p)
{
    Pilha aux1, aux2;

    while(!vaziaP(p))
        empilhaP(&aux1, desempilhaP(p));

    while(!vaziaP(&aux1))
        empilhaP(&aux2, desempilhaP(&aux1));

    while(!vaziaP(&aux2))
        empilhaP(p, desempilhaP(&aux2));
}

void separaIMC(Pilha *origem, Pilha *saudavel, Pilha *risco)
{
    while(!vaziaP(origem))
    {
        Pessoa p = desempilhaP(origem);
        float imc = p.peso / (p.altura * p.altura);
        //cout << imc << endl;
        if(imc>=18.5 &&  imc<=24.9)
            empilhaP(saudavel, p);
        else
            empilhaP(risco, p);
    }

    inverter(saudavel);
    inverter(risco);
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Pilha origem, saudavel, risco;

    empilhaP(&origem, Pessoa("Fulano", 60, 1.70));
    empilhaP(&origem, Pessoa("Ciclano", 70, 1.50));
    empilhaP(&origem, Pessoa("Beltrano", 80, 1.83));
    empilhaP(&origem, Pessoa("Beltrana", 100, 1.62));
    mostraP(&origem, "origem - ");
    mostraP(&saudavel, "saudavel - ");
    mostraP(&risco, "risco - ");
    separaIMC(&origem, &saudavel, &risco);
    cout << endl;
    mostraP(&origem, "origem - ");
    mostraP(&saudavel, "saudavel - ");
    mostraP(&risco, "risco - ");


    //desalocar memória
    destroiP(&origem);
    destroiP(&saudavel);
    destroiP(&risco);


    return EXIT_SUCCESS;

}//final do main

