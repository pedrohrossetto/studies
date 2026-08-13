#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iomanip>

using namespace std;

void i(int**, int*, int*);
void m(int**, int*, int*);
void a(int**, int*, int*);
void e(int**, int*, int*);
void l(int***, int*, int*, int*);

int main() {
    int* R = new int; *R = 4;
    int* C = new int; *C = 6;
    
    int** pMatrix = new int*[*R];
    int* pi = new int;
    
    for (*pi = 0; *pi < *R; (*pi)++) {
        *(pMatrix + *pi) = new int[*C];
    }
    
    i(pMatrix, R, C);
    
    int* pOption = new int;
    *pOption = -1;

    while (*pOption != 0) {
        cout << "\nMenu:\n";
        cout << "0 - Sair\n";
        cout << "1 - Mostrar matriz\n";
        cout << "2 - Indicar acidente\n";
        cout << "3 - Estatisticas\n";
        cout << "Escolha: ";
        cin >> *pOption;

        if (*pOption == 1) {
            m(pMatrix, R, C);
        } else if (*pOption == 2) {
            a(pMatrix, R, C);
        } else if (*pOption == 3) {
            e(pMatrix, R, C);
        } else if (*pOption != 0) {
            cout << "Opcao invalida.\n";
        }
    }

    l(&pMatrix, R, C, pi);
    delete pOption;
    exit(0);
}

void i(int** pMatrix, int* pRows, int* pCols) {
    int* pi = new int;
    int* pj = new int;
    
    for (*pi = 0; *pi < *pRows; (*pi)++) {
        for (*pj = 0; *pj < *pCols; (*pj)++) {
            *(*(pMatrix + *pi) + *pj) = 0;
        }
    }
    delete pi;
    delete pj;
}

void m(int** pMatrix, int* pRows, int* pCols) {
    int* pi = new int;
    int* pj = new int;
    
    cout << "\nMatriz LE x NS:\n";
    
    cout << "   ";
    for (*pj = 0; *pj < *pCols; (*pj)++) {
        cout << setw(5) << "NS" << *pj + 1;
    }
    cout << "\n";
    
    for (*pi = 0; *pi < *pRows; (*pi)++) {
        cout << "LE" << *pi + 1;
        for (*pj = 0; *pj < *pCols; (*pj)++) {
            cout << setw(7) << *(*(pMatrix + *pi) + *pj);
        }
        cout << "\n";
    }
    delete pi;
    delete pj;
}

void a(int** pMatrix, int* pRows, int* pCols) {
    int* pRow = new int;
    int* pCol = new int;
    
    cout << "Rua Leste-Oeste (1 a " << *pRows << "): ";
    cin >> *pRow;
    cout << "Rua Norte-Sul (1 a " << *pCols << "): ";
    cin >> *pCol;
    
    if (*pRow >= 1 && *pRow <= *pRows && *pCol >= 1 && *pCol <= *pCols) {
        (*(*(pMatrix + *pRow - 1) + *pCol - 1))++;
        cout << "Acidente LE" << *pRow << " x NS" << *pCol << ".\n";
    } else {
        cout << "Invalidas.\n";
    }
    
    delete pRow;
    delete pCol;
}

void e(int** pMatrix, int* pRows, int* pCols) {
    int* pTotal = new int; *pTotal = 0;
    int* pi = new int;
    int* pj = new int;
    
    int* pMaxA = new int; *pMaxA = -1;
    
    for (*pi = 0; *pi < *pRows; (*pi)++) {
        for (*pj = 0; *pj < *pCols; (*pj)++) {
            *pTotal += *(*(pMatrix + *pi) + *pj);
            if (*(*(pMatrix + *pi) + *pj) > *pMaxA) {
                *pMaxA = *(*(pMatrix + *pi) + *pj);
            }
        }
    }
    cout << "\nEstatisticas:\n";
    cout << "a. Total: " << *pTotal << "\n";
    
    cout << "b. Cruzamentos Maximo (" << *pMaxA << "): ";
    int* pFirst = new int; *pFirst = 1;

    for (*pi = 0; *pi < *pRows; (*pi)++) {
        for (*pj = 0; *pj < *pCols; (*pj)++) {
            if (*(*(pMatrix + *pi) + *pj) == *pMaxA && *pMaxA > 0) {
                if (*pFirst == 0) {
                    cout << ", ";
                }
                cout << "LE" << *pi + 1 << "xNS" << *pj + 1;
                *pFirst = 0;
            }
        }
    }
    if (*pFirst == 1) { cout << "Nenhum"; }
    cout << "\n";
    
    int* pMaxNS = new int; *pMaxNS = -1;
    int* pSomaCol = new int;
    
    for (*pj = 0; *pj < *pCols; (*pj)++) {
        *pSomaCol = 0;
        for (*pi = 0; *pi < *pRows; (*pi)++) {
            *pSomaCol += *(*(pMatrix + *pi) + *pj);
        }
        if (*pSomaCol > *pMaxNS) {
            *pMaxNS = *pSomaCol;
        }
    }

    cout << "c. Rua NS Max (" << *pMaxNS << "): ";
    *pFirst = 1;
    for (*pj = 0; *pj < *pCols; (*pj)++) {
        *pSomaCol = 0;
        for (*pi = 0; *pi < *pRows; (*pi)++) {
            *pSomaCol += *(*(pMatrix + *pi) + *pj);
        }
        if (*pSomaCol == *pMaxNS && *pMaxNS > 0) {
             if (*pFirst == 0) {
                cout << ", ";
            }
            cout << "NS" << *pj + 1;
            *pFirst = 0;
        }
    }
    if (*pFirst == 1) { cout << "Nenhum"; }
    cout << "\n";
    
    int* pMaxLE = new int; *pMaxLE = -1;
    int* pSomaRow = new int;
    
    for (*pi = 0; *pi < *pRows; (*pi)++) {
        *pSomaRow = 0;
        for (*pj = 0; *pj < *pCols; (*pj)++) {
            *pSomaRow += *(*(pMatrix + *pi) + *pj);
        }
        if (*pSomaRow > *pMaxLE) {
            *pMaxLE = *pSomaRow;
        }
    }

    cout << "d. Rua LE Max (" << *pMaxLE << "): ";
    *pFirst = 1;
    for (*pi = 0; *pi < *pRows; (*pi)++) {
        *pSomaRow = 0;
        for (*pj = 0; *pj < *pCols; (*pj)++) {
            *pSomaRow += *(*(pMatrix + *pi) + *pj);
        }
        if (*pSomaRow == *pMaxLE && *pMaxLE > 0) {
             if (*pFirst == 0) {
                cout << ", ";
            }
            cout << "LE" << *pi + 1;
            *pFirst = 0;
        }
    }
    if (*pFirst == 1) { cout << "Nenhum"; }
    cout << "\n";

    delete pTotal;
    delete pi;
    delete pj;
    delete pMaxA;
    delete pSomaCol;
    delete pMaxLE;
    delete pSomaRow;
    delete pFirst;
    delete pMaxNS;
}

void l(int*** pMatrix, int* pRows, int* pCols, int* pi) {
    for (*pi = 0; *pi < *pRows; (*pi)++) {
        delete[] *(*pMatrix + *pi);
    }
    delete[] *pMatrix;
    *pMatrix = nullptr;
    delete pRows;
    delete pCols;
}