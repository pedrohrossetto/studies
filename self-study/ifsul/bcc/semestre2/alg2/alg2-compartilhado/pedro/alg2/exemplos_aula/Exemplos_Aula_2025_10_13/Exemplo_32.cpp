#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<windows.h>

using namespace std;

main()
{
    int n1, n2, *pn1, *pn2;

    pn1 = &n1;
    pn2 = &n2;

    cout << "Informe o valor 1: ";
    cin >> *pn1;

    cout << "Informe o valor 2: ";
    cin >> *pn2;

    cout << "Valor 1: " << *pn1 << endl;
    cout << "Valor 2: " << *pn2 << endl;
    cout << "Soma: " << *pn1 + *pn2 << endl;

    cout << "Endereço da variável n1: " << &n1 << endl;
    cout << "Endereço do ponteiro pn1: " << &pn1 << endl;
    cout << "Endereço para onde o ponteiro pn1 aponta: " << pn1 << endl;
    cout << "Valor contido no endereço onde o ponteiro aponta: " << *pn1 << endl;
    cout << "Endereço da variável n2: " << &n2 << endl;
    pn1 = &n2;
    cout << "Endereço para onde o ponteiro pn1 aponta: " << pn1 << endl;
    cout << "Valor contido no endereço onde o ponteiro aponta: " << *pn1 << endl;


}
