#include <iostream>

/**
 * @brief Intercala dois vetores em um terceiro (V1, V2 -> Destino).
 * O vetor destino deve ter tamanho suficiente (tam1 + tam2).
 */
void mod_intercalarVetores(int* v1, int* tam1, int* v2, int* tam2, int* vDestino) {
    int* p1 = v1;            // Leitura V1
    int* p2 = v2;            // Leitura V2
    int* pDest = vDestino;   // Escrita Destino
    
    int* fim1 = v1 + *tam1;
    int* fim2 = v2 + *tam2;

    // Enquanto houver elementos em ambos os vetores
    while (p1 < fim1 && p2 < fim2) {
        // Copia de V1
        *pDest = *p1;
        pDest++;
        p1++;

        // Copia de V2
        *pDest = *p2;
        pDest++;
        p2++;
    }

    // Se sobrou algo no V1, copia o resto
    while (p1 < fim1) {
        *pDest = *p1;
        pDest++;
        p1++;
    }

    // Se sobrou algo no V2, copia o resto
    while (p2 < fim2) {
        *pDest = *p2;
        pDest++;
        p2++;
    }
    
    // Não há variáveis locais para deletar neste caso, apenas ponteiros de navegação.
}