#include <iostream>

/**
 * @brief Procura um valor no vetor.
 * @return true se encontrado, false caso contrário.
 */
bool alg_buscaLinear(int* vetor, int* tamanho, int* valorBusca) {
    // Ponteiros de navegação
    int* p = vetor;
    int* fim = vetor + *tamanho;
    
    // Flag de retorno no Heap (opcional, poderia retornar direto)
    bool* encontrado = new bool(false);

    while (p < fim) {
        if (*p == *valorBusca) {
            *encontrado = true;
            break; 
        }
        p++; // Avança para o próximo endereço
    }

    bool resultado = *encontrado;
    delete encontrado;
    return resultado;
}