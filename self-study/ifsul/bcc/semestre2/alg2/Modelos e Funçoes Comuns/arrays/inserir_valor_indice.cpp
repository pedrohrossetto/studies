/*
 * Função Modular: Inserir valor em uma posição específica (empurra os outros)
 */
bool inserirValorPosicao(int* vetor, int* qtdAtual, int* capacidade, int* valor, int* posicao) {
    // Verifica espaço e validade da posição
    if (*qtdAtual >= *capacidade) return false;
    if (*posicao < 0 || *posicao > *qtdAtual) return false;

    // Ponteiros para movimentação de memória (Shift Right)
    // Começa do último elemento válido e vem voltando até a posição desejada
    int* pAtual = vetor + *qtdAtual;       // Posição vazia no final
    int* pAlvo  = vetor + *posicao;        // Onde queremos inserir

    // Move os dados para a direita
    while (pAtual > pAlvo) {
        *pAtual = *(pAtual - 1); // Copia o anterior para o atual
        pAtual--;
    }

    // Insere o novo valor no buraco aberto
    *pAlvo = *valor;

    // Atualiza tamanho
    (*qtdAtual)++;

    return true;
}