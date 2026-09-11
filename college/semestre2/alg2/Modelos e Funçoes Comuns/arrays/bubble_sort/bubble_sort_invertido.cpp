#include <iostream>

/**
 * @brief Ordena um vetor em ordem DECRESCENTE (Maior -> Menor).
 */
void alg_ordenarDecrescente(int* vetor, int* tamanho) {
    int* i = new int;
    int* j = new int;
    int* temp = new int;

    for (*i = 0; *i < *tamanho - 1; (*i)++) {
        for (*j = 0; *j < *tamanho - *i - 1; (*j)++) {
            
            int* atual   = (vetor + *j);
            int* proximo = (vetor + *j + 1);

            // MUDANÇA AQUI: Se atual < proximo, troca (para ficar decrescente)
            if (*atual < *proximo) {
                *temp    = *atual;
                *atual   = *proximo;
                *proximo = *temp;
            }
        }
    }

    delete i; delete j; delete temp;
}