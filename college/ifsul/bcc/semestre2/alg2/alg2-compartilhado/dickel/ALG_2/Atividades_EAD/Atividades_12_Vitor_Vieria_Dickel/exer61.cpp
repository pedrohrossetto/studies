#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {

    int** ppV1 = new int*;
    *ppV1 = new int[0];
    int** ppV2 = new int*;
    *ppV2 = new int[0];

    int* pSizeV1 = new int(0);
    int* pSizeV2 = new int(0);

    ifstream entrada("Entrada.txt");
    ofstream saida("Saida.txt");

    if (!entrada.is_open() || !saida.is_open()) {
        saida << "Erro ao abrir os arquivos!" << endl;
        delete *ppV1;
        delete *ppV2;
        delete ppV1;
        delete ppV2;
        delete pSizeV1;
        delete pSizeV2;
        return 1;
    }

    char* pInstrucao = new char[20];
    char* pVetorNome = new char[3];
    int* pValor = new int;
    char* pFormato = new char[3];

    while (entrada >> pInstrucao) {
        if (strcmp(pInstrucao, "adiciona") == 0) {
            entrada >> pVetorNome >> *pValor;
            
            int** ppVetor;
            int* pSize;
            char* nome = pVetorNome;

            if (strcmp(pVetorNome, "V1") == 0) {
                ppVetor = ppV1;
                pSize = pSizeV1;
            } else {
                ppVetor = ppV2;
                pSize = pSizeV2;
            }

            int* pNovoVetor = new int[*pSize + 1];
            int* pSrc = *ppVetor;
            int* pDest = pNovoVetor;
            int* pEnd = *ppVetor + *pSize;

            while (pSrc < pEnd) {
                *pDest = *pSrc;
                pDest++;
                pSrc++;
            }

            *pDest = *pValor;

            delete[] *ppVetor;
            *ppVetor = pNovoVetor;
            (*pSize)++;
            
            saida << "O número " << *pValor << " foi adicionado no vetor " << nome << endl;
        
        } else if (strcmp(pInstrucao, "remove") == 0) {
            entrada >> pVetorNome >> *pValor;

            int** ppVetor;
            int* pSize;
            char* nome = pVetorNome;
            
            if (strcmp(pVetorNome, "V1") == 0) {
                ppVetor = ppV1;
                pSize = pSizeV1;
            } else {
                ppVetor = ppV2;
                pSize = pSizeV2;
            }

            int* pSearch = *ppVetor;
            int* pEnd = *ppVetor + *pSize;
            bool* pEncontrado = new bool(false);

            while (pSearch < pEnd) {
                if (*pSearch == *pValor) {
                    *pEncontrado = true;
                    break;
                }
                pSearch++;
            }

            if (*pEncontrado) {
                if (*pSize == 0) {
                    saida << "O número " << *pValor << " não pode ser removido, pois pertence ao vetor " << nome << endl;
                    delete pEncontrado;
                    continue;
                }

                int* pNovoVetor = new int[*pSize - 1];
                int* pSrc = *ppVetor;
                int* pDest = pNovoVetor;

                while (pSrc < pEnd) {
                    if (*pSrc != *pValor) {
                        *pDest = *pSrc;
                        pDest++;
                    } else {

                    }
                    pSrc++;
                }

                delete[] *ppVetor;
                *ppVetor = pNovoVetor;
                (*pSize)--;
                saida << "O número " << *pValor << " foi removido do vetor " << nome << endl;
            } else {
                saida << "O número " << *pValor << " não pode ser removido, pois não pertence ao vetor " << nome << endl;
            }
            delete pEncontrado;

        } else if (strcmp(pInstrucao, "mostra") == 0) {
            entrada >> pVetorNome >> pFormato;
            
            int* pVetor;
            int* pSize;
            char* nome = pVetorNome;

            if (strcmp(pVetorNome, "V1") == 0) {
                pVetor = *ppV1;
                pSize = pSizeV1;
            } else {
                pVetor = *ppV2;
                pSize = pSizeV2;
            }

            saida << nome << "(" << pFormato << "): ";
            int* pSrc = pVetor;
            int* pEnd = pVetor + *pSize;
            
            while (pSrc < pEnd) {
                saida << *pSrc;
                if (pSrc + 1 < pEnd) {
                    saida << ", ";
                }
                pSrc++;
            }
            saida << endl;

        } else if (strcmp(pInstrucao, "qtd") == 0) {
            entrada >> pVetorNome;

            int* pSize;
            char* nome = pVetorNome;
            
            if (strcmp(pVetorNome, "V1") == 0) {
                pSize = pSizeV1;
            } else {
                pSize = pSizeV2;
            }

            saida << "Total de elementos no vetor " << nome << ": " << *pSize << endl;

        } else if (strcmp(pInstrucao, "media") == 0) {
            entrada >> pVetorNome;

            int* pVetor;
            int* pSize;
            char* nome = pVetorNome;

            if (strcmp(pVetorNome, "V1") == 0) {
                pVetor = *ppV1;
                pSize = pSizeV1;
            } else {
                pVetor = *ppV2;
                pSize = pSizeV2;
            }

            double* pSoma = new double(0.0);
            int* pSrc = pVetor;
            int* pEnd = pVetor + *pSize;
            
            while (pSrc < pEnd) {
                *pSoma = *pSoma + (double)*pSrc;
                pSrc++;
            }

            if (*pSize == 0) {
                saida << "Media dos elementos do vetor " << nome << ": 0.0" << endl;
            } else {
                double* pMedia = new double(*pSoma / (double)*pSize);
                saida << "Media dos elementos do vetor " << nome << ": " << fixed << setprecision(1) << *pMedia << endl;
                delete pMedia;
            }
            delete pSoma;
        }
    }

    entrada.close();
    saida.close();
    
    delete[] *ppV1;
    delete[] *ppV2;
    delete ppV1;
    delete ppV2;
    delete pSizeV1;
    delete pSizeV2;
    delete[] pInstrucao;
    delete[] pVetorNome;
    delete pValor;
    delete[] pFormato;

    return 0;
}