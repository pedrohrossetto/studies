#include <iostream>
#include <fstream>
#include <string>
#include <clocale>

// Suas bibliotecas de módulos (ajuste os caminhos se necessário)
#include "../../modules/lista_descritor_template_plus.hpp"
#include "../../modules/utils.hpp"

using namespace std;

// ============================================================================
// 1. DEFINIÇÃO DA STRUCT COM ARSENAL DE OPERADORES COMPLETO
// ============================================================================
struct Elemento {
    int id;
    string nome;
    // Adicione outros campos aqui conforme o enunciado...

    // Construtor Completo
    Elemento(int _id, string _nome) : id(_id), nome(_nome) {}

    // Construtor Padrão (Obrigatório para inicialização de nós vazios no seu template)
    Elemento() : id(0), nome("") {}

    // --- SEÇÃO DE SOBRECARGA DE OPERADORES ---

    // Sobrecarga de Igualdade (Obrigatório para sua função MostrarInterseccao)
    bool operator==(const Elemento& outro) const {
        return this->id == outro.id; // Altere o critério se a igualdade for por nome, etc.
    }

    // Sobrecarga de Desigualdade (Reutiliza o operador de igualdade negando-o)
    bool operator!=(const Elemento& outro) const {
        return !(*this == outro);
    }

    // Sobrecarga de Comparação / Ordenação (Útil para buscar menor/maior ou ordenar)
    bool operator<(const Elemento& outro) const {
        return this->id < outro.id; // Altere para 'this->nome < outro.nome' se for ordem alfabética
    }

    // Sobrecarga de Saída (Diz ao std::cout ou fstream como formatar e exibir o objeto)
    friend ostream& operator<<(ostream& os, const Elemento& e) {
        os << "[ID: " << e.id << " | Nome: " << e.nome << "]";
        return os;
    }

    // Sobrecarga de Entrada (Permite ler o objeto direto via 'cin >> seu_objeto' ou de arquivos)
    friend istream& operator>>(istream& is, Elemento& e) {
        cout << "Digite o ID: ";
        is >> e.id;
        is.ignore(); // Limpa o caractere de nova linha '\n' residual do buffer
        cout << "Digite o Nome: ";
        getline(is, e.nome);
        return is;
    }
};

// ============================================================================
// 2. FUNÇÕES LOCAIS / REGRAS DE NEGÓCIO DA QUESTÃO
// ============================================================================
// Escreva os algoritmos específicos solicitados pela questão aqui


// ============================================================================
// 3. PROGRAMA PRINCIPAL
// ============================================================================
int main() {
    // Garante que a acentuação do português não quebre no terminal
    setlocale(LC_ALL, "Portuguese");

    // Inicialização das Estruturas Genéricas
    Lista<Elemento> lista1;
    Lista<Elemento> lista2;

    // ------------------------------------------------------------------------
    // CÓDIGO DE TESTE (Exemplo de uso das novas sobrecargas)
    // ------------------------------------------------------------------------
    Elemento e1;
    
    cout << "--- Cadastro de Elemento via Sobrecarga de Entrada ---\n";
    cin >> e1; // Chama a lógica interna do operator>> automaticamente

    insereFimL(&lista1, e1);

    cout << "\n--- Estado Inicial da Lista ---\n";
    mostraL(&lista1); // Chama o operator<< para cada nó exibido

    // ------------------------------------------------------------------------
    // RESOLUÇÃO DA QUESTÃO (Desenvolva a chamada dos seus algoritmos aqui)
    // ------------------------------------------------------------------------
    


    // ------------------------------------------------------------------------
    // FINALIZAÇÃO OBRIGATÓRIA (Liberação explícita dos nós alocados na Heap)
    // ------------------------------------------------------------------------
    destroiL(&lista1);
    destroiL(&lista2);

    return 0;
}