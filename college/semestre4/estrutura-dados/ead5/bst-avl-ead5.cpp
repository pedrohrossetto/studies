#include "../modules/arvore-binaria-avl.hpp"
#include "../modules/graphviz_bintree.hpp"
#include "../modules/menu_funcoes.hpp"
#include "../modules/utils_plus.hpp"
#include "../modules/text_files_plus.hpp"

#include <iostream>

int main() {
    limpar_tela();
    bool rodando = true;

    ListaMenuAcao acoes = lista_criar();

    lista_adicionar(acoes, {"Sair", [&]() {
        rodando = false;
    }});

    lista_adicionar(acoes, {"Operações da Árvore - Questao 1", [&]() {
        bool rodando_submenu = true;
        AVLNode* root = nullptr;

        ListaMenuAcao acoes_submenu = lista_criar();

        lista_adicionar(acoes_submenu, {"Voltar ao Menu Principal", [&]() {
            rodando_submenu = false;
        }});

        lista_adicionar(acoes_submenu, {"Inserir Elemento", [&]() {
            int valor = lerInteiroValido("Valor: ");
            tree_insert(root, valor);
            std::cout << "Elemento inserido.\n";
        }});

        lista_adicionar(acoes_submenu, {"Mostrar Árvore", [&]() {
            std::cout << "In-order: ";
            tree_walk_inorder(root);
            std::cout << "\nPre-order: ";
            tree_walk_preorder(root);
            std::cout << "\nPost-order: ";
            tree_walk_postorder(root);
            std::cout << "\n";
        }});

        lista_adicionar(acoes_submenu, {"Remover Elemento", [&]() {
            int valor = lerInteiroValido("Valor: ");
            if (!node_search(root, valor)) {
                std::cout << "Valor não encontrado.\n";
                return;
            }
            node_delete(root, valor);
            std::cout << "Elemento removido.\n";
        }});

        lista_adicionar(acoes_submenu, {"Ler Arquivo Texto", [&]() {
            std::ifstream arquivo;
            if (!abrir_arquivo_leitura_candidatos(arquivo, {
                    "arquivo_ead5_q1.txt",
                    "ead5/arquivo_ead5_q1.txt"})) {
                return;
            }
            tree_apply_ops_stream(root, arquivo);
            arquivo.close();
            std::cout << "Árvore resultante em pré-ordem: ";
            tree_walk_preorder(root);
            std::cout << "\n";
        }});

        lista_adicionar(acoes_submenu, {"Limpar Árvore", [&]() {
            tree_clear(root);
            std::cout << "Árvore excluída.\n";
        }});

        lista_adicionar(acoes_submenu, {"Exportar DOT/PNG", [&]() {
            export_to_dot(root, "arvore_q1");
        }});

        while (rodando_submenu) {
            limpar_tela();
            std::cout << "EAD5 Q1 — AVL básica\n";
            desenharLinha();
            menu_listar(acoes_submenu);
            desenharLinha();
            int indice = lerInteiroValido("Índice: ");
            limpar_tela();
            menu_executar(acoes_submenu, indice);
            if (rodando_submenu) {
                pausar_e_limpar();
            }
        }

        lista_liberar(acoes_submenu);
        tree_clear(root);
    }});

    lista_adicionar(acoes, {"Operações da Árvore - Questao 2", [&]() {
        bool rodando_submenu = true;
        AVLNode* root = nullptr;

        ListaMenuAcao acoes_submenu = lista_criar();

        lista_adicionar(acoes_submenu, {"Voltar ao Menu Principal", [&]() {
            rodando_submenu = false;
        }});

        lista_adicionar(acoes_submenu, {"Inserir Elemento", [&]() {
            int valor = lerInteiroValido("Valor: ");
            tree_insert(root, valor);
            std::cout << "Elemento inserido.\n";
        }});

        lista_adicionar(acoes_submenu, {"Mostrar Árvore", [&]() {
            std::cout << "In-order: ";
            tree_walk_inorder(root);
            std::cout << "\nPre-order: ";
            tree_walk_preorder(root);
            std::cout << "\nPost-order: ";
            tree_walk_postorder(root);
            std::cout << "\n";
        }});

        lista_adicionar(acoes_submenu, {"Remover Elemento", [&]() {
            int valor = lerInteiroValido("Valor: ");
            if (!node_search(root, valor)) {
                std::cout << "Valor não encontrado.\n";
                return;
            }
            node_delete(root, valor);
            std::cout << "Elemento removido.\n";
        }});

        lista_adicionar(acoes_submenu, {"Inserir lista randomizada", [&]() {
            int qtd_val = lerInteiroValido("Quantidade de inserções: ");
            int lim_min = lerInteiroValido("Limite Menor: ");
            int lim_max = lerInteiroValido("Limite Maior: ");
            tree_fill_random(root, qtd_val, lim_min, lim_max);
            std::cout << "Inserido.\n";
        }});

        lista_adicionar(acoes_submenu, {"Nós por nível", [&]() {
            if (is_empty(root)) {
                std::cout << "Árvore vazia.\n";
                return;
            }
            count_nodes_per_height(root);
        }});

        lista_adicionar(acoes_submenu, {"Exibir fator de balanceamento", [&]() {
            int valor = lerInteiroValido("Valor: ");
            AVLNode* node = node_search_iteractive(root, valor);
            if (!node) {
                std::cout << "Valor não encontrado.\n";
                return;
            }
            std::cout << "Fator de balanceamento do nó " << node->val
                      << ": " << avl_balance(node) << "\n";
        }});

        lista_adicionar(acoes_submenu, {"O maior elemento da árvore e seu nível", [&]() {
            AVLNode* max = tree_max(root);
            if (!max) {
                std::cout << "Árvore vazia.\n";
                return;
            }
            std::cout << "Maior elemento: " << max->val
                      << "\nNível: " << node_level(root, max->val) << "\n";
        }});

        lista_adicionar(acoes_submenu, {"Ancestor comum mais próximo (LCA)", [&]() {
            int a = lerInteiroValido("Primeiro valor: ");
            int b = lerInteiroValido("Segundo valor: ");
            AVLNode* lca = lowest_common_ancestor(root, a, b);
            if (lca) {
                std::cout << "LCA de " << a << " e " << b << ": " << lca->val << "\n";
            } else {
                std::cout << "Árvore vazia ou algum valor não existe.\n";
            }
        }});

        lista_adicionar(acoes_submenu, {"Soma dos valores", [&]() {
            std::cout << "Soma dos nós da árvore: " << tree_sum(root) << "\n";
        }});

        lista_adicionar(acoes_submenu, {"Todos os elementos do nível do menor elemento", [&]() {
            AVLNode* min = tree_min(root);
            if (!min) {
                std::cout << "Árvore vazia.\n";
                return;
            }
            int nivel = node_level(root, min->val);
            std::cout << "Menor: " << min->val << " (nível " << nivel << "): ";
            print_nodes_at_height(root, nivel);
            std::cout << "\n";
        }});

        lista_adicionar(acoes_submenu, {"Limpar Árvore", [&]() {
            tree_clear(root);
            std::cout << "Árvore excluída.\n";
        }});

        lista_adicionar(acoes_submenu, {"Exportar DOT/PNG", [&]() {
            export_to_dot(root, "arvore_q2");
        }});

        while (rodando_submenu) {
            limpar_tela();
            std::cout << "EAD5 Q2 — consultas AVL\n";
            desenharLinha();
            menu_listar(acoes_submenu);
            desenharLinha();
            int indice = lerInteiroValido("Índice: ");
            limpar_tela();
            menu_executar(acoes_submenu, indice);
            if (rodando_submenu) {
                pausar_e_limpar();
            }
        }

        lista_liberar(acoes_submenu);
        tree_clear(root);
    }});

    while (rodando) {
        limpar_tela();
        std::cout << "EAD5 — AVL\n";
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

    lista_liberar(acoes);
    return 0;
}
