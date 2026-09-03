#include "../modules/arvore-binaria-avl_ia.hpp"
#include "../modules/graphviz_bintree.hpp"
#include "../modules/menu_funcoes.hpp"
#include "../modules/utils_plus.hpp"
#include <iostream>
#include <vector>



int main() {
    limpar_tela();
    AVLNode* root = nullptr;
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
        if (is_empty(root)) { std::cout << "Árvore vazia.\n"; return; }
        AVLNode* pred = node_predecessor(root);
        std::cout << (pred ? std::to_string(pred->val) : "Nenhum") << "\n";
    }});

    acoes.push_back({"Sucessor do nó",[&](){
        if (is_empty(root)) { std::cout << "Árvore vazia.\n"; return; }
        AVLNode* suc = node_sucessor(root);
        std::cout << (suc ? std::to_string(suc->val) : "Nenhum") << "\n";
    }});

    acoes.push_back({"Maior Valor da Árvore",[&](){
        if (is_empty(root)) { std::cout << "Árvore vazia.\n"; return; }
        std::cout << tree_max(root)->val << "\n";
    }});

    acoes.push_back({"Menor Valor da Árvore",[&](){
        if (is_empty(root)) { std::cout << "Árvore vazia.\n"; return; }
        std::cout << tree_min(root)->val << "\n";
    }});

    acoes.push_back({"Soma dos elementos da Árvore",[&](){
        std::cout << tree_sum(root);
    }});

    acoes.push_back({"Soma dos elementos da Árvore (condicional)",[&](){
        int min = lerInteiroValido("Informe o limite minimo do intervalo de soma: ");
        int max = lerInteiroValido("Informe o limite máximo do intervalo de soma: ");
        std::cout << tree_sum_conditional(root,min,max);
    }});

    acoes.push_back({"Altura da Árvore",[&](){
        std::cout << avl_height(root) << "\n";
    }});

    acoes.push_back({"Tamanho da Árvore",[&](){
        std::cout << tree_size(root) << "\n";
    }});

    acoes.push_back({"Fator de Balanceamento",[&](){
        if (is_empty(root)) { std::cout << "Árvore vazia.\n"; return; }
        std::cout << avl_balance(root) << "\n";
    }});


    acoes.push_back({"Estatísticas Compiladas", [&]() {
        if (is_empty(root)) { std::cout << "Árvore vazia.\n"; return; }
        avl_stats(root);
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
