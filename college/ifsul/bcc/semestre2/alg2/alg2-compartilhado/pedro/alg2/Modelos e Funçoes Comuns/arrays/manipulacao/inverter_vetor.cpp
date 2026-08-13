#include <iostream>

/**
 * @brief Inverte a ordem dos elementos de um vetor (In-place).
 * Ex: [1, 2, 3, 4] vira [4, 3, 2, 1].
 */
void mod_inverterVetor(int* vetor, int* tamanho) {
    // Ponteiro da esquerda (começo)
    int* pEsq = vetor;
    // Ponteiro da direita (final) -> Endereço base + tamanho - 1
    int* pDir = vetor + *tamanho - 1;
    
    // Variável temporária para o swap
    int* temp = new int;

    // Enquanto os ponteiros não se cruzarem
    while (pEsq < pDir) {
        // Troca os valores (Swap)
        *temp = *pEsq;
        *pEsq = *pDir;
        *pDir = *temp;

        // Aritmética: Avança um, recua o outro
        pEsq++;
        pDir--;
    }

    delete temp;
}