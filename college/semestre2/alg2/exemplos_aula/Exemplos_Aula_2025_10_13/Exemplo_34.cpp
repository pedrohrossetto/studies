#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

#define TAM 5

void gera_valores(int *pv);
void mostra_valores(int *pv);

main()
{
    setlocale(LC_ALL, "Portuguese");
    int v[TAM];
    gera_valores(v);
    mostra_valores(&v[0]);
}

void gera_valores(int *pv)
{
    srand(time(NULL));
    int i, *pi = &i;

    cout << "Endereço inicial do ponteiro: " << pv << endl;
    for(*pi = 0; *pi < TAM; (*pi)++)
    {
        *(pv + (*pi)) = rand() % 10;
    }
    cout << "\nEndereço final do ponteiro: " << pv << endl;
}

void mostra_valores(int *pv)
{
    //exemplo com aritmética de ponteiro
    cout << "\nEndereco inicial: " << pv << endl;
    int i, *pi = &i;
    for(*pi = 0; *pi < TAM; (*pi)++)
    {
        cout << *(pv + (*pi)) << ", ";
    }

    cout << "\nEndereco final: " << pv << endl;
}
