#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iomanip>

using namespace std;

void o(char*, int*);
void l(int**, char**, int**, int**, int**, int**, int**, int**);

int main() {
    int* pNum = new int;
    
    char* pStr = new char[5];
    char* pMenor = new char[5];
    char* pMaior = new char[5];
    
    int* pMaiorVal = new int;
    int* pMenorVal = new int;
    int* p4 = new int; *p4 = 4;
    
    int* pi = new int;
    int* pj = new int;
    char* ptemp = new char;

    do {
        cout << "Informe um valor: ";
        cin >> *pNum;
        
        if (*pNum < 1000 || *pNum > 9999) {
            cout << "Valor invalido, digite novamente\n";
            continue;
        }
        
        sprintf(pStr, "%d", *pNum);
        
        *ptemp = *pStr;
        if (*(pStr + 1) == *ptemp && *(pStr + 2) == *ptemp && *(pStr + 3) == *ptemp) {
            cout << "Valor invalido, digite novamente\n";
            continue;
        }
        
    } while (*pNum < 1000 || *pNum > 9999 || (*pStr == *(pStr + 1) && *(pStr + 1) == *(pStr + 2) && *(pStr + 2) == *(pStr + 3)));
    
    while (*pNum != 6174) {
        
        sprintf(pStr, "%04d", *pNum); 
        
        for (*pi = 0; *pi < *p4 - 1; (*pi)++) {
            for (*pj = 0; *pj < *p4 - 1 - *pi; (*pj)++) {
                if (*(pStr + *pj) > *(pStr + *pj + 1)) {
                    *ptemp = *(pStr + *pj);
                    *(pStr + *pj) = *(pStr + *pj + 1);
                    *(pStr + *pj + 1) = *ptemp;
                }
            }
        }
        strcpy(pMenor, pStr);
        
        for (*pi = 0; *pi < *p4; (*pi)++) {
            *(pMaior + *pi) = *(pMenor + *p4 - 1 - *pi);
        }
        *(pMaior + *p4) = '\0';
        
        sscanf(pMaior, "%d", pMaiorVal);
        sscanf(pMenor, "%d", pMenorVal);

        *pNum = *pMaiorVal - *pMenorVal;

        cout << *pMaiorVal << " - ";
        cout << setw(4) << setfill('0') << *pMenorVal << " = ";
        cout << *pNum << endl;
    }

    delete pi;
    delete pj;
    delete ptemp;

    l(&pNum, &pStr, &pMenor, &pMaior, &pMaiorVal, &pMenorVal, &p4, nullptr);
    
    exit(0);
}

void o(char* v, int* t) {
}

void l(int** ppNum, char** ppStr, char** ppMenor, char** ppMaior, int** ppMaiorVal, int** ppMenorVal, int** ppQuatro, int** ppExtra) {
    delete *ppNum;
    delete[] *ppStr;
    delete[] *ppMenor;
    delete[] *ppMaior;
    delete *ppMaiorVal;
    delete *ppMenorVal;
    delete *ppQuatro;

    *ppNum = nullptr;
    *ppStr = nullptr;
    *ppMenor = nullptr;
    *ppMaior = nullptr;
    *ppMaiorVal = nullptr;
    *ppMenorVal = nullptr;
    *ppQuatro = nullptr;
}