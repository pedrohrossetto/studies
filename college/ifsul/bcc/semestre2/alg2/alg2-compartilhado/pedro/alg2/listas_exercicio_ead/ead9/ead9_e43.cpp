/*
    Autor: Pedro H.C Rossetto
    Data: 13/10/2025
    Descrição: Gerar um relatório de números pares e ímpares.
    Algoritimos 2, Trabalho prático 9, Exercício 4
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int TAMANHO = 6;
void gerarValores(int* ponteiroVetor);
void exibirVetor(const int* ponteiroVetor);
void gerarRelatorio(const int* ponteiroVetor);
int main() {
    int vetor[TAMANHO];
    srand(time(NULL));
    gerarValores(vetor);
    exibirVetor(vetor);
    gerarRelatorio(vetor);
    return 0;
}
void gerarValores(int* ponteiroVetor) {
    for (int i = 0; i < TAMANHO; ++i) {
        int numeroAleatorio = rand() % 50 + 1;
        *(ponteiroVetor + i) = numeroAleatorio;
    }
    cout << "Vetor preenchido com valores aleatorios.\n";
}
void exibirVetor(const int* ponteiroVetor) {
    cout << "\n-----------------------------------------\n";
    cout << "Vetor\n";
    for (int i = 0; i < TAMANHO; ++i) {
        cout << *(ponteiroVetor + i) << " ";
    }
    cout << endl;
    for (int i = 0; i < TAMANHO; ++i) {
        cout << i << " ";
    }
    cout << "\n-----------------------------------------\n";
}
void gerarRelatorio(const int* ponteiroVetor) {
    int* somaPares = new int(0);
    int* qtdImpares = new int(0);
    cout << "\nRelatorio\n";
    cout << "Os numeros pares sao:\n";
    for (int i = 0; i < TAMANHO; ++i) {
        int valorAtual = *(ponteiroVetor + i);
        if (valorAtual % 2 == 0) {
            cout << "numero " << valorAtual << " na posicao " << i << endl;
            *somaPares += valorAtual;
        }
    }
    cout << "Soma dos pares = " << *somaPares << endl;
    cout << "\nOs numeros impares sao:\n";
    for (int i = 0; i < TAMANHO; ++i) {
        int valorAtual = *(ponteiroVetor + i);
        if (valorAtual % 2 != 0) {
            cout << "numero " << valorAtual << " na posicao " << i << endl;
            (*qtdImpares)++;
        }
    }
    cout << "Quantidade de impares = " << *qtdImpares << endl;
    cout << "-----------------------------------------\n";
    delete somaPares;
    delete qtdImpares;
}
