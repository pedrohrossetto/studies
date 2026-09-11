#include <iostream>
#include <fstream>

/**
 * @brief Lê inteiros de um arquivo para o vetor.
 * @return Quantidade de elementos lidos.
 */
int io_lerVetor(const char* nomeArquivo, int* vetor, int* capacidadeMax) {
    std::ifstream* entrada = new std::ifstream(nomeArquivo);
    
    // Contador alocado no heap
    int* qtdLida = new int(0);
    int* tempVal = new int;

    if (entrada->is_open()) {
        // Lê enquanto houver números e houver espaço
        while (*qtdLida < *capacidadeMax && *entrada >> *tempVal) {
            // Aritmética: vetor + deslocamento
            *(vetor + *qtdLida) = *tempVal;
            (*qtdLida)++;
        }
        entrada->close();
    } else {
        std::cout << "Erro ao abrir arquivo para leitura.\n";
    }

    int resultado = *qtdLida;
    
    delete entrada;
    delete qtdLida;
    delete tempVal;

    return resultado;
}