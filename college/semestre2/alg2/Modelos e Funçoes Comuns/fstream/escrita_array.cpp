#include <iostream>
#include <fstream>

/**
 * @brief Salva o vetor em arquivo txt.
 * @param nomeArquivo String com nome do arquivo (ex: "saida.txt")
 */
void io_salvarVetor(const char* nomeArquivo, int* vetor, int* tamanho) {
    // Aloca objeto ofstream dinamicamente
    std::ofstream* saida = new std::ofstream(nomeArquivo);

    if (saida->is_open()) {
        int* p = vetor;
        int* fim = vetor + *tamanho;

        while (p < fim) {
            // Escreve: Valor [quebra de linha]
            *saida << *p << "\n";
            p++;
        }

        saida->close();
        std::cout << "Arquivo salvo com sucesso.\n";
    } else {
        std::cout << "Erro ao abrir arquivo para escrita.\n";
    }

    // Importante: destrói o objeto e fecha o arquivo se estiver aberto
    delete saida; 
}