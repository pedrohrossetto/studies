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

   delete []p;

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
                if(*(percorre + *j) == *aux)
                {
                    *achou = true;
                    break;
                }
            }
            if(*achou == false)
            {
                *(pvet + *i) = *aux;
                (*contV)++;
            }
        }
        while(*achou == true);
    }
    cout << "Vetor: ";
    for(*i = 0; *i < 5;(*i)++)
    {
        cout << *(pvet + *i) << "\t";
    }
    cout << endl;
}
