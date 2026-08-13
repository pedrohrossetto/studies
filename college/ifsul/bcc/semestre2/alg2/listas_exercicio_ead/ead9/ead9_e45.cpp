/*
    Autor: Pedro H C Rossetto
    Data: 19/10/2025
    Descrição: Lê um valor N (entre 3 e 9) e imprime um padrão triangular
    Algoritimos 2, Exercício 45
*/

#include <iostream>
using namespace std;

void lerValorN(int* ponteiroN);
void imprimirPadrao(const int* ponteiroN);

int main() {
    int* ponteiroN = new int;
    lerValorN(ponteiroN);
    imprimirPadrao(ponteiroN);
    delete ponteiroN;
    return 0;
}

void lerValorN(int* ponteiroN) {
    do {
        cout << "Digite um valor para N (entre 3 e 9): ";
        cin >> *ponteiroN;
        if (*ponteiroN < 3 || *ponteiroN > 9) {
            cout << "Valor invalido! Por favor, tente novamente." << endl;
        }
    } while (*ponteiroN < 3 || *ponteiroN > 9);
}

void imprimirPadrao(const int* ponteiroN) {
    cout << "\nPadrao para N = " << *ponteiroN << ":\n" << endl;
    for (int i = 1; i <= *ponteiroN; ++i) {
        for (int j = 1; j <= i; ++j) {
            cout << j << " ";
        }
        cout << endl;
    }
}
