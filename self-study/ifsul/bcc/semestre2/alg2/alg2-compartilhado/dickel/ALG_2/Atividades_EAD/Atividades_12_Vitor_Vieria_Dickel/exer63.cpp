#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>

using namespace std;

void gerarValores(int* pVet, int* pSize) {
    srand(time(0));
    int* pEnd = pVet + *pSize;
    int* pAtual = pVet;

    while (pAtual < pEnd) {
        int* pNovoValor = new int(rand() % 50 + 1);
        
        bool* pRepetido = new bool(false);
        int* pCheck = pVet;
        
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

void mostraVetor(int* pVet, int* pSize, const char* nome) {
    int* pAtual = pVet;
    int* pEnd = pVet + *pSize;
    
    if (*pSize == 0) {
        cout << "O vetor " << nome << " está vazio." << endl;
        return;
    }

    cout << "Elementos do vetor " << nome << " (" << *pSize << "):";
    while (pAtual < pEnd) {
        cout << " " << *pAtual;
        pAtual++;
    }
    cout << endl;
}

void incluirSobra(int* pSobra, int* pSizeSobra, int* pMaxSobra, int valor) {
    if (*pSizeSobra == *pMaxSobra) {
        cout << "Vetor 'sobra' cheio. Esvaziando..." << endl;
        mostraVetor(pSobra, pSizeSobra, "sobra");
        
        int* pSobraAtual = pSobra;
        int* pSobraEnd = pSobra + *pMaxSobra;
        
        while (pSobraAtual < pSobraEnd) {
            *pSobraAtual = 0;
            pSobraAtual++;
        }
        *pSizeSobra = 0;
    }
    
    *(pSobra + *pSizeSobra) = valor;
    (*pSizeSobra)++;
    cout << "Valor " << valor << " incluído no vetor 'sobra'." << endl;
}


int main() {
    int* pDimensao = new int;
    
    do {
        cout << "Informe a dimensão do vetor (entre 5 e 50): ";
        cin >> *pDimensao;
        if (*pDimensao < 5 || *pDimensao > 50) {
            cout << "Dimensão inválida. Tente novamente." << endl;
        }
    } while (*pDimensao < 5 || *pDimensao > 50);

    int* pVet = new int[*pDimensao];
    int* pSobra = new int[*pDimensao];
    
    int* pTamanhoSobra = new int(0);
    int* pMaxSobra = pDimensao;
    
    int* pOpcao = new int(-1); 
    bool* pGerado = new bool(false);
    bool* pLocalizado = new bool(false);
    
    while (*pOpcao != 0) {
        cout << "\n--- Menu ---" << endl;
        cout << "0 - Sair" << endl;
        cout << "1 - Gerar valores para o vetor (vet)" << endl;
        cout << "2 - Localizar valor" << endl;
        cout << "3 - Mostrar elementos do vetor vet" << endl;
        cout << "4 - Mostrar elementos do vetor \"sobra\"" << endl;
        cout << "Escolha uma opção: ";
        
        if (!(cin >> *pOpcao)) {
            cin.clear();
            char* pIgnorar = new char[256];
            cin.getline(pIgnorar, 256);
            delete[] pIgnorar;
            *pOpcao = -1; 
        }

        switch (*pOpcao) {
            case 0:
                cout << "Saindo do programa." << endl;
                break;
                
            case 1:
                gerarValores(pVet, pDimensao);
                *pGerado = true;
                cout << "Vetor 'vet' gerado com " << *pDimensao << " valores únicos." << endl;
                break;
                
            case 2:
                if (!*pGerado) {
                    cout << "Opção 2 só pode ser executada se a opção 1 foi acionada." << endl;
                    break;
                }
                
                int* pValorBusca = new int;
                cout << "Informe o valor a ser localizado: ";
                cin >> *pValorBusca;
                
                int* pAtual = pVet;
                int* pEnd = pVet + *pDimensao;
                bool* pEncontrado = new bool(false);
                
                while (pAtual < pEnd) {
                    if (*pAtual == *pValorBusca) {
                        *pEncontrado = true;
                        break;
                    }
                    pAtual++;
                }
                
                if (*pEncontrado) {
                    cout << "Valor " << *pValorBusca << ", pertence ao vetor está no endereço de memória " << (void*)pAtual << endl;
                } else {
                    cout << "Não pertence no vetor o valor informado." << endl;
                    incluirSobra(pSobra, pTamanhoSobra, pMaxSobra, *pValorBusca);
                }
                
                *pLocalizado = true;
                delete pValorBusca;
                delete pEncontrado;
                break;
                
            case 3:
                if (!*pGerado) {
                    cout << "Opção 3 só pode ser executada se a opção 1 foi acionada." << endl;
                    break;
                }
                mostraVetor(pVet, pDimensao, "vet");
                break;
                
            case 4:
                if (!*pLocalizado) {
                    cout << "Opção 4 só poderá ser executada se a opção 2 foi executada pelo menos uma vez." << endl;
                    break;
                }
                mostraVetor(pSobra, pTamanhoSobra, "sobra");
                break;
                
            default:
                cout << "Opção inválida. Escolha uma opção válida do menu." << endl;
                break;
        }
    }

    delete[] pVet;
    delete[] pSobra;
    delete pDimensao;
    delete pTamanhoSobra;
    delete pOpcao;
    delete pGerado;
    delete pLocalizado;

    return 0;
}