#include "../modules/arvore-binaria.hpp"
#include "../modules/arvore-randomizada.hpp"
#include "../modules/graphviz_bintree.hpp"
#include "../modules/menu_funcoes.hpp"
#include "../modules/utils_plus.hpp"
#include <iostream>
#include <vector>

static void mostrar_estatisticas(const char* titulo, BinTreeNode* tree) {
    std::cout << titulo
              << "  nos=" << tree_size(tree)
              << "  altura=" << tree_height(tree)
              << "  balance=" << tree_balance(tree)
              << "\n  in-ordem: ";
    tree_walk_inorder(tree);
    std::cout << "\n";
}

int main() {
    BinTreeNode* root = nullptr;
    bool rodando = true;

    std::vector<MenuAcao> acoes;

    acoes.push_back({"Sair", [&]() {
        rodando = false;
    }});

    acoes.push_back({"Inserir (BST)", [&]() {
        int val = lerInteiroValido("Valor: ");
        tree_insert(root, val);
        std::cout << "Inserido.\n";
    }});

    acoes.push_back({"Inserir randomizada 1/(n+1)", [&]() {
        int val = lerInteiroValido("Valor: ");
        tree_insert_randomized(root, val);
        std::cout << "Inserido.\n";
    }});

    acoes.push_back({"Inserir como raiz (rotações)", [&]() {
        int val = lerInteiroValido("Valor: ");
        tree_insert(root, val);
        std::cout << "Inserido na raiz.\n";
    }});

    acoes.push_back({"Buscar", [&]() {
        int val = lerInteiroValido("Valor: ");
        if (node_search(root, val)) {
            std::cout << "Encontrado.\n";
        } else {
            std::cout << "Não encontrado.\n";
        }
    }});

    acoes.push_back({"Remover", [&]() {
        int val = lerInteiroValido("Valor: ");
        node_delete(root, val);
        std::cout << "Remoção tentada.\n";
    }});

    acoes.push_back({"Exibir in-ordem", [&]() {
        tree_walk_inorder(root);
        std::cout << "\n";
    }});

    acoes.push_back({"Exibir pré-ordem", [&]() {
        tree_walk_preorder(root);
        std::cout << "\n";
    }});

    acoes.push_back({"Exibir pós-ordem", [&]() {
        tree_walk_postorder(root);
        std::cout << "\n";
    }});

    acoes.push_back({"Estatísticas", [&]() {
        mostrar_estatisticas("árvore atual", root);
    }});

    acoes.push_back({"Preencher 1..n sequencial", [&]() {
        int n = lerInteiroValido("n: ");
        tree_fill_sequential(root, n);
        std::cout << "Preenchido.\n";
    }});

    acoes.push_back({"Preencher 1..n embaralhado", [&]() {
        int n = lerInteiroValido("n: ");
        tree_fill_range_shuffled(root, n);
        std::cout << "Preenchido.\n";
    }});

    acoes.push_back({"Preencher 1..n randomizado", [&]() {
        int n = lerInteiroValido("n: ");
        tree_fill_range_randomized(root, n);
        std::cout << "Preenchido.\n";
    }});

    acoes.push_back({"Preencher n aleatórios [min, max]", [&]() {
        int n = lerInteiroValido("n: ");
        int min_val = lerInteiroValido("min: ");
        int max_val = lerInteiroValido("max: ");
        if (min_val > max_val) {
            std::cout << "min maior que max.\n";
            return;
        }
        tree_fill_random(root, n, min_val, max_val);
        std::cout << "Preenchido.\n";
    }});

    acoes.push_back({"Limpar árvore", [&]() {
        tree_clear(root);
        std::cout << "Árvore vazia.\n";
    }});

    acoes.push_back({"Exportar DOT/PNG", [&]() {
        export_to_dot(root, "arvore.dot");
    }});

    acoes.push_back({"Comparar sequencial / embaralhada / randomizada", [&]() {
        int n = lerInteiroValido("n: ");
        BinTreeNode* sequencial = nullptr;
        BinTreeNode* embaralhada = nullptr;
        BinTreeNode* randomizada = nullptr;
        tree_fill_sequential(sequencial, n);
        tree_fill_range_shuffled(embaralhada, n);
        tree_fill_range_randomized(randomizada, n);
        mostrar_estatisticas("BST sequencial", sequencial);
        mostrar_estatisticas("BST embaralhada", embaralhada);
        mostrar_estatisticas("BST randomizada", randomizada);
        tree_clear(sequencial);
        tree_clear(embaralhada);
        tree_clear(randomizada);
    }});

    while (rodando) {
        limpar_tela();
        std::cout << "Árvore (índice = função)\n";
        desenharLinha();
        menu_listar(acoes);
        desenharLinha();
        int indice = lerInteiroValido("Índice: ");
        limpar_tela();
        menu_executar(acoes, indice);
        if (rodando) {
            pausar_e_limpar();
        }
    }

    tree_clear(root);
    return 0;
}
