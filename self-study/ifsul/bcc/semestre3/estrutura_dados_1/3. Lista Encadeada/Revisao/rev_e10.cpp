#include <iostream>
#include <fstream>
#include <string>
#include <clocale>

// Suas bibliotecas de módulos (ajuste os caminhos se necessário)
#include "../../modules/lista_descritor_template_plus.hpp"
#include "../../modules/utils_plus.hpp"

using namespace std;

// ============================================================================
// 2. FUNÇÕES LOCAIS / REGRAS DE NEGÓCIO DA QUESTÃO
// ============================================================================

/**
 * @brief Encontra o menor e o maior valor de uma lista estruturada e os troca de lugar.
 * @details Adaptado para utilizar o descritor de template da lista, mantendo a tipagem.
 * @param lista Ponteiro para o descritor da lista.
 */
void trocarMenorMaior(Lista<int> *lista) {
    // 1. VALIDAÇÃO: Se o descritor for nulo ou a lista estiver vazia, encerra
    if (lista == nullptr || lista->inicio == nullptr) {
        return;
    }

    // CORREÇÃO: Os nós devem ser declarados explicitamente com o tipo de template <int>
    No<int> *noMenor = lista->inicio;
    No<int> *noMaior = lista->inicio;
    No<int> *atual = lista->inicio->prox;

    // 2. VARREDURA: Encontra os nós que contêm o menor e o maior valor
    while (atual != nullptr) {
        if (atual->dado < noMenor->dado) {
            noMenor = atual;
        }
        if (atual->dado > noMaior->dado) {
            noMaior = atual;
        }
        atual = atual->prox;
    }

    // 3. TROCA (SWAP): Troca os valores internos se eles forem nós diferentes
    if (noMenor != noMaior) {
        int temp = noMenor->dado;
        noMenor->dado = noMaior->dado;
        noMaior->dado = temp;
    }
}

// ============================================================================
// 3. PROGRAMA PRINCIPAL
// ============================================================================
int main() {
    // Garante que a acentuação do português não quebre no terminal
    setlocale(LC_ALL, "Portuguese");

    // Inicialização das Estruturas Genéricas
    Lista<int> lista1;

    // Populando a lista
    insereFimL(&lista1, 10);
    insereFimL(&lista1, 20);
    insereFimL(&lista1, 30);
    insereFimL(&lista1, 40);
    insereFimL(&lista1, 50);
    insereFimL(&lista1, 60);

    cout << "\n--- Estado Inicial da Lista ---\n";
    mostraL(&lista1); 
    
    // CORREÇÃO: Agora passamos o endereço do descritor de forma limpa e compatível
    trocarMenorMaior(&lista1);

    cout << "\n--- Estado Final da Lista ---\n";
    mostraL(&lista1); 

    // Finalização obrigatória
    destroiL(&lista1);

    return 0;
}