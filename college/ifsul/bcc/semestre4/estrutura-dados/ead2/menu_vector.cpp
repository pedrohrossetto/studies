#include "../modules/arvore-binaria.hpp"
#include "../modules/graphviz_bintree.hpp"
#include "../modules/menu_funcoes.hpp"
#include "../modules/utils_plus.hpp"
#include <iostream>
#include <vector>



int main() {
    limpar_tela();
    BinTreeNode* root = nullptr;
    bool rodando = true;

    std::vector<MenuAcao> acoes;

    acoes.push_back({"Sair", [&]() {
        rodando = false;
    }});

    acoes.push_back({"Inserir", [&]() {
        int val = lerInteiroValido("Valor: ");
        tree_insert(root, val);
        std::cout << "Inserido.\n";
    }});

    acoes.push_back({"Inserir randomizada", [&]() {
        int lim_min = lerInteiroValido("Limite Menor: ");
        int lim_max = lerInteiroValido(("Limite Maior: "));
        tree_insert_random(root, lim_min,lim_max);
        std::cout << "Inserido.\n";
    }});

    acoes.push_back({"Inserir lista randomizada", [&]() {
        int qtd_val = lerInteiroValido("Quantidade de inserções: ");
        int lim_min = lerInteiroValido("Limite Menor: ");
        int lim_max = lerInteiroValido(("Limite Maior: "));
        tree_fill_random(root,qtd_val, lim_min,lim_max);
        std::cout << "Inserido.\n";
    }});

    acoes.push_back({"Buscar", [&]() {
        int val = lerInteiroValido("Valor: ");
        if (node_search(root, val)) {
            std::cout << "Encontrado.\n";
        } else {
            std::cout << "Não encontrado.\n";
        }
    }});

    acoes.push_back({"Remover Node", [&]() {
        int val = lerInteiroValido("Valor: ");
        node_delete(root, val);
        std::cout << "Remoção tentada.\n";
    }});

    acoes.push_back({"Limpar Árvore", [&](){
        tree_clear(root);
        std::cout << "Árvore Excluída.\n";
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

    acoes.push_back({"Predecessor do nó",[&](){
        node_predecessor(root);
    }});

    acoes.push_back({"Sucessor do nó",[&](){
        node_sucessor(root);
    }});

    acoes.push_back({"Maior Valor da Árvore",[&](){
        tree_max(root);
    }});

    acoes.push_back({"Menor Valor da Árvore",[&](){
        tree_min(root);
    }});

    acoes.push_back({"Altura da Árvore",[&](){
        tree_height(root);
    }});

    acoes.push_back({"Tamanho da Árvore",[&](){
        tree_size(root);
    }});


    acoes.push_back({"Estatísticas Compiladas", [&]() {
        tree_stats(root);
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
