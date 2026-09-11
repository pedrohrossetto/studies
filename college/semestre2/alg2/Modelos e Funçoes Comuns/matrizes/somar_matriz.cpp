#include <iostream>

/**
 * @brief Soma MatA + MatB = MatC movendo 3 cursores simultaneamente.
 */
void mat_somarMatrizes(int** matA, int** matB, int** matC, int* linhas, int* colunas) {
    // Cursores para os arrays de ponteiros (linhas)
    int** cursorLinhaA = matA;
    int** cursorLinhaB = matB;
    int** cursorLinhaC = matC;
    
    int** fimLinhas = matA + *linhas;

    while (cursorLinhaA < fimLinhas) {
        // Pega o início da linha atual para cada matriz
        int* pA = *cursorLinhaA;
        int* pB = *cursorLinhaB;
        int* pC = *cursorLinhaC;
        
        int* fimColunas = pA + *colunas;

        // Percorre as colunas sincronizadamente
        while (pA < fimColunas) {
            // Aritmética pura nos valores
            *pC = *pA + *pB;

            // MOVIMENTO DOS PONTEIROS (Marcha sincronizada)
            pA++;
            pB++;
            pC++;
        }

        // Avança para a próxima linha nas 3 matrizes
        cursorLinhaA++;
        cursorLinhaB++;
        cursorLinhaC++;
    }
}