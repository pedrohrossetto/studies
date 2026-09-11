#include <iostream>

/**
 * @brief Ordena um vetor usando Bubble Sort e aritmética de ponteiros.
 * @param vetor Ponteiro para o início do array.
 * @param tamanho Ponteiro para o tamanho do array.
 */
void alg_ordenarBubbleSort(int* vetor, int* tamanho) {
    // Alocação dinâmica de contadores e auxiliares
    int* i = new int;
    int* j = new int;
    int* temp = new int;

    // Loop Externo: i de 0 até tamanho-1
    for (*i = 0; *i < *tamanho - 1; (*i)++) {
        
        // Loop Interno: j de 0 até tamanho-i-1
        for (*j = 0; *j < *tamanho - *i - 1; (*j)++) {
            
            // Aritmética de Ponteiros para acessar v[j] e v[j+1]
            int* atual   = (vetor + *j);
            int* proximo = (vetor + *j + 1);

            // Se atual > proximo, troca
            if (*atual > *proximo) {
                *temp    = *atual;
                *atual   = *proximo;
                *proximo = *temp;
            }
        }
    }

    // Limpeza de memória obrigatória
    delete i;
    delete j;
    delete temp;
}