#include <iostream>

/**
 * @brief Insere valor. Se cheio, zera o vetor e insere no início.
 * @param vetor Ponteiro para o array.
 * @param tamAtual Ponteiro para quantidade atual.
 * @param capacidade Ponteiro para capacidade máxima.
 * @param valor Ponteiro para o valor a inserir.
 */
void alg_inserirOuResetar(int* vetor, int* tamAtual, int* capacidade, int* valor) {
    // Lógica de "Vetor Cheio -> Zerar"
    if (*tamAtual >= *capacidade) {
        std::cout << "[INFO]: Vetor cheio. Resetando..." << std::endl;
        *tamAtual = 0; // Apenas resetamos o contador lógico
    }

    // Inserção Padrão (Agora garantido que tem espaço)
    // Endereço base + deslocamento
    int* pDestino = vetor + *tamAtual;
    *pDestino = *valor;

    // Incrementa contador
    (*tamAtual)++;
}