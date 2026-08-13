#include <iostream>
using namespace std;

#include "pilha.hpp"


int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Pilha p1;
    Pilha aux;
    int tamPilha, valor,v;
    bool resultado;
    tamPilha=5;//cria pilha P com tamanho fixo de 5 posições



    inicializaP(&p1, tamPilha);
    resultado = verificaInicializacaoP(&p1); //verifica de a pilha foi inicializada
    if(resultado == true)
        cout << "Pilha P criada com sucesso!"<<endl;
    else
        cout << "Erro em criar pilha P!\n"<<endl;


    inicializaP(&aux, tamPilha);

    resultado = verificaInicializacaoP(&aux); //verifica de a pilha foi inicializada
    if(resultado == true)
        cout << "Pilha AUX criada com sucesso!";
    else
        cout << "Erro em criar pilha AUX!\n";


//insere 5 valores na pilha
    empilhaP(&p1, 10);
    empilhaP(&p1, 11);
    empilhaP(&p1, 12);
    empilhaP(&p1, 13);
    empilhaP(&p1, 14);

    resultado= vaziaP(&p1);
    if(resultado == true)
        cout << " ERRO Pilha P não preenchida!";
    else
        cout << "Pilha P preenchida!\n";

    cout<<"Pilha P: "<<endl;
    mostraP(&p1);
    cout<<"Pilha AUX: "<<endl;
    mostraP(&aux);
//passa topo para pilha auxiliar
    bool achou;
    int topo;
    cout<<"busque um valor que esta presente na pilha P: ";
    cin>>v;


    for(int i=0; i<tamPilha; i++)
    {
        topo = desempilhaP(&p1); ///pop
        if(topo == v)
        {
            achou = true;
            cout<<"O numero "<<topo<<" esta na pilha!!!\nDevolvendo valores para pilha aux!!!\n";
            break;
        }
        empilhaP(&aux, topo);
        if(vaziaP(&p1)==true){
            cout<<"O valor nao esta na pilha P\n";
            break;
        }
    }
    cout<<"Pilha P: "<<endl;
    mostraP(&p1);
    cout<<"Pilha AUX: "<<endl;
    mostraP(&aux);

    while(vaziaP(&aux)!=true){
        topo = desempilhaP(&aux); ///pop
        empilhaP(&p1, topo);
        if(vaziaP(&aux)==true){
            cout<<"Pilha aux esta vazia\n";
            break;
        }
    }

    cout<<"Pilha P: "<<endl;
    mostraP(&p1);
    cout<<"Pilha AUX: "<<endl;
    mostraP(&aux);
}
