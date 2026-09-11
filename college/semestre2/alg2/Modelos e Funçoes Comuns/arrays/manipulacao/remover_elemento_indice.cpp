#include <iostream>

/**
 * @brief Remove um elemento do vetor movendo os posteriores para esquerda.
 * @param vetor Ponteiro para o início do vetor.
 * @param tamAtual Ponteiro para o tamanho lógico atual (será decrementado).
 * @param posEndereco Endereço de memória do elemento a ser removido.
 */
void alg_removerElemento(int* vetor, int* tamAtual, int* posEndereco) {
    // Verifica limites de segurança
    int* fimLogico = vetor + *tamAtual;
    if (posEndereco < vetor || posEndereco >= fimLogico) return;

    // Ponteiro de navegação começa no item a ser removido
    int* p = posEndereco;
    
    // Loop move dados: *(p) recebe *(p+1)
    // Vai até o penúltimo elemento válido
    while (p < fimLogico - 1) {
        *p = *(p + 1);
        p++;
    }

    // Decrementa o tamanho do vetor
    (*tamAtual)--;
}