#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>

using namespace std;
void ler_arquivo(int *px, int *c);
void mostrar_vetor(int *p, int *c);

main()
{
    setlocale(LC_ALL,"Portuguese");
    int *px = new int[10];
    int *cont = new int(0);
    ler_arquivo(px, cont);
    mostrar_vetor(px, cont);
}

void ler_arquivo(int *px, int *c)
{
    ifstream ler("exemplo_58.txt");

    if(ler.is_open())
    {

        while(!ler.eof())
        {
            ler >> *px;
            (*c)++;
            px++;
            if(*c >= 10)
                break;
        }
    }
    ler.close();
}

void mostrar_vetor(int *p, int *c)
{
    for(int *pi = new int(0); *pi < *c; (*pi)++)
    {
        cout << *p << ", ";
        p++;
    }
}

