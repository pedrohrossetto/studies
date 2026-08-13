#include <iostream>
using namespace std;

#include "pilha-dinamica-template.hpp"

void imprimeInverso(Pilha<int> *p)
{
    // Caso base: se a pilha acabar, para de chamar a si mesma
    if (vaziaP(p))
    {
        return;
    }
    // Tira o elemento do topo e guarda na memória da função (na pilha do sistema)
    int temp = desempilhaP(p);
    // Chama a função recursivamente para o próximo elemento
    imprimeInverso(p);
    // No caminho de "volta" da recursão, a impressão acontece
    // Isso garante que o elemento do fundo seja impresso primeiro
    cout << temp << " ";
    // Importante: Empilha de volta para manter a pilha original intacta
    empilhaP(p, temp);
}

int main()
{
    Pilha<int> p;
    empilhaP(&p, 10);
    empilhaP(&p, 20);
    empilhaP(&p, 30);

    cout << "Pilha original (Topo para Base): ";
    mostraP(&p);

    cout << "Impressao Inversa (Base para Topo): ";
    imprimeInverso(&p);
    cout << endl;

    return 0;
}