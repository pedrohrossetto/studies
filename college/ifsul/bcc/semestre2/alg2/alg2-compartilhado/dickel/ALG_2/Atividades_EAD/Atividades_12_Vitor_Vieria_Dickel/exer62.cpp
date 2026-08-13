#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

#define TAMANHO 20

void gera(int* pVetor) {
    srand(time(0));
    int* pEnd = pVetor + TAMANHO;
    
    int* pAtual = pVetor;

    while (pAtual < pEnd) {
        int* pNovoValor = new int(rand() % 101);
        
        bool* pRepetido = new bool(false);
        int* pCheck = pVetor;
        
        while (pCheck < pAtual) {
            if (*pCheck == *pNovoValor) {
                *pRepetido = true;
                break;
            }
            pCheck++;
        }
        
        if (!*pRepetido) {
            *pAtual = *pNovoValor;
            pAtual++;
        }
        
        delete pNovoValor;
        delete pRepetido;
    }
}

void ordena(int* pVetor) {
    int* pEnd = pVetor + TAMANHO;
    
    int* pExterno = pVetor;
    
    while (pExterno < pEnd - 1) {
        
        int** ppMenor = new int*(); 
        *ppMenor = pExterno;
        
        int* pInterno = pExterno + 1;
        
        while (pInterno < pEnd) {
            if (*pInterno < **ppMenor) {
                *ppMenor = pInterno;
            }
            pInterno++;
        }
        
        if (*ppMenor != pExterno) {
            int* pTemp = new int(*pExterno);
            *pExterno = **ppMenor;
            **ppMenor = *pTemp;
            delete pTemp;
        }
        
        delete ppMenor;
        pExterno++;
    }
}

int main() {
    int* pVetor = new int[TAMANHO];

    gera(pVetor);

    ordena(pVetor);

    ofstream saida("exerc_61.txt");

    if (!saida.is_open()) {
        delete[] pVetor;
        return 1;
    }
    
    int* pAtual = pVetor;
    int* pEnd = pVetor + TAMANHO;

    saida << hex << uppercase;

    while (pAtual < pEnd) {
        saida << (void*)pAtual << " - " << dec << *pAtual << endl;
        pAtual++;
    }

    saida.close();
    
    delete[] pVetor;

    return 0;
}