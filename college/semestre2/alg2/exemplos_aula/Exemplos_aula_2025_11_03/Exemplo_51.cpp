#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

void leitura(int *pvet2);
void mostra(int **pvet2);

main()
{
    int *pvet = new int[10];

    leitura(pvet);
    mostra(&pvet);

    delete [] pvet;
}

void leitura(int *pvet2)
{
    srand(time(NULL));
    for(int *pi = new int(0);*pi < 10; (*pi)++)
    {
        *pvet2 = rand() % 50;
        pvet2++;
    }
}

void mostra(int **pvet2)
{
    cout << "Valores do vetor: " << endl;
    for(int *pi = new int(0);*pi < 10; (*pi)++)
    {
        cout << (*pvet2)[*pi] << ", ";
    }
}
