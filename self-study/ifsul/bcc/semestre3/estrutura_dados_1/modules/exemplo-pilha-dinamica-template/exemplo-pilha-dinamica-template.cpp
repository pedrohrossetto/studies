#include <iostream>
#include <string>
using namespace std;

#include "cliente.hpp"
#include "pilha-dinamica-template.hpp"

void mostraP(Pilha<Cliente> *p, string nome="")
{

    cout << "PILHA: " << nome << endl;
    cout << "TOPO: " << p->topo << endl;
    cout << "------------------------" << endl;
    NoPilha<Cliente> *no = p->topo;
    while (no != NULL)
    {
        cout << no->dado.nome << ", " << no->dado.idade << endl;
        cout << "------------------------" << endl;
        no = no->prox;
    }

    cout << endl;
    fflush(stdout);
}

//busca de pelo nome do cliente
bool buscaP(Pilha<Cliente> *p, string nome)
{

    NoPilha<Cliente> *no = p->topo;
    while (no != NULL)
    {
        if(no->dado.nome == nome)
            return true;

        no = no->prox;
    }

    return false;
}

//busca de pela idade
bool buscaP(Pilha<Cliente> *p, int idade)
{

    NoPilha<Cliente> *no = p->topo;
    while (no != NULL)
    {
        if(no->dado.idade == idade)
            return true;

        no = no->prox;
    }

    return false;

}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    cout << "\n#######INT#######\n";
    Pilha<int> p1;
    empilhaP(&p1, 100);
    empilhaP(&p1, 50);
    empilhaP(&p1, 20);
    empilhaP(&p1, 10);
    mostraP(&p1, "tipo int");
    destroiP(&p1);

    cout << "\n#######FLOAT#######\n";
    Pilha<float> p2;

    if(vaziaP(&p2))
        cout << "Pilha<float> vazia!\n";
    else
        cout << "Pilha<float> não está vazia.\n";

    empilhaP(&p2, 10.5f);
    empilhaP(&p2, 50.6f);
    empilhaP(&p2, 20.2f);
    empilhaP(&p2, 10.3f);
    mostraP(&p2, "tipo float");
    cout << "Espia pilha<float>: " << espiaP(&p2) << endl;
    cout << "Busca pilha<float> valor 10.5: " << buscaP(&p2, 10.5f) << endl;
    float x = desempilhaP(&p2);
    cout << "Valor x: " << x << endl;
    mostraP(&p2, "tipo float");
    destroiP(&p2);

    cout << "\n#######DOUBLE#######\n";
    Pilha<double> p3;
    empilhaP(&p3, 10.5);
    empilhaP(&p3, 50.6);
    empilhaP(&p3, 20.2);
    empilhaP(&p3, 10.3);
    mostraP(&p3, "tipo double");
    double y = desempilhaP(&p3);
    cout << "Valor y: " << y << endl;
    destroiP(&p3);


    cout << "\n#######CLIENTE#######\n";
    Pilha<Cliente> p4;
    empilhaP(&p4, Cliente("Fulano", 10));
    empilhaP(&p4, Cliente("Ciclano", 20));
    mostraP(&p4, "tipo Cliente");
    cout << "Busca pilha<Cliente> nome Fulano " << buscaP(&p4, "Fulano") << endl;
    cout << "Busca pilha<Cliente> nome Joao " << buscaP(&p4, "Joao") << endl;
    cout << "Busca pilha<Cliente> idade 20 " << buscaP(&p4, 20) << endl;
    cout << "Busca pilha<Cliente> idade 50 " << buscaP(&p4, 50) << endl;
    Cliente c = desempilhaP(&p4);
    cout << "Cliente c: " << c.nome << ", " << c.idade << endl;
    destroiP(&p4);


    return EXIT_SUCCESS;

}//final do main

