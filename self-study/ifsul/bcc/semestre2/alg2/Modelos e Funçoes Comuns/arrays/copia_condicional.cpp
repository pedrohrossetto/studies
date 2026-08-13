#include <iostream>

/**
 * @brief Copia valores menores que 'corte' do vetor origem para o destino.
 * @param origem Vetor com os dados brutos.
 * @param tamOrigem Tamanho do vetor origem.
 * @param destino Vetor já alocado que receberá os dados.
 * @param corte Valor de referência (ex: média).
 * @return Quantidade de elementos copiados.
 */
int alg_filtrarMenores(int* origem, int* tamOrigem, int* destino, int* corte) {
    int* pLeitura = origem;
    int* pFim     = origem + *tamOrigem;
    int* pEscrita = destino;
    
    int* contador = new int(0);

    while (pLeitura < pFim) {
        // Se valor atual for menor que o corte
        if (*pLeitura < *corte) {
            // Copia o valor para o destino
            *pEscrita = *pLeitura;
            
            // Avança ponteiro de escrita e contador
            pEscrita++;
            (*contador)++;
        }
        // Avança ponteiro de leitura
        pLeitura++;
    }

    int qtdCopiada = *contador;
    delete contador;
    return qtdCopiada;
}