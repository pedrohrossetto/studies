/**
 * @brief Calcula o índice de um elemento baseando-se no endereço.
 * @param inicio Endereço inicial do vetor.
 * @param alvo Endereço do elemento encontrado.
 * @return Índice inteiro (0 a N).
 */
int util_calcularIndice(int* inicio, int* alvo) {
    // Em C++, subtração de ponteiros retorna a distância em "quantidade de elementos"
    // Ex: Se int ocupa 4 bytes e a diferença de endereço é 8 bytes, o resultado é 2.
    long diferenca = alvo - inicio;
    return (int)diferenca;
}