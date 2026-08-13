#include <iostream>
using namespace std;

#include "pilha.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Pilha p1;
    int tamPilha, valor , v;
    bool resultado;
    tamPilha=5;//cria pilha P com tamanho fixo de 5 posições

    inicializaP(&p1, tamPilha);
    resultado = verificaInicializacaoP(&p1); //verifica de a pilha foi inicializada
    if(resultado == true)
        cout << "Pilha P criada com sucesso!"<<endl;
    else
        cout << "Erro em criar pilha P!\n"<<endl;


//insere 5 valores na pilha
    empilhaP(&p1, 10);
    empilhaP(&p1, 11);
    empilhaP(&p1, 12);
    empilhaP(&p1, 13);
    empilhaP(&p1, 14);

    int x;
    float media;
    x = MaiorP(&p1);
    cout<<x<<endl;

    x = MenorP(&p1);
    cout<<x<<endl;

    media = MediaP(&p1);
    cout<<media<<endl;

}

