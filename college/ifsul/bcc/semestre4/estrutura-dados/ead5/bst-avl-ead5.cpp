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
            std::cout << "Elemento inserido com sucesso.\n";
        }});

        lista_adicionar(acoes_submenu, {"Mostrar Árvore", [&]() {
            std::cout << "In-order: ";
            tree_walk_inorder(root);
            std::cout << "\n";
            std::cout << "Pre-order: ";
            tree_walk_preorder(root);
            std::cout << "\n";
            std::cout << "Post-order: ";
            tree_walk_postorder(root);
            std::cout << "\n";
        }});

        lista_adicionar(acoes_submenu, {"Remover Elemento", [&]() {
            int valor = lerInteiroValido("Valor: ");
            node_delete(root, valor);
            std::cout << "Elemento removido com sucesso.\n";
        }});

        lista_adicionar(acoes_submenu, {"Ler Arquivo Texto", [&]() {
            std::ifstream arquivo;
            if (!abrir_arquivo_leitura(arquivo, "arquivo_ead5_q1.txt")) return;

            std::string linha;
            while (std::getline(arquivo, linha)) {
                std::string operacao;
                int valor;
                std::istringstream ss(linha);
                ss >> operacao >> valor;

                if (operacao == "inserir") {
                    tree_insert(root, valor);
                    std::cout << "Inserindo " << valor << std::endl;
                } else if (operacao == "remover") {
                    node_delete(root, valor);
                    std::cout << "Removendo " << valor << std::endl;
                }
            }
            arquivo.close();

            std::cout << "Árvore resultante em pré-ordem: ";
            tree_walk_preorder(root);
            std::cout << std::endl;
        }});

        lista_adicionar(acoes_submenu, {"Limpar Árvore", [&]() {
            tree_clear(root);
            std::cout << "Árvore Excluída.\n";
        }});

        lista_adicionar(acoes_submenu, {"Exportar DOT/PNG", [&]() {
            export_to_dot(root, "arvore_q1");
        }});

        while (rodando_submenu) {
            limpar_tela();
            std::cout << "Árvore (índice = função)\n";
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
            std::cout << "Elemento inserido com sucesso.\n";
        }});

        lista_adicionar(acoes_submenu, {"Mostrar Árvore", [&]() {
            std::cout << "In-order: ";
            tree_walk_inorder(root);
            std::cout << "\n";
            std::cout << "Pre-order: ";
            tree_walk_preorder(root);
            std::cout << "\n";
            std::cout << "Post-order: ";
            tree_walk_postorder(root);
            std::cout << "\n";
        }});

        lista_adicionar(acoes_submenu, {"Remover Elemento", [&]() {
            int valor = lerInteiroValido("Valor: ");
            node_delete(root, valor);
            std::cout << "Elemento removido com sucesso.\n";
        }});


        lista_adicionar(acoes_submenu, {"Inserir lista randomizada", [&]() {
            int qtd_val = lerInteiroValido("Quantidade de inserções: ");
            int lim_min = lerInteiroValido("Limite Menor: ");
            int lim_max = lerInteiroValido("Limite Maior: ");
            tree_fill_random(root, qtd_val, lim_min, lim_max);
            std::cout << "Inserido.\n";
        }});

        lista_adicionar(acoes_submenu, {"Nós por nível",[&](){
            count_nodes_per_height(root);
        }});

        lista_adicionar(acoes_submenu, {"Exibir fator de balanceamento",[&](){
            AVLNode* node = node_search_iteractive(root,lerInteiroValido("Valor: "));

            std::cout << "Fator de balanceamento do nó " << node->val << ": " << avl_balance(node);
        }});
        lista_adicionar(acoes_submenu, {"O maior elemento da árvore e seu nível",[&](){
            AVLNode* max = tree_max(root);
            std::cout << "Maior Elemento: " << max->val;
            std::cout << "\nNível: " << node_level(root, max->val);
        }});
        lista_adicionar(acoes_submenu, {"Ancestor Comum mais Próximo (LCA)",[&](){
            int a = lerInteiroValido("Primeiro valor: ");
            int b = lerInteiroValido("Segundo valor: ");
            AVLNode* lca = lowest_common_ancestor(root, a, b);
            if (lca) {
                std::cout << "LCA de " << a << " e " << b << ": " << lca->val << "\n";
            } else {
                std::cout << "Árvore vazia ou valores inválidos.\n";
            }
        }});
        lista_adicionar(acoes_submenu, {"Soma dos Valores",[&](){
            std::cout << "Soma dos nós da árvore:" << tree_sum(root);
        }});
        lista_adicionar(acoes_submenu, {"Todos os elementos do nível do menor elemento",[&](){
            int nivel = node_level(root, tree_min(root)->val);
            print_nodes_at_height(root, nivel);
        }});

        lista_adicionar(acoes_submenu, {"Limpar Árvore", [&]() {
            tree_clear(root);
            std::cout << "Árvore Excluída.\n";
        }});

        lista_adicionar(acoes_submenu, {"Exportar DOT/PNG", [&]() {
            export_to_dot(root, "arvore_q2");
        }});

        while (rodando_submenu) {
            limpar_tela();
            std::cout << "Árvore (índice = função)\n";
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

    lista_liberar(acoes);
    return 0;

}
