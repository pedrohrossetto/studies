#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cmath>

using namespace std;

struct Cell {
    int* pNum;
    int* pMarcado;
};

void geraCartela(Cell**, int*, int*, int*, int*);
void mostraCartela(Cell**, int*, int*, char*);
void sorteia(Cell**, Cell**, int*, int*, int*, int*, int*, int*);
int* verifica(Cell**, int*, int*);
void l(Cell***, Cell***, int*, int*);

int main() {
    int* R = new int; *R = 5;
    int* C = new int; *C = 5;
    
    int* pLimite = new int; *pLimite = 75;
    
    int* pSorteados = new int[*pLimite + 1];
    int* pi = new int;
    for (*pi = 0; *pi <= *pLimite; (*pi)++) {
        *(pSorteados + *pi) = 0;
    }

    Cell** pCartelaA = new Cell*[*R];
    Cell** pCartelaB = new Cell*[*R];
    
    for (*pi = 0; *pi < *R; (*pi)++) {
        *(pCartelaA + *pi) = new Cell[*C];
        *(pCartelaB + *pi) = new Cell[*C];
    }

    int* semente = new int; *semente = 1; 
    srand(*semente);
    delete semente;
    
    int* pZero = new int; *pZero = 0;
    geraCartela(pCartelaA, R, C, pSorteados, pZero);
    geraCartela(pCartelaB, R, C, pSorteados, pZero);
    
    char* pNomeA = new char[2]; pNomeA[0] = 'A'; pNomeA[1] = '\0';
    char* pNomeB = new char[2]; pNomeB[0] = 'B'; pNomeB[1] = '\0';
    
    mostraCartela(pCartelaA, R, C, pNomeA);
    mostraCartela(pCartelaB, R, C, pNomeB);

    int* pGanhador = new int; *pGanhador = 0;
    int* pTotalSorteado = new int; *pTotalSorteado = 0;
    
    while (*pGanhador == 0 && *pTotalSorteado < *pLimite) {
        
        sorteia(pCartelaA, pCartelaB, R, C, pSorteados, pLimite, pTotalSorteado, pGanhador);
        
        if (*pGanhador != 0 || *pTotalSorteado == *pLimite) {
            break;
        }
        
        cout << "\nPressione ENTER para o proximo sorteio...";
        cin.ignore(); 
        if (cin.peek() == '\n') {
            cin.ignore();
        }
    }
    
    cout << "\n=========================================\n";
    if (*pTotalSorteado == *pLimite && *pGanhador == 0) {
        cout << "TODOS OS VALORES FORAM SORTEADOS. SEM GANHADOR.\n";
    } else {
        cout << "FIM DO JOGO! GANHADOR(ES): ";
        if (*pGanhador == 1 || *pGanhador == 3) {
            cout << "CARTELA A ";
        }
        if (*pGanhador == 2 || *pGanhador == 3) {
            cout << "CARTELA B ";
        }
        cout << "\n";
    }
    cout << "=========================================\n";

    delete pZero;
    delete pLimite;
    delete pSorteados;
    delete pi;
    delete pGanhador;
    delete pTotalSorteado;
    delete[] pNomeA;
    delete[] pNomeB;
    
    l(&pCartelaA, &pCartelaB, R, C);
    exit(0);
}

void geraCartela(Cell** pC, int* R, int* C, int* pS, int* pZ) {
    int* pi = new int;
    int* pj = new int;
    int* pNum = new int;
    
    for (*pi = 0; *pi < *R; (*pi)++) {
        for (*pj = 0; *pj < *C; (*pj)++) {
            
            Cell* pCell = &(*(*(pC + *pi) + *pj));
            pCell->pNum = new int;
            pCell->pMarcado = new int;
            *(pCell->pMarcado) = 0;
            
            do {
                *pNum = (rand() % 75) + 1;
            } while (*(pS + *pNum) == 1);
            
            *(pCell->pNum) = *pNum;
            *(pS + *pNum) = 1;
        }
    }
    
    for (*pi = 0; *pi <= 75; (*pi)++) {
        *(pS + *pi) = 0;
    }
    
    delete pi;
    delete pj;
    delete pNum;
}

void mostraCartela(Cell** pC, int* R, int* C, char* pNome) {
    int* pi = new int;
    int* pj = new int;
    
    cout << "\nCARTELA " << pNome << "\n";
    for (*pi = 0; *pi < *R; (*pi)++) {
        for (*pj = 0; *pj < *C; (*pj)++) {
            Cell* pCell = &(*(*(pC + *pi) + *pj));
            
            cout << setw(3) << *(pCell->pNum);
            
            if (*(pCell->pMarcado) == 1) {
                cout << "(*)";
            } else {
                cout << "   ";
            }
        }
        cout << "\n";
    }
    delete pi;
    delete pj;
}

