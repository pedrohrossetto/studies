#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;
//void leitura(int (*pm)[3]);
void leitura2(int (*pm)[3]);
//void mostra(int (*pm)[3]);
void mostra2(int (*pm)[3]);


main()
{
    int m[3][3];
    srand(time(NULL));
    leitura2(m);
    mostra2(m);
}

/*void leitura(int (*pm)[3])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            pm[i][j] = rand() % 20;
        }
    }
}*/


void leitura2(int (*pm)[3])
{
    int *pmat = *pm;
    for(int *i = new int(0); *i < 3; (*i)++)
    {
        for(int *j = new int(0); *j < 3; (*j)++)
        {

            *pmat = rand() % 20;
            pmat++;
        }
    }
}


/*void mostra(int (*pm)[3])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << pm[i][j] << "\t";
        }
        cout << endl;
    }
}*/

void mostra2(int (*pm)[3])
{
    int *pmat = *pm, *cont = new int(0);
    for(int *i = new int(0); *i < 9; (*i)++)
    {
        cout << *pmat << "\t";
        pmat++;
        (*cont)++;
        if(*cont == 3)
        {
            cout << endl;
            *cont = 0;
        }
    }
}


