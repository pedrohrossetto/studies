/*
    Autor: Pedro H.C Rossetto
    Data: 13/10/2025
    Descrição: Utilize ponteiros para calcular maior elemento em um array e contar suas ocorrências.
    Algoritimos 2, Trabalho prático 9, Exercício 2
*/


#include <iostream>

using namespace std;

/**
 * @brief Encontra o maior elemento em um array e conta suas ocorrências.
 * * @param array Ponteiro para o início do array de inteiros.
 * @param tamanho O número de elementos no array.
 * @param ptr_maior Ponteiro para a variável que armazenará o maior elemento encontrado.
 * @param ptr_ocorrencias Ponteiro para a variável que armazenará o número de vezes que o maior elemento apareceu.
 * * A função percorre o array para identificar o maior valor. Ao encontrar um novo
 * maior valor, ela atualiza o ponteiro 'ptr_maior' e reinicia a contagem de ocorrências.
 * Se encontrar um número igual ao maior atual, apenas incrementa a contagem.
 * Por ser do tipo 'void', ela não retorna um valor diretamente, mas modifica as variáveis
 * na função 'main' através dos ponteiros.
 */
void encontrarMaiorEContar(int* array, int tamanho, int* ptr_maior, int* ptr_ocorrencias) {
    // 1. Validação inicial: se o array estiver vazio, não há o que fazer.
    if (tamanho <= 0) {
        *ptr_maior = 0;
        *ptr_ocorrencias = 0;
        return;
    }

    // 2. Inicializa as variáveis de resultado com os valores do primeiro elemento do array.
    *ptr_maior = array[0];
    *ptr_ocorrencias = 1;

    // 3. Percorre o array a partir do segundo elemento (índice 1).
    for (int i = 1; i < tamanho; i++) {
        // Se o elemento atual for maior que o maior já registrado...
        if (array[i] > *ptr_maior) {
            *ptr_maior = array[i]; // ...atualiza o maior valor...
            *ptr_ocorrencias = 1;  // ...e reinicia a contagem de ocorrências.
        } 
        // Se o elemento atual for igual ao maior já registrado...
        else if (array[i] == *ptr_maior) {
            (*ptr_ocorrencias)++; // ...apenas incrementa a contagem.
        }
    }
}

int main() {
    // Array de exemplo para o teste da função.
    int numeros[] = {5, 2, 15, 3, 7, 15, 8, 6, 15};
    
    // Calcula o tamanho do array dinamicamente.
    int tam_array = sizeof(numeros) / sizeof(numeros[0]);

    // Variáveis que receberão os resultados da função.
    int maiorElemento;
    int numeroDeOcorrencias;

    cout << "Analisando o array: ";
    for(int i = 0; i < tam_array; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    // Chama a função, passando o array, seu tamanho e os endereços das variáveis de resultado para que possam ser modificadas.
    encontrarMaiorEContar(numeros, tam_array, &maiorElemento, &numeroDeOcorrencias);


    cout << "\n--- Resultado ---\n";
    cout << "Maior elemento: " << maiorElemento << endl;
    cout << "Numero de ocorrencias: " << numeroDeOcorrencias << endl;
    cout << "-----------------\n";

    return 0;
}
