#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;
void ajuste(int *x, int *i);

main()
{
    setlocale(LC_ALL, "Portuguese");
    int n1, n2, soma, x, *pn1, *pn2, *psoma = &soma, *px = &x;
    pn1 = &n1;
    pn2 = &n2;

    cout << "Informe o valor 1: ";
    cin >> *pn1;
    fflush(stdin);

    cout << "Informe o valor 2: ";
    cin >> *pn2;
    fflush(stdin);

    cout << "Valor do N1: " << *pn1 << endl;
    cout << "Valor do N2: " << *pn2 << endl;

    *psoma = *pn1 + *pn2;

    cout << "Soma de " << *pn1 << " + " << *pn2 << " = " << *psoma << endl;


    cout << "Endereço de memoria da variável n1: " << &n1 << endl;
    cout << "Endereço de memoria do ponteiro pn1: " << &pn1 << endl;
    cout << "Endereço de memoria para onde pn1 aponta: " << pn1 << endl;
    cout << "Valor contido no endereço apontado pelo ponteiro pn1: " << *pn1 << endl;

    for(*px = *pn1 + 1;*px < *pn2; (*px)++)
    {
        cout << *px << ", ";
    }


}


