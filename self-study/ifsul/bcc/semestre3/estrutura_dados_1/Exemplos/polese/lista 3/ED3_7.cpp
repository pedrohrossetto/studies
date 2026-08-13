#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#include "pilha.hpp"
bool bal();

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    bal();

}

bool bal()
{
    string entrada;
    cout << "insira sua expressão: "<<endl;
    cin>>entrada;

    Pilha p1;
    bool resultado;

    inicializaP(&p1, entrada.size());
    resultado = verificaInicializacaoP(&p1); //verifica de a pilha foi inicializada
    for (int i=0; i<entrada.size(); i++)
    {
        if(entrada[i] == '(')
        {
            empilhaP(&p1,1);
        }
        else if (entrada[i] == ')')
            if(vaziaP(&p1) == true)
            {
                cout<<"Pilha desbalanceada"<<endl;
                return false;
            }
            else
                desempilhaP(&p1);
    }
    if(vaziaP(&p1) == true)
    {
        cout<<"Pilha balanceada"<<endl;
        return true;
    }

}
