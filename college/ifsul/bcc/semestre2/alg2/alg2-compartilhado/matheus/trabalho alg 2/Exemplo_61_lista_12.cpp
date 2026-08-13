#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<cstring>


using namespace std;
int gerar(int *pvet);
void mostrar(int *pvet);
int ordenar (int *pvet);
main()
{
    setlocale(LC_ALL,"portuguese");
    int *p = new int[20];
    srand(time(NULL));
    cout<<p<<endl;
    gerar(p);
    cout<<p<<endl;
    mostrar(p);
    ordenar(p);
}

int gerar(int *pvet)
{
    int *contV = new int();
    *contV = 0;
    int *i = new int();
    int *j = new int();
    int *aux = new int();
    bool *achou = new bool();
    int *inicio = new int();
    inicio = pvet;
    int *percorre = new int();

    for (*i = 0; *i < 21; (*i)++)
    {
        do
        {
            *aux = rand() % 100 + 1;
            *achou = false;
            percorre = inicio;

            for(*j = 0; *j < *contV; (*j)++)
            {
                if(*percorre == *aux)
                {
                    *achou = true;
                    //cout << "Achou duplicado " << *percorre << endl;
                    break;
                }
                percorre++;
            }
            if(*achou == false)
            {
                *pvet  = *aux;
                pvet++;
                (*contV)++;
            }
        }
        while(*achou == true);
    }
}
void mostrar (int *pvet)
{
    cout << "Vetor: ";
    for(    int *i = new int(0); *i<20; (*i)++)
    {
        cout << *pvet << "\t";
        pvet++;
    }
    cout << endl;
}
int ordenar (int *pvet)
{
    int *aux = new int(0);

    for(int *i = new int(0); *i<20; (*i)++)
    {
        for(int *j = new int(0); *j<20; (*j)++)
            if (*(pvet + *i)<*(pvet + *j))
            {
                *aux = *(pvet + *i);
                *(pvet + *i) = *(pvet + *j);
                *(pvet + *j) = *aux;
            }
    }

    ofstream escreve("exemplo61.txt");
    for(    int *i = new int(0); *i<20; (*i)++)
    {
        escreve <<"execucao "<<*i+1<<" "<< (pvet) << " - " <<*(pvet) << "\n";
        pvet++;
    }
    escreve.close();
    cout <<"tudo certo"<< endl;

}
