#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

const int LIN = 3;
const int COL = 3;

void gerar(int (*pmat)[COL]);
void mostrar(int (*pmat)[COL]);

main()
{
    setlocale(LC_ALL,"portuguese");
    int mat[LIN][COL];

    srand(time(NULL));
    gerar(mat);
    mostrar(mat);
}

void gerar(int (*pmat)[COL])
{
    int *plin = new int(), *pcol = new int(), *pcont = new int();
    int *paux = new int(), *pconta_gerados = new int(0);
    int *pi = new int(), *pj = new int();
    bool *pexiste = new bool();
    for(*plin = 0; *plin < LIN; (*plin)++)
    {
        for(*pcol = 0; *pcol < COL; (*pcol)++)
        {
            *paux = rand() % 9 + 1;
            (*pconta_gerados)++;
            if(*pconta_gerados == 1)
            {
                pmat[*plin][*pcol] = *paux;
            }
            else
            {
                *pexiste = false;
                *pcont = 1;
                *pi = 0;
                *pj = 0;
                while(*pcont < *pconta_gerados)
                {
                    if(pmat[*pi][*pj] == *paux)
                    {
                        //cout << "Achou repetido: " << aux << endl;
                        *pexiste = true;
                        (*pconta_gerados)--;
                        break;
                    }
                    (*pj)++;
                    if(*pj == COL)
                    {
                        (*pi)++;
                        *pj = 0;
                    }
                    (*pcont)++;
                }

                if(*pexiste == false)
                {
                    pmat[*plin][*pcol] = *paux;
                }
                else
                {
                    if(*pcol == 0)
                    {
                        (*plin)--;
                        *pcol = COL;
                    }
                    else
                        (*pcol)--;
                }
            }
        }
    }

    delete plin;
    delete pcol;
    delete pcont;
    delete paux;
    delete pconta_gerados;
    delete pi;
    delete pj;
    delete pexiste;
}

void mostrar(int (*pmat)[COL])
{
    int *plin = new int(), *pcol = new int();
    cout << "\n\nMatriz gerada sem valores repetidos: " << endl;
    for(*plin = 0; *plin < LIN; (*plin)++)
    {
        for(*pcol = 0; *pcol < COL; (*pcol)++)
        {
            cout << pmat[*plin][*pcol] << "\t";
        }
        cout << endl;
    }
    delete plin;
    delete pcol;
}