void sorteia(Cell** pA, Cell** pB, int* R, int* C, int* pS, int* L, int* pT, int* pG) {
    int* pSorteado = new int;
    int* pi = new int;
    int* pj = new int;
    
    do {
        *pSorteado = (rand() % *L) + 1;
    } while (*(pS + *pSorteado) == 1);
    
    *(pS + *pSorteado) = 1;
    (*pT)++;
    
    cout << "\n=========================================\n";
    cout << "NUMERO SORTEADO: " << *pSorteado << "\n";
    cout << "=========================================\n";

    for (*pi = 0; *pi < *R; (*pi)++) {
        for (*pj = 0; *pj < *C; (*pj)++) {
            Cell* pCellA = &(*(*(pA + *pi) + *pj));
            Cell* pCellB = &(*(*(pB + *pi) + *pj));

            if (*(pCellA->pNum) == *pSorteado) {
                *(pCellA->pMarcado) = 1;
            }
            if (*(pCellB->pNum) == *pSorteado) {
                *(pCellB->pMarcado) = 1;
            }
        }
    }
    
    if (*(verifica(pA, R, C)) == 1) {
        *pG = 1;
    }
    if (*(verifica(pB, R, C)) == 1) {
        if (*pG == 1) {
            *pG = 3;
        } else {
            *pG = 2;
        }
    }
    
    char* pNomeA = new char[2]; pNomeA[0] = 'A'; pNomeA[1] = '\0';
    char* pNomeB = new char[2]; pNomeB[0] = 'B'; pNomeB[1] = '\0';
    
    mostraCartela(pA, R, C, pNomeA);
    mostraCartela(pB, R, C, pNomeB);

    delete pSorteado;
    delete pi;
    delete pj;
    delete[] pNomeA;
    delete[] pNomeB;
}

int* verifica(Cell** pC, int* R, int* C) {
    int* pWin = new int; *pWin = 0;
    int* pi = new int;
    int* pj = new int;
    int* pCont = new int;
    
    for (*pi = 0; *pi < *R; (*pi)++) {
        *pCont = 0;
        for (*pj = 0; *pj < *C; (*pj)++) {
            if (*((*(*(pC + *pi) + *pj)).pMarcado) == 1) {
                (*pCont)++;
            }
        }
        if (*pCont == *C) { *pWin = 1; break; }
    }
    if (*pWin == 1) { delete pCont; delete pi; delete pj; return pWin; }
    
    for (*pj = 0; *pj < *C; (*pj)++) {
        *pCont = 0;
        for (*pi = 0; *pi < *R; (*pi)++) {
            if (*((*(*(pC + *pi) + *pj)).pMarcado) == 1) {
                (*pCont)++;
            }
        }
        if (*pCont == *R) { *pWin = 1; break; }
    }
    if (*pWin == 1) { delete pCont; delete pi; delete pj; return pWin; }

    *pCont = 0;
    for (*pi = 0; *pi < *R; (*pi)++) {
        if (*((*(*(pC + *pi) + *pi)).pMarcado) == 1) {
            (*pCont)++;
        }
    }
    if (*pCont == *R) { *pWin = 1; }
    if (*pWin == 1) { delete pCont; delete pi; delete pj; return pWin; }

    *pCont = 0;
    for (*pi = 0; *pi < *R; (*pi)++) {
        if (*((*(*(pC + *pi) + *R - 1 - *pi)).pMarcado) == 1) {
            (*pCont)++;
        }
    }
    if (*pCont == *R) { *pWin = 1; }
    
    delete pCont;
    delete pi;
    delete pj;
    return pWin;
}

void l(Cell*** ppA, Cell*** ppB, int* R, int* C) {
    int* pi = new int;
    for (*pi = 0; *pi < *R; (*pi)++) {
        for (int* pj = new int; *pj < *C; (*pj)++) {
            Cell* pCellA = &(*(*ppA + *pi) + *pj);
            Cell* pCellB = &(*(*ppB + *pi) + *pj);
            
            delete pCellA->pNum;
            delete pCellA->pMarcado;
            delete pCellB->pNum;
            delete pCellB->pMarcado;
            delete pj;
        }
        delete[] *(*ppA + *pi);
        delete[] *(*ppB + *pi);
    }
    delete[] *ppA;
    delete[] *ppB;
    delete R;
    delete C;
    delete pi;
}