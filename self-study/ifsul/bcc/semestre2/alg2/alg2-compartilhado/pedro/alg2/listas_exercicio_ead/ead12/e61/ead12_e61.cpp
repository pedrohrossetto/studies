#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip> // Não utilizado, mas permitido
#include <cstdio>  // Não utilizado, mas permitido
#include <cstring> // Não utilizado, mas permitido
#include <cmath>   // Não utilizado, mas permitido

/*
 * NOTA: A restrição de "apenas ponteiros" continua.
 * 1. Nenhuma variável de pilha (ex: 'int i = 0;') é usada.
 * 2. Todas as "variáveis", incluindo contadores, são alocadas no heap
 * (ex: 'int* i = new int;') e acessadas via ponteiro (ex: '*i').
 * 3. Cada função agora gerencia (aloca e libera) seus próprios
 * ponteiros temporários.
 */

/**
 * @brief Gera 20 valores únicos entre 0-100 no vetor V.
 * @param V Ponteiro para o vetor principal.
 * @param size Ponteiro para o tamanho do vetor (20).
 * @param maxRand Ponteiro para o valor máximo do rand (101).
 */
void gerarValores(int* V, int* size, int* maxRand) {
    // Aloca os ponteiros temporários/contadores para esta função
    int* i = new int;
    int* j = new int;
    int* temp = new int;
    bool* duplicado = new bool;

    // Loop principal de preenchimento (de i=0 até i<20)
    for (*i = 0; *i < *size; (*i)++) {
        do {
            *duplicado = false;
            *temp = rand() % *maxRand; // Gera um novo valor (0-100)

            // Loop de verificação de duplicatas (de j=0 até j<i)
            for (*j = 0; *j < *i; (*j)++) {
                if (*(V + *j) == *temp) {
                    *duplicado = true;
                    break;
                }
            }
        } while (*duplicado); // Repete se o número já existia

        // Armazena o valor único
        *(V + *i) = *temp;
    }

    // Libera a memória temporária usada por esta função
    delete i;
    delete j;
    delete temp;
    delete duplicado;
}

/**
 * @brief Ordena o vetor V em ordem crescente (Bubble Sort).
 * @param V Ponteiro para o vetor principal.
 * @param size Ponteiro para o tamanho do vetor (20).
 */
void ordenarVetor(int* V, int* size) {
    // Aloca os ponteiros temporários/contadores para esta função
    int* i = new int;
    int* j = new int;
    int* temp = new int;

    // Loop externo (de i=0 até i<19)
    for (*i = 0; *i < *size - 1; (*i)++) {
        // Loop interno (de j=0 até j < 20-i-1)
        for (*j = 0; *j < *size - *i - 1; (*j)++) {
            
            // Compara V[j] com V[j+1]
            if (*(V + *j) > *(V + *j + 1)) {
                // Troca (swap)
                *temp = *(V + *j);
                *(V + *j) = *(V + *j + 1);
                *(V + *j + 1) = *temp;
            }
        }
    }

    // Libera a memória temporária usada por esta função
    delete i;
    delete j;
    delete temp;
}

/**
 * @brief Salva o conteúdo do vetor (endereço e valor) no arquivo.
 * @param V Ponteiro para o vetor principal.
 * @param size Ponteiro para o tamanho do vetor (20).
 * @param saida Ponteiro para o stream do arquivo de saída.
 */
void salvarArquivo(int* V, int* size, std::ofstream* saida) {
    // Aloca o contador para esta função
    int* i = new int;

    // Loop final para escrita (de i=0 até i<20)
    for (*i = 0; *i < *size; (*i)++) {
        // (V + *i) é o endereço
        // *(V + *i) é o valor
        *saida << (void*)(V + *i) << " – " << *(V + *i) << "\n";
    }

    // Libera a memória temporária
    delete i;
}


// --- Função Principal ---
int main() {
    
    // --- 1. Alocação dos ponteiros "principais" ---
    // Estes serão compartilhados entre as funções
    
    int* V = new int[20];
    int* size = new int;
    *size = 20;
    
    int* maxRand = new int;
    *maxRand = 101; // Para rand() % 101 (0-100)

    // Ponteiro para o objeto de arquivo
    std::ofstream* saida = new std::ofstream("exer_61.txt");

    // --- 2. Execução das Funções ---
    
    if (saida->is_open()) {
        
        // Passo 1: Preencher o vetor com valores únicos
        gerarValores(V, size, maxRand);
        
        // Passo 2: Ordenar o vetor
        ordenarVetor(V, size);
        
        // Passo 3: Escrever no arquivo
        salvarArquivo(V, size, saida);

        saida->close();
        std::cout << "Arquivo 'exer_61.txt' gerado com sucesso." << std::endl;
        
    } else {
        std::cout << "Erro: Nao foi possivel abrir o arquivo para escrita." << std::endl;
    }

    // --- 3. Limpeza da memória principal ---
    
    delete[] V; // Libera o array
    delete size;
    delete maxRand;
    delete saida; // Libera o objeto ofstream

    return 0;
}