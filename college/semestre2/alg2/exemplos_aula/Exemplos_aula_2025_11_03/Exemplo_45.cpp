#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;
void mostra_por_letra(char *pnome);
void mostra_tudo(char *pnome);
void mostra_as_duas_coisas(char *pnome);

main()
{
    string nome;

    cout << "Informe seu nome: ";
    getline(cin, nome);
    fflush(stdin);

    mostra_por_letra(&nome[0]);
    mostra_tudo(&nome[0]);
    mostra_as_duas_coisas(&nome[0]);
}

void mostra_por_letra(char *pnome)
{
    cout << "Mostra o texto por letra: " << endl;
    while(*pnome)
    {
        cout << *pnome << ", ";
        pnome++;
    }
}

void mostra_tudo(char *pnome)
{
    cout << "\n\nMostra todo o conteúdo a partir da posição atual: " << endl;
    cout << pnome << endl;
}

void mostra_as_duas_coisas(char *pnome)
{
    cout << "\n\nMostra o valor atual e todo o conteúdo a partir da posição atual: " << endl;
    while(*pnome)
    {
        cout << *pnome << " - ";
        cout << pnome << endl;
        pnome++;
    }
}
