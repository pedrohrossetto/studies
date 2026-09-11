#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>

using namespace std;
void tabuada (int *p);

main()
{
    system("chcp 1252 > nul");
    int *px = new int();
    cout << "Informe um valor qualquer: ";
    cin >> *px;

    tabuada(px);
    delete px;
}

void tabuada (int *p)
{
    cout << "Tabuado do " << *p << endl;
    int *tab = new int();
    for(int *i = new int(1); *i <= 10; (*i)++)
    {
        *tab = *i * *p;
        cout << *i << " * " << *p << " = " << *tab << endl;
    }
    delete tab;
}
