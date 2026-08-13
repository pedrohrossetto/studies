#include <iostream>

/**
 * @brief Varre a matriz e retorna o ENDEREÇO do maior valor encontrado.
 * @param outEnderecoMaior (Saída) Ponteiro que receberá o endereço do maior valor.
 */
void mat_encontrarMaiorEndereco(int** mat, int* linhas, int* colunas, int** outEnderecoMaior) {
    int** pLinha = mat;
    int** fimLinhas = mat + *linhas;

    // Inicializa o 'maior' com o endereço do primeiro elemento [0][0]
    *outEnderecoMaior = *mat; 

    while (pLinha < fimLinhas) {
        int* pElemento = *pLinha;
        int* fimColunas = pElemento + *colunas;

        while (pElemento < fimColunas) {
            
            // Compara o VALOR apontado pelo cursor atual 
            // com o VALOR apontado pelo "maior" salvo até agora
            if (*pElemento > **outEnderecoMaior) {
                *outEnderecoMaior = pElemento; // Salva o novo endereço
            }

            pElemento++; // Move o ponteiro
        }
        pLinha++;
    }
}