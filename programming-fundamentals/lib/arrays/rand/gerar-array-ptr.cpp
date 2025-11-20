#include <iostream>
using namespace std;

// Preenche o vetor usando estritamente aritmetica de ponteiros

void gerarAleatorioPonteiros(int* vetor, int* tamanho, int* min, int* max) {
    // Ponteiro 'atual' percorrera o vetor do inicio ate o fim
    // (vetor + *tamanho) calcula o endereco final
    for (int* atual = vetor; atual < (vetor + *tamanho); atual++) {
        bool existe;
        int novoNumero;

        do {
            existe = false;
            // Acessamos os valores de min e max com *
            novoNumero = *min + (rand() % (*max - *min + 1));

            // Ponteiro 'verificador' percorre do inicio ate a posicao 'atual'
            for (int* verificador = vetor; verificador < atual; verificador++) {
                // Compara o valor apontado pelo verificador com o novoNumero
                if (*verificador == novoNumero) {
                    existe = true;
                    break;
                }
            }
        } while (existe);

        // Grava o valor no endereco apontado por 'atual'
        *atual = novoNumero;
    }
    
    cout << "Vetor gerado (Modo Ponteiro) com sucesso!" << endl;
}