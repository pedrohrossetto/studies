#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;
void gerar(int *pvet);

main()
{
   setlocale(LC_ALL,"portuguese");
   int *p = new int[5];
   srand(time(NULL));
   gerar(p);

}

void gerar(int *pvet)
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

    for (*i = 0; *i < 5; (*i)++)
    {
        do
        {
            *aux = rand() % 5 + 1;
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
    pvet-=5;
    cout << "Vetor: ";
    for(*i=0;*i<5;(*i)++)
    {
        cout << *pvet << "\t";
        pvet++;
    }
    cout << endl;
}
