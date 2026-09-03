#include "../modules/arvore-binaria.hpp"
#include "../modules/graphviz_bintree.hpp"
#include "../modules/menu_funcoes.hpp"
#include "../modules/utils_plus.hpp"
#include <iostream>



int main() {
    limpar_tela();
    TreeNode* root = nullptr;
    bool rodando = true;

    ListaMenuAcao acoes = lista_criar();

    lista_adicionar(acoes, {"Sair", [&]() {
        rodando = false;
    }});

    lista_adicionar(acoes, {"Inserir", [&]() {
        int val = lerInteiroValido("Valor: ");
        tree_insert(root, val);
        std::cout << "Inserido.\n";
    }});

    lista_adicionar(acoes, {"Inserir randomizada", [&]() {
        int lim_min = lerInteiroValido("Limite Menor: ");
        int lim_max = lerInteiroValido("Limite Maior: ");
        tree_insert_random(root, lim_min, lim_max);
        std::cout << "Inserido.\n";
    }});

    lista_adicionar(acoes, {"Inserir lista randomizada", [&]() {
        int qtd_val = lerInteiroValido("Quantidade de inserções: ");
        int lim_min = lerInteiroValido("Limite Menor: ");
        int lim_max = lerInteiroValido("Limite Maior: ");
        tree_fill_random(root, qtd_val, lim_min, lim_max);
        std::cout << "Inserido.\n";
    }});

    lista_adicionar(acoes, {"Buscar nó", [&]() {
        int val = lerInteiroValido("Valor: ");
        if (node_search(root, val)) {
            std::cout << "Encontrado.\n";
        } else {
            std::cout << "Não encontrado.\n";
        }
    }});

    lista_adicionar(acoes, {"Buscar nó e sua altura", [&]() {
        int val = lerInteiroValido("Valor: ");
        int height = node_height_search(root, val);
        if (height != -1) {
            std::cout << "Encontrado. Altura: " << height << "\n";
        } else {
            std::cout << "Não encontrado.\n";
        }
    }});

    lista_adicionar(acoes, {"Remover Node", [&]() {
        int val = lerInteiroValido("Valor: ");
        node_delete(root, val);
        std::cout << "Remoção tentada.\n";
    }});

    lista_adicionar(acoes, {"Limpar Árvore", [&]() {
        tree_clear(root);
        std::cout << "Árvore Excluída.\n";
    }});

    lista_adicionar(acoes, {"Exibir in-ordem", [&]() {
        tree_walk_inorder(root);
        std::cout << "\n";
    }});

    lista_adicionar(acoes, {"Exibir pré-ordem", [&]() {
        tree_walk_preorder(root);
        std::cout << "\n";
    }});

    lista_adicionar(acoes, {"Exibir pós-ordem", [&]() {
        tree_walk_postorder(root);
        std::cout << "\n";
    }});

    lista_adicionar(acoes, {"Predecessor do nó", [&]() {
        std::cout << node_predecessor(root)->val;
    }});

    lista_adicionar(acoes, {"Sucessor do nó", [&]() {
        std::cout << node_sucessor(root)->val;
    }});

    lista_adicionar(acoes, {"Maior Valor da Árvore", [&]() {
        std::cout << tree_max(root)->val;
    }});

    lista_adicionar(acoes, {"Menor Valor da Árvore", [&]() {
        std::cout << tree_min(root)->val;
    }});

    lista_adicionar(acoes, {"Soma dos elementos da Árvore", [&]() {
        std::cout << tree_sum(root);
    }});

    lista_adicionar(acoes, {"Soma dos elementos da Árvore (condicional)", [&]() {
        int min = lerInteiroValido("Informe o limite minimo do intervalo de soma: ");
        int max = lerInteiroValido("Informe o limite máximo do intervalo de soma: ");
        std::cout << tree_sum_conditional(root, min, max);
    }});

    lista_adicionar(acoes, {"Altura da Árvore", [&]() {
        std::cout << tree_height(root);
    }});

    lista_adicionar(acoes, {"Tamanho da Árvore", [&]() {
        std::cout << tree_size(root);
    }});

    lista_adicionar(acoes, {"Estatísticas Compiladas", [&]() {
        tree_stats(root);
    }});

    lista_adicionar(acoes, {"Exportar DOT/PNG", [&]() {
        export_to_dot(root, "arvore.dot");
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
    lista_liberar(acoes);
    return 0;
}
