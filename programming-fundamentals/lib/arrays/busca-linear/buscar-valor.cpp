#include <iostream>

/*
 * Função Modular: Busca Linear com Ponteiros
 * Retorna: true se encontrar, false se não encontrar
 */
bool contemValor(int* vetor, int* tamanho, int* valorBusca) {
    // Define os limites do loop usando aritmética de ponteiros
    int* p = vetor;
    int* fim = vetor + *tamanho;

    while (p < fim) {
        // Compara o VALOR apontado (*) por p com o VALOR buscado
        if (*p == *valorBusca) {
            return true;
        }
        p++; // Avança para o próximo endereço de memória
    }

    return false;
}