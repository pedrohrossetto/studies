#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cmath>

using namespace std;

void o(int*, int*);
void m(int*, int*);
void e(int*, int*, int*, int*, int*);
void g(int*, int*, int*, int*, int*);
void l(int***, int***, int*);

int main() {
    int* pN = new int;
    int* pCheck = new int;
    
    do {
        cout << "Qtd. de valores (par, 6 a 24): ";
        cin >> *pN;
        
        *pCheck = (*pN % 2 != 0 || *pN < 6 || *pN > 24);
        
        if (*pCheck) {
            cout << "Valor invalido. Tente novamente.\n";
        }
    } while (*pCheck);
    
    int* pVetor1 = new int[*pN];
    
    int* pi = new int;
    int* pj = new int;
    int* pDuplicado = new int;
    int* pValido = new int;
    int* pNum = new int;
    
    int* semente = new int; *semente = 1; 
    srand(*semente);
    delete semente;

    for (*pi = 0; *pi < *pN; (*pi)++) {
        do {
            *pDuplicado = 0;
            *pValido = 0;
            *pNum = rand() % 500;
            
            if ( *pNum == 0) continue;
            
            int* pUnid = new int; *pUnid = *pNum % 10;
            
            if (*pNum % 3 == 0 || *pNum % 7 == 0 || *pUnid == 3 || *pUnid == 7) {
                *pValido = 1;
            }
            delete pUnid;
            
            for (*pj = 0; *pj < *pi; (*pj)++) {
                if (*(pVetor1 + *pj) == *pNum) {
                    *pDuplicado = 1;
                    break;
                }
            }
        } while (*pValido == 0 || *pDuplicado == 1);
        
        *(pVetor1 + *pi) = *pNum;
    }
    
    delete pi;
    delete pj;
    delete pDuplicado;
    delete pValido;
    delete pNum;

    m(pVetor1, pN);
    
    int* pMax = new int; 
    int* pMin = new int;
    int* pIndMax = new int;
    int* pIndMin = new int;
    
    e(pVetor1, pN, pMax, pMin, pIndMax, pIndMin);
    
    int* pSoma = new int; *pSoma = 0;
    int* pMediaInt = new int;
    double* pSomaD = new double;
    
    *pSomaD = 0.0;
    int* pk = new int;
    for (*pk = 0; *pk < *pN; (*pk)++) {
        *pSoma += *(pVetor1 + *pk);
    }
    
    *pSomaD = (double)*pSoma / (double)*pN;
    *pMediaInt = (int)ceil(*pSomaD);

    cout << "  Media dos elementos (arred. ceil): " << *pMediaInt << "\n";

    delete pSoma;
    delete pSomaD;
    delete pk;

    int* pCount2 = new int; *pCount2 = 0;
    
    int* pl = new int;
    for (*pl = 0; *pl < *pN; (*pl)++) {
        if (*(pVetor1 + *pl) < *pMediaInt) {
            (*pCount2)++;
        }
    }
    delete pl;

    int* pVetor2 = new int[*pCount2];
    g(pVetor1, pN, pVetor2, pCount2, pMediaInt);
    
    if (*pCount2 > 0) {
        o(pVetor2, pCount2);
        cout << "\nSegundo vetor (menores que a media, ordenado):\n";
        m(pVetor2, pCount2);
    } else {
        cout << "\nNao ha elementos menores que a media.\n";
    }

    l(&pVetor1, &pVetor2, pN, pCheck);
    delete pMax;
    delete pMin;
    delete pIndMax;
    delete pIndMin;
    delete pMediaInt;
    
    exit(0);
}

void m(int* v, int* t) {
    int* pi = new int;
    
    cout << "  [";
    for (*pi = 0; *pi < *t; (*pi)++) {
        cout << *(v + *pi);
        if (*pi < *t - 1) {
            cout << ", ";
        }
    }
    cout << "]\n";
    delete pi;
}

void e(int* v, int* t, int* max, int* min, int* imax, int* imin) {
    int* pi = new int;
    
    *max = *v; 
    *min = *v;
    *imax = 0;
    *imin = 0;
    
    for (*pi = 1; *pi < *t; (*pi)++) {
        if (*(v + *pi) > *max) {
            *max = *(v + *pi);
            *imax = *pi;
        }
        if (*(v + *pi) < *min) {
            *min = *(v + *pi);
            *imin = *pi;
        }
    }

    cout << "\nEstatisticas:\n";
    cout << "  Maior: " << *max << " (Pos: " << *imax << ")\n";
    cout << "  Menor: " << *min << " (Pos: " << *imin << ")\n";
    delete pi;
}

void g(int* v1, int* t1, int* v2, int* t2, int* media) {
    int* pi = new int;
    int* pj = new int; *pj = 0;
    
    for (*pi = 0; *pi < *t1; (*pi)++) {
        if (*(v1 + *pi) < *media) {
            *(v2 + *pj) = *(v1 + *pi);
            (*pj)++;
        }
    }
    delete pi;
    delete pj;
}

void o(int* v, int* t) {
    int* i = new int;
    int* j = new int;
    int* temp = new int;
    int* aux = new int;

    *aux = *t; (*aux)--; 

    for (*i = 0; *i < *aux; (*i)++) {
        for (*j = 0; *j < *aux - *i; (*j)++) {
            if (*(v + *j) > *(v + *j + 1)) {
                *temp = *(v + *j);
                *(v + *j) = *(v + *j + 1);
                *(v + *j + 1) = *temp;
            }
        }
    }
    delete i;
    delete j;
    delete temp;
    delete aux;
}

void l(int*** vv1, int*** vv2, int* pN, int* pCheck) {
    delete[] **vv1;
    delete[] **vv2;
    **vv1 = nullptr;
    **vv2 = nullptr;
    delete *pCheck;
    delete *pN;
}