#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>

using namespace std;

bool valida(int valor) {
    int* pUltimoDigito = new int(valor % 10);
    bool* pValido = new bool(false);

    if (valor % 4 == 0 || valor % 9 == 0) {
        *pValido = true;
    } else if (*pUltimoDigito == 5 || *pUltimoDigito == 8) {
        *pValido = true;
    }

    delete pUltimoDigito;
    bool resultado = *pValido;
    delete pValido;
    return resultado;
}

bool jaExiste(int* pVetor, int* pEnd, int valor) {
    int* pAtual = pVetor;
    bool* pEncontrado = new bool(false);

    while (pAtual < pEnd) {
        if (*pAtual == valor) {
            *pEncontrado = true;
            break;
        }
        pAtual++;
    }
    
    bool resultado = *pEncontrado;
    delete pEncontrado;
    return resultado;
}

void geraVetor(int* pVetor, int* pTamanho) {
    srand(time(0));
    int* pEnd = pVetor + *pTamanho;
    int* pAtual = pVetor;
    
    while (pAtual < pEnd) {
        int* pNovoValor = new int(rand() % 481 + 20);

        if (valida(*pNovoValor) && !jaExiste(pVetor, pAtual, *pNovoValor)) {
            *pAtual = *pNovoValor;
            pAtual++;
        }
        delete pNovoValor;
    }
}

void mostraVetor(int* pVetor, int* pTamanho) {
    int* pAtual = pVetor;
    int* pEnd = pVetor + *pTamanho;
    
    while (pAtual < pEnd) {
        cout << *pAtual;
        if (pAtual + 1 < pEnd) {
            cout << ",";
        }
        pAtual++;
    }
    cout << endl;
}

int main() {
    int* pTamanho = new int;
    
    do {
        cout << "Informe a quantidade de valores (par, min 6, max 24): ";
        cin >> *pTamanho;
        
        if (*pTamanho < 6 || *pTamanho > 24 || *pTamanho % 2 != 0) {
            cout << "Erro: O valor deve ser par, no mínimo 6 e no máximo 24." << endl;
        }
    } while (*pTamanho < 6 || *pTamanho > 24 || *pTamanho % 2 != 0);

    int* pVet = new int[*pTamanho];
    geraVetor(pVet, pTamanho);

    cout << "\n--- Exibição dos Elementos ---" << endl;
    mostraVetor(pVet, pTamanho);

    cout << "\n--- Encontrar e Mostrar ---" << endl;
    
    int* pMaior = pVet;
    int* pMenor = pVet;
    int* pEnd = pVet + *pTamanho;
    int* pAtual = pVet + 1;

    while (pAtual < pEnd) {
        if (*pAtual > *pMaior) {
            pMaior = pAtual;
        }
        if (*pAtual < *pMenor) {
            pMenor = pAtual;
        }
        pAtual++;
    }

    cout << "Maior: " << *pMaior << " (" << (void*)pMaior << ")" << endl;
    cout << "Menor: " << *pMenor << " (" << (void*)pMenor << ")" << endl;

    double* pSoma = new double((double)*pMaior + (double)*pMenor);
    double* pMedia = new double(*pSoma / 2.0);
    int* pMediaArredondada = new int(ceil(*pMedia));

    cout << "Média (arredondada): " << *pMediaArredondada << endl;
    
    cout << "\n--- Realizar os seguintes ajustes ---" << endl;
    
    int* pCapacidadeSobra = new int(0);
    pAtual = pVet;

    while (pAtual < pEnd) {
        if (*pAtual < *pMediaArredondada) {
            (*pCapacidadeSobra)++;
        }
        pAtual++;
    }

    int* pSegundoVet = new int[*pCapacidadeSobra];
    int* pDest = pSegundoVet;
    pAtual = pVet;

    while (pAtual < pEnd) {
        if (*pAtual < *pMediaArredondada) {
            *pDest = *pAtual;
            pDest++;
        }
        pAtual++;
    }
    
    pAtual = pSegundoVet;
    int* pEndSobra = pSegundoVet + *pCapacidadeSobra;

    while (pAtual < pEndSobra - 1) {
        int* pInterno = pAtual + 1;
        while (pInterno < pEndSobra) {
            if (*pInterno > *pAtual) {
                int* pTemp = new int(*pAtual);
                *pAtual = *pInterno;
                *pInterno = *pTemp;
                delete pTemp;
            }
            pInterno++;
        }
        pAtual++;
    }

    cout << "Segundo vetor (menores que a média, decrescente):" << endl;
    mostraVetor(pSegundoVet, pCapacidadeSobra);

    delete[] pVet;
    delete[] pSegundoVet;
    delete pTamanho;
    delete pSoma;
    delete pMedia;
    delete pMediaArredondada;
    delete pCapacidadeSobra;

    return 0;
}