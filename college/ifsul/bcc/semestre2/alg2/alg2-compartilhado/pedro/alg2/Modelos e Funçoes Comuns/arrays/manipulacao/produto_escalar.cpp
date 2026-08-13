#include <iostream>

/**
 * @brief Calcula a soma dos produtos: (v1[0]*v2[0]) + (v1[1]*v2[1]) + ...
 * @return O resultado inteiro do produto escalar.
 */
int mod_produtoEscalar(int* v1, int* v2, int* tamanho) {
    int* p1 = v1;
    int* p2 = v2;
    int* fim = v1 + *tamanho;

    // Acumulador no Heap
    int* soma = new int(0);

    while (p1 < fim) {
        // Aritmética: Valor apontado por p1 * Valor apontado por p2
        *soma += (*p1) * (*p2);

        // Avança ambos para a próxima posição
        p1++;
        p2++;
    }

    int resultado = *soma;
    delete soma;
    
    return resultado;
}