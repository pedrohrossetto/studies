#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

void ler_valores(int *pvet, int *ptam);
void mostra_valores(int *pvet, int *ptam);

main()
{
    setlocale(LC_ALL,"Portuguese");
    int *tam = new int;
    cout << "Informe o tamanho do vetor: ";
    cin >> *tam;
    int *vet = new int[*tam];
    cout << "Endereço inicial do vetor original: " << vet << endl;
    ler_valores(vet, tam);
    mostra_valores(vet, tam);
    delete []vet;
    delete tam;
}

void ler_valores(int *pvet, int *ptam)
{
    cout << "Endereço inicial do ponteiro pvet na função: " << pvet << endl;
    for(int *pi = new int(0); *pi < *ptam; (*pi)++)
    {
        *pvet = rand() % 50;
        pvet++; //incrementa o endereço de memória aritmética de ponteiro
    }
    cout << "Endereço final do ponteiro pvet na função: " << pvet << endl;
}

void mostra_valores(int *pvet, int *ptam)
{
    for(int *pi = new int(0); *pi < *ptam; (*pi)++)
    {
        cout << *pvet << ", ";
        pvet++;
    }
}
