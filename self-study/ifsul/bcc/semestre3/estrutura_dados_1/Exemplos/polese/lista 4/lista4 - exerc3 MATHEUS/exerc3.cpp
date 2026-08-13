#include <iostream>
#include <string>
using namespace std;
#include "pilha-dinamica-template.hpp"

void ordenaP(Pilha<int> *ORD, Pilha<int> *AUX)
{
    while (!vaziaP(ORD))
    {
        int temp = desempilhaP(ORD);

        while (!vaziaP(AUX) && espiaP(AUX) > temp)
        {
            empilhaP(ORD, desempilhaP(AUX));
        }
        empilhaP(AUX, temp);
    }
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    cout << "\n#######INT#######\n";
    Pilha<int> AUX;
    Pilha<int> ORD;

    int tam;
    cout << "Quantos valores inteiros deseja inserir: ";
    cin >> tam;
    cout << endl;
    for (int i = 0; i < tam; i++)
    {
        int emp;
        cout << "insira o valor[" << i + 1 << "]: ";
        cin >> emp;
        empilhaP(&ORD, emp);
    }
    mostraP(&ORD);

    ordenaP(&ORD, &AUX);

    mostraP(&AUX);

    destroiP(&AUX);
    destroiP(&ORD);

    return EXIT_SUCCESS;

} // final do main
