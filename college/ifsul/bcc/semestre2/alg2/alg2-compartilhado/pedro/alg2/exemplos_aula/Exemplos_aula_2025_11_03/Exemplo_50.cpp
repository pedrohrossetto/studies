#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

const int LIN = 3;
const int COL = 3;

void gerar(int (*pmat)[COL]);
void mostrar(int (*pmat)[COL]);
//void mostrar_2(int (*pmat)[COL]);
void mostrar_2(int pmat[][COL]);

main()
{
    setlocale(LC_ALL,"portuguese");
    int mat[LIN][COL];

    srand(time(NULL));
    gerar(mat);
    mostrar(mat);
    //cout << endl << mat << endl;
    mostrar_2(mat);

}

void gerar(int (*pmat)[COL])
{
    int lin, *plin = &lin, col, *pcol = &col, cont, *pcont = &cont;
    int aux, *paux = &aux, conta_gerados = 0, *pconta_gerados = &conta_gerados;
    int i, *pi = &i, j, *pj = &j;
    bool existe = false, *pexiste = &existe;
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
}

void mostrar(int (*pmat)[COL])
{
    int lin, *plin = &lin, col, *pcol = &col;
    cout << "\n\nMatriz gerada sem valores repetidos: " << endl;
    for(*plin = 0; *plin < LIN; (*plin)++)
    {
        for(*pcol = 0; *pcol < COL; (*pcol)++)
        {
            cout << &pmat[*plin][*pcol] << " -> " << pmat[*plin][*pcol] << "\t";
        }
        cout << endl;
    }
}

void mostrar_2(int (*pmat)[COL])
{
    //cout << *pmat << endl;
    //cout << pmat[0] << endl;
    int *p = *pmat;
    int lin, *plin = &lin, col, *pcol = &col;
    cout << "\n\nMatriz gerada sem valores repetidos com aritmética: " << endl;
    for(*plin = 0; *plin < LIN; (*plin)++)
    {
        for(*pcol = 0; *pcol < COL; (*pcol)++)
        {
            cout << p << " -> " << *p<< "\t";
            p++;
        }
        cout << endl;
    }
}



