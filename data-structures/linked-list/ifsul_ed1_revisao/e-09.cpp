#include <iostream>
#include <fstream>
#include <string>
#include <clocale>

// Suas bibliotecas de módulos (ajuste os caminhos se necessário)
#include "../../modules/lista_dupla_template_plus.hpp"
#include "../../modules/utils_plus.hpp"

using namespace std;


// ============================================================================
// 2. FUNÇÕES LOCAIS / REGRAS DE NEGÓCIO DA QUESTÃO
// ============================================================================
// Escreva os algoritmos específicos solicitados pela questão aqui embaixo...


void inserirAntesDepois(Lista<int> *l, int valorBusca, int valorNovoNo) {
    // Salvaguarda para lista nula ou vazia
    if (l == nullptr || l->inicio == nullptr) {
        return;
    }

    No<int> *atual = l->inicio;

    while (atual != nullptr) {
        // Encontrou uma ocorrência do valor de busca
        if (atual->dado == valorBusca) {
            
            // 1. ALOCAÇÃO DOS DOIS NOVOS NÓS
            No<int> *novoAntes = new No<int>();
            No<int> *novoDepois = new No<int>();
            
            // Se faltar memória na Heap, limpamos o que foi alocado e abortamos
            if (!novoAntes || !novoDepois) {
                delete novoAntes;
                delete novoDepois;
                return;
            }

            novoAntes->dado = valorNovoNo;
            novoDepois->dado = valorNovoNo;

            // ----------------------------------------------------------------
            // 2. INSERÇÃO DO NÓ "ANTES"
            // ----------------------------------------------------------------
            novoAntes->prox = atual;
            novoAntes->ant = atual->ant;

            if (atual == l->inicio) {
                // Se o atual for o primeiro, o novoAntes vira o novo início
                l->inicio = novoAntes;
            } else {
                // Caso contrário, costura com o nó que vinha antes do atual
                atual->ant->prox = novoAntes;
            }
            atual->ant = novoAntes;
            l->tamanho++;

            // ----------------------------------------------------------------
            // 3. INSERÇÃO DO NÓ "DEPOIS"
            // ----------------------------------------------------------------
            novoDepois->ant = atual;
            novoDepois->prox = atual->prox;

            if (atual == l->fim) {
                // Se o atual for o último, o novoDepois vira o novo fim
                l->fim = novoDepois;
            } else {
                // Caso contrário, costura com o nó que vinha depois do atual
                atual->prox->ant = novoDepois;
            }
            atual->prox = novoDepois;
            l->tamanho++;

            // ----------------------------------------------------------------
            // 4. O PULO DO GATO: CONTROLE DE AVANÇO
            // ----------------------------------------------------------------
            // O ponteiro 'atual' agora tem um 'novoAntes' atrás dele e um 'novoDepois' na frente.
            // Para a próxima iteração, devemos saltar o 'novoDepois', indo direto para o prox dele.
            atual = novoDepois->prox;

        } else {
            // Se não encontrou o valor de busca neste nó, avança normalmente
            atual = atual->prox;
        }
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
    insereFimL(&lista1, 10);
    insereFimL(&lista1, 60);
    insereFimL(&lista1, 10);


    cout << "\n--- Estado Inicial da Lista ---\n";
    mostraL(&lista1); // Chama o operator<< para cada nó exibido
    
    

    // ------------------------------------------------------------------------
    // RESOLUÇÃO DA QUESTÃO (Desenvolva a chamada dos seus algoritmos aqui)
    // ------------------------------------------------------------------------
    
    inserirAntesDepois(&lista1,10, 100);
    cout << "\n--- Estado Final da Lista ---\n";
    mostraL(&lista1); // Chama o operator<< para cada nó exibido

    // ------------------------------------------------------------------------
    // FINALIZAÇÃO OBRIGATÓRIA (Liberação explícita dos nós alocados na Heap)
    // ------------------------------------------------------------------------
    destroiL(&lista1);

    return 0;
}