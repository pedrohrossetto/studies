#include <iostream>

/**
 * @brief Atualiza os ponteiros passados para apontarem para o Maior e Menor valor do vetor.
 * @param vetor Ponteiro para o inicio do array.
 * @param tamanho Ponteiro para o tamanho.
 * @param outMin (Saída) Ponteiro que receberá o endereço do menor valor.
 * @param outMax (Saída) Ponteiro que receberá o endereço do maior valor.
 */
void alg_encontrarExtremos(int* vetor, int* tamanho, int** outMin, int** outMax) {
    int* p = vetor;
    int* fim = vetor + *tamanho;

    // Inicializa as saídas apontando para o primeiro elemento
    *outMin = vetor;
    *outMax = vetor;

    // Começa do segundo elemento
    p++; 

    while (p < fim) {
        // Se o valor apontado por p for menor que o valor apontado por outMin
        if (*p < **outMin) {
            *outMin = p; // Atualiza o endereço
        }
        // Se o valor apontado por p for maior que o valor apontado por outMax
        if (*p > **outMax) {
            *outMax = p; // Atualiza o endereço
        }
        p++;
    }
}