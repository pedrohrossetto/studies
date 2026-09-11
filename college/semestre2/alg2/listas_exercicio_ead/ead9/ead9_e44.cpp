/*
    Autor: Pedro H.c Rossetto
    Data: 19/10/2025
    Descrição: Calcular soma e média da função main através de ponteiros.
    Algoritimos 2, Trabalho prático 9, Exercício 5
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

const int TAMANHO_VETOR = 20;

void gerar_vetor(int* ponteiroVetor, int tamanho);
void calcular_estatisticas(const int* ponteiroVetor, int tamanho, float* ponteiroMedia, int* ponteiroSoma);
void imprimir_vetor(const int* ponteiroVetor, int tamanho);

int main() {
    srand(time(NULL));
    int vetor[TAMANHO_VETOR];
    int somaTotal = 0;
    float mediaValores = 0.0f;
    gerar_vetor(vetor, TAMANHO_VETOR);
    imprimir_vetor(vetor, TAMANHO_VETOR);
    calcular_estatisticas(vetor, TAMANHO_VETOR, &mediaValores, &somaTotal);
    cout << "\n--- Resultados Finais ---\n";
    cout << "Soma de todos os elementos: " << somaTotal << endl;
    cout << "Media de todos os elementos: " << fixed << setprecision(2) << mediaValores << endl;
    cout << "---------------------------\n";
    return 0;
}

void gerar_vetor(int* ponteiroVetor, int tamanho) {
    for (int i = 0; i < tamanho; ++i) {
        int numeroAleatorio = rand() % 99 + 1;
        *(ponteiroVetor + i) = numeroAleatorio;
    }
}

void calcular_estatisticas(const int* ponteiroVetor, int tamanho, float* ponteiroMedia, int* ponteiroSoma) {
    *ponteiroSoma = 0;
    for (int i = 0; i < tamanho; ++i) {
        *ponteiroSoma += *(ponteiroVetor + i);
    }
    if (tamanho > 0) {
        *ponteiroMedia = static_cast<float>(*ponteiroSoma) / tamanho;
    } else {
        *ponteiroMedia = 0.0f;
    }
}

void imprimir_vetor(const int* ponteiroVetor, int tamanho) {
    cout << "--- Vetor Gerado ---\n[ ";
    for (int i = 0; i < tamanho; ++i) {
        cout << *(ponteiroVetor + i) << " ";
    }
    cout << "]\n--------------------\n";
}
