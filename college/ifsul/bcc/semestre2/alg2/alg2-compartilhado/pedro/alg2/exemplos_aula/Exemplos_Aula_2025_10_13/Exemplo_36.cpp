#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

#define TAM 5

void gera_valores(int (*pv)[TAM]);
void mostra_valores(int (*pv)[TAM]);

main()
{
    setlocale(LC_ALL, "Portuguese");
    int m[TAM][TAM];
    srand(time(NULL));
    gera_valores(m);
    mostra_valores(m);
}

void gera_valores(int (*pv)[TAM])
{
    int l, c, *pl, *pc;
    pl = &l;
    pc = &c;
    for(*pl = 0; *pl < TAM; (*pl)++)
    {
        for(*pc = 0; *pc < TAM; (*pc)++)
        {
            pv[*pl][*pc] = rand() % 100 + 1;
        }
    }
}

void mostra_valores(int (*pv)[TAM])
{
    int l, c, *pl, *pc;
    pl = &l;
    pc = &c;
    for(*pl = 0; *pl < TAM; (*pl)++)
    {
        for(*pc = 0; *pc < TAM; (*pc)++)
        {
            cout << pv[*pl][*pc] << "\t";
        }
        cout << endl;
    }
}
