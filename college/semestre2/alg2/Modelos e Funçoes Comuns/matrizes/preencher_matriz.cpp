#include <iostream>

/**
 * @brief Preenche toda a matriz com um valor especifico.
 * Técnica: Movimento de ponteiro (Cursor).
 */
void mat_preencherMatriz(int** mat, int* linhas, int* colunas, int* valorPadrao) {
    // Cursor para percorrer o array de linhas (int**)
    int** pLinhaAtual = mat;
    int** pFimLinhas  = mat + *linhas;

    // Loop Externo: Avança de linha em linha
    while (pLinhaAtual < pFimLinhas) {
        
        // Dereferencia a linha atual para pegar o começo do array de inteiros
        int* pElemento = *pLinhaAtual;
        int* pFimColuna = pElemento + *colunas;

        // Loop Interno: Avança elemento por elemento NAQUELA linha
        while (pElemento < pFimColuna) {
            *pElemento = *valorPadrao;
            
            // MOVIMENTO DO PONTEIRO: Avança para o próximo int
            pElemento++; 
        }

        // MOVIMENTO DO PONTEIRO: Avança para a próxima linha
        pLinhaAtual++;
    }
}