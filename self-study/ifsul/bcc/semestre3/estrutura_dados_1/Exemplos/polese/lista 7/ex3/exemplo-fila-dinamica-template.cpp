#include <iostream>
using namespace std;

#include "fila-dinamica-template.hpp"


//busca de pelo nome do cliente
void separaF(int N, Fila<int> *f1,Fila<int> *f2)
{
    Fila<int> aux;
    int cont = 0, i = 0, valor;
    while(!vaziaF(f1))
    {
        valor = desenfileiraF(f1);
        if(valor > N){
            enfileiraF(f2,valor);
        }else
        enfileiraF(&aux, valor);
    }
    while(!vaziaF(&aux))
    {
        enfileiraF(f1,desenfileiraF(&aux));
    }


}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    Fila<int> f1;
    Fila<int> f2;

    cout << "\n#######STRING#######\n";
    enfileiraF(&f1, 1);
    enfileiraF(&f1, 2);
    enfileiraF(&f1, 3);
    enfileiraF(&f1, 4);
    enfileiraF(&f1, 5);
    enfileiraF(&f1, 6);
    cout<<"fila 1:"<<endl;
    mostraF(&f1);
    cout<<"fila 2:"<<endl;
    mostraF(&f2);
    int N;
    cout<<"Deseja separar em qual numero: ";
    cin>>N;
    separaF(N,&f1,&f2);
    cout<<"fila 1:"<<endl;
    mostraF(&f1);
    cout<<"fila 2:"<<endl;
    mostraF(&f2);
    destroiF(&f1);
    destroiF(&f2);

    return EXIT_SUCCESS;

}//final do main

