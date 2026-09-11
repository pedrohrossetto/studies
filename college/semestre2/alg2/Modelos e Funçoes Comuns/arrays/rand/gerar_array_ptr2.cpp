#include <iostream>
#include <cstdlib> // rand, srand

/**
 * @brief Preenche vetor com valores únicos entre min e max.
 */
void alg_gerarAleatorioUnico(int* vetor, int* tamanho, int* min, int* max) {
    int* pInicio = vetor;
    int* pFim    = vetor + *tamanho;
    
    // Auxiliares no Heap
    int* gerado  = new int;
    bool* existe = new bool;
    int* pCheck  = new int; // Usado como iterador interno (não como ponteiro de dados)

    for (int* pAtual = pInicio; pAtual < pFim; pAtual++) {
        do {
            *existe = false;
            // Fórmula: min + (rand % (max - min + 1))
            *gerado = *min + (rand() % (*max - *min + 1));

            // Verifica duplicidade percorrendo do início até a posição atual
            for (int* pVarredura = pInicio; pVarredura < pAtual; pVarredura++) {
                if (*pVarredura == *gerado) {
                    *existe = true;
                    break;
                }
            }
        } while (*existe);

        *pAtual = *gerado;
    }

    delete gerado;
    delete existe;
    delete pCheck;
}