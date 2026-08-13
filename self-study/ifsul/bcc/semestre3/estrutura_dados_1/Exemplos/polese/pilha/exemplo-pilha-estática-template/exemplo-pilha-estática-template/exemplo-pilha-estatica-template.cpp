#include <iostream>
#include <string>
using namespace std;

#include "cliente.hpp"
#include "pilha-estatica-template.hpp"


void mostraP(Pilha<Cliente> *p, string nome="")
{

    cout << "PILHA: " << nome << endl;
    cout << "TAM: " << p->tam << endl;
    cout << "TOPO: " << p->topo << endl;
    if(vaziaP(p) == false)
    {
        cout << "------------------------" << endl;
        for(int i = p->topo; i > p->base; i--)
        {
            cout << i << "- " << p->dados[i].nome << ", " << p->dados[i].idade << endl;
            cout << "------------------------" << endl;
        }
    }
    cout << endl;
    fflush(stdout);
}

//busca de pelo nome do cliente
bool buscaP(Pilha<Cliente> *p, string nome)
{

   for(int i = p->topo ; i > p->base; i--)
   {
       if (p->dados[i].nome == nome)
          return true;
   }
   return false;

}

//busca de pela idade
bool buscaP(Pilha<Cliente> *p, int idade)
{

   for(int i = p->topo ; i > p->base; i--)
   {
       if (p->dados[i].idade == idade)
          return true;
   }
   return false;

}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    cout << "\n#######INT#######\n";
    Pilha<int> p1;
    inicializaP(&p1, 10);
    empilhaP(&p1, 100);
    empilhaP(&p1, 50);
    empilhaP(&p1, 20);
    empilhaP(&p1, 10);
    mostraP(&p1, "tipo int");
    destroiP(&p1);

    cout << "\n#######FLOAT#######\n";
    Pilha<float> p2;
    inicializaP(&p2, 10);

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
    inicializaP(&p3, 10);
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
    inicializaP(&p4, 10);
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

