#ifndef VETOR_DINAMICO_HPP
#define VETOR_DINAMICO_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

// Protótipos das funções
int* alocar_vetor(int tamanho);
void preencher_aleatorio(int* v, int tam, int min, int max);
void mostrar_vetor(const int* v, int tam);
void liberar_vetor(int* &v);

/**
 * Aloca dinamicamente um vetor de inteiros.
 */
int* alocar_vetor(int tamanho) {
    if (tamanho <= 0) return nullptr;
    return new int[tamanho];
}

/**
 * Preenche o vetor com valores aleatórios em um intervalo fechado [min, max].
 */
void preencher_aleatorio(int* v, int tam, int min, int max) {
    if (v == nullptr) return;
    for (int i = 0; i < tam; i++) {
        v[i] = (std::rand() % (max - min + 1)) + min;
    }
}

/**
 * Exibe os elementos do vetor no console.
 */
void mostrar_vetor(const int* v, int tam) {
    if (v == nullptr) {
        std::cout << "Vetor vazio ou nao alocado." << std::endl;
        return;
    }
    std::cout << "[ ";
    for (int i = 0; i < tam; i++) {
        std::cout << v[i] << (i < tam - 1 ? ", " : "");
    }
    std::cout << " ]" << std::endl;
}

/**
 * Libera a memória e anula o ponteiro para evitar erros.
 */
void liberar_vetor(int* &v) {
    if (v != nullptr) {
        delete[] v;
        v = nullptr;
    }
}

#endif