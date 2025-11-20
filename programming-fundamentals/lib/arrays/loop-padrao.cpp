#include <iostream>

using namespace std;

/**
 * @brief Percorre um vetor usando aritmética de ponteiros, imprime
 * o valor/endereço e altera o valor para 10.
 * * @param vetor Ponteiro para o início do array.
 * @param tamanho Ponteiro para a quantidade de elementos.
 */
void modular_percorrerEModificar(int* vetor, int* tamanho) {
    
    // Define inicio e fim usando aritmética de ponteiros
    int* inicio = vetor;
    int* fim    = vetor + *tamanho; // Aponta para a posição logo após o último elemento

    cout << "\n--- Iniciando Iteracao via Ponteiros ---" << endl;

    // Loop usando ponteiro 'p' como iterador
    for (int* p = inicio; p < fim; p++) {
        // Leitura (Desreferência)
        cout << "Index " << (int)(p - inicio) << ": "; // Calculo opcional do indice visual
        cout << "Valor: " << *p << " | ";
        // O cout imprime endereços de memória em Hexadecimal automaticamente
        cout << "Endereco Memoria: " << p << endl;
    }

}