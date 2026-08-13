#include <iostream>
#include <string>
using namespace std;
#include "pilha-dinamica-template.hpp"

void copiaP(Pilha<int> *p1, Pilha<int> *p2)
{
    Pilha<int> AUX;
    while (!vaziaP(p1))
    {
        int temp = desempilhaP(p1);
        empilhaP(&AUX, temp);
    }
    while (!vaziaP(&AUX))
    {
        int temp = desempilhaP(&AUX);
        empilhaP(p1, temp);
        empilhaP(p2, temp);
    }
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    cout << "\n#######INT#######\n";
    Pilha<int> p1;
    Pilha<int> p2;

    int tam;
    cout << "Quantos valores inteiros deseja inserir: ";
    cin >> tam;
    cout << endl;
    for (int i = 0; i < tam; i++)
    {
        int emp;
        cout << "insira o valor[" << i + 1 << "]: ";
        cin >> emp;
        empilhaP(&p1, emp);
    }
    cout << "antes de copiar:" << endl;
    mostraP(&p1);
    mostraP(&p2);

    copiaP(&p1, &p2);
    cout << "depois de copiar:" << endl;

    mostraP(&p1);
    mostraP(&p2);

    return EXIT_SUCCESS;

} // final do main
