#include <iostream>

/*
 * Função Modular: Inserir valor na primeira posição livre (Final)
 * Parâmetros:
 * - vetor: Ponteiro para o início do array
 * - qtdAtual: Ponteiro para a contagem atual de elementos
 * - capacidade: Ponteiro para o tamanho máximo do array
 * - valor: Ponteiro para o valor a ser inserido
 * Retorno: true se inseriu, false se o vetor estiver cheio
 */
bool inserirValorFinal(int* vetor, int* qtdAtual, int* capacidade, int* valor) {
    // Verifica se há espaço (Overflow check)
    if (*qtdAtual >= *capacidade) {
        return false; 
    }

    // Calcula o endereço de destino: Base + Deslocamento
    int* pDestino = vetor + *qtdAtual;
    
    // Grava o valor
    *pDestino = *valor;

    // Incrementa a quantidade de elementos
    // Nota: Parênteses (*qtdAtual) são obrigatórios devido à precedência
    (*qtdAtual)++;

    return true;
}