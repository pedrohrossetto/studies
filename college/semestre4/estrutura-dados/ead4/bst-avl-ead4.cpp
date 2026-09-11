#include "../modules/arvore-binaria-avl.hpp"
#include "../modules/graphviz_bintree.hpp"
#include "../modules/menu_funcoes.hpp"
#include "../modules/utils_plus.hpp"
#include "../modules/text_files_plus.hpp"

#include <iostream>

int main() {
    limpar_tela();
    AVLNode* root = nullptr;
    bool rodando = true;

    ListaMenuAcao acoes = lista_criar();

    lista_adicionar(acoes, {"Sair", [&]() {
        rodando = false;
    }});

    lista_adicionar(acoes, {"Q1 — Inserir sequência AVL e mostrar árvore resultante", [&]() {
        tree_clear(root);
        avl_set_rotation_trace(true);
        int lista[] = {53, 26, 14, 7, 30, 36, 23, 86, 35, 18, 40, 25, 90};
        for (int v : lista) {
            std::cout << "Inserindo " << v << "\n";
            tree_insert(root, v);
        }
        avl_set_rotation_trace(false);
        std::cout << "Árvore resultante em pré-ordem: ";
        tree_walk_preorder(root);
        std::cout << "\n";
        export_to_dot(root, "arvore_q1");
    }});

    lista_adicionar(acoes, {"Q2 — Inserir, remover e inserir de novo", [&]() {
        tree_clear(root);
        avl_set_rotation_trace(true);
        int lista[] = {4, 2, 3, 10, 9, 5};
        for (int v : lista) {
            std::cout << "Inserindo " << v << "\n";
            tree_insert(root, v);
        }
        std::cout << "Árvore original em pré-ordem: ";
        tree_walk_preorder(root);
        std::cout << "\n";

        std::cout << "Removendo 2\n";
        node_delete(root, 2);
        std::cout << "Inserindo 7\n";
        tree_insert(root, 7);
        std::cout << "Inserindo 16\n";
        tree_insert(root, 16);
        std::cout << "Inserindo 20\n";
        tree_insert(root, 20);
        std::cout << "Removendo 4\n";
        node_delete(root, 4);
        std::cout << "Removendo 9\n";
        node_delete(root, 9);

        avl_set_rotation_trace(false);
        std::cout << "Árvore resultante em pré-ordem: ";
        tree_walk_preorder(root);
        std::cout << "\n";
        export_to_dot(root, "arvore_q2");
    }});

    lista_adicionar(acoes, {"Q3 — Inserir e conferir rotações (LR depois LL)", [&]() {
        tree_clear(root);
        avl_set_rotation_trace(true);
        int lista[] = {47, 35, 40, 32, 42, 30};
        for (int v : lista) {
            std::cout << "Inserindo " << v << "\n";
            tree_insert(root, v);
        }
        avl_set_rotation_trace(false);
        std::cout << "Árvore resultante em pré-ordem: ";
        tree_walk_preorder(root);
        std::cout << "\n";
        std::cout << "Confira as rotações impressas. Esperado: LR ao inserir 40, LL ao inserir 30.\n";
        export_to_dot(root, "arvore_q3");
    }});

    lista_adicionar(acoes, {"Q4 — Mix insert/delete com rotações", [&]() {
        tree_clear(root);
        avl_set_rotation_trace(true);
        int lista[] = {30, 25, 15, 45, 41, 35, 43, 56, 50};
        for (int v : lista) {
            std::cout << "Inserindo " << v << "\n";
            tree_insert(root, v);
        }
        std::cout << "Árvore original em pré-ordem: ";
        tree_walk_preorder(root);
        std::cout << "\n";

        std::cout << "Exclusão de 45\n";
        node_delete(root, 45);
        std::cout << "Exclusão de 25\n";
        node_delete(root, 25);
        std::cout << "Inserção de 12\n";
        tree_insert(root, 12);
        std::cout << "Inserção de 42\n";
        tree_insert(root, 42);
        std::cout << "Inserção de 38\n";
        tree_insert(root, 38);
        std::cout << "Exclusão de 41\n";
        node_delete(root, 41);
        std::cout << "Exclusão de 56\n";
        node_delete(root, 56);
        std::cout << "Inserção de 23\n";
        tree_insert(root, 23);

        avl_set_rotation_trace(false);
        std::cout << "Árvore resultante em pré-ordem: ";
        tree_walk_preorder(root);
        std::cout << "\n";
        export_to_dot(root, "arvore_q4");
    }});

    lista_adicionar(acoes, {"Q5 — Ler arquivo e aplicar operações", [&]() {
        tree_clear(root);
        std::ifstream arquivo;
        if (!abrir_arquivo_leitura_candidatos(arquivo, {
                "arquivo_ead4_q5.txt",
                "ead4/arquivo_ead4_q5.txt"})) {
            return;
        }
        avl_set_rotation_trace(true);
        tree_apply_ops_stream(root, arquivo);
        avl_set_rotation_trace(false);
        arquivo.close();

        std::cout << "Árvore resultante em pré-ordem: ";
        tree_walk_preorder(root);
        std::cout << "\n";
        export_to_dot(root, "arvore_q5");
    }});

    while (rodando) {
        limpar_tela();
        std::cout << "EAD4 — AVL (cada questão começa com árvore vazia)\n";
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
