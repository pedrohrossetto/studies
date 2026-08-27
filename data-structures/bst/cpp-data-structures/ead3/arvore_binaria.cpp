#include "../modules/arvore-binaria.hpp"
#include "../modules/graphviz_bintree.hpp"
#include "../modules/utils_plus.hpp"
#include <iostream>

using namespace std;

int main(){
    // Chave para funcionar
    // Ponteiro que aponta para o endereço alocado de uma BinTreeNode vazia
    // Sempre que estiver sendo utilizado o ponteiro root em uma função
    // está sendo passado na verdade o endereço inicial da estrutura BinTreeNode
    BinTreeNode* root = nullptr;

    int valores[10] = {6,8,4,5,2,3,1,9,7,6};
    for (int v : valores) {
        tree_insert(root, v);
    }

    int menu_main;
    while (true) {
        std::cout<< "Menu:\n0 - Sair\n1 - Inserir\n2 - Busca de Elementos\n3 - Opções de Exibição:\n";
        std::cin >> menu_main;
        switch (menu_main) {
            case 0: //sair
                limpar_tela();
                return 0;
            case 1: // incluir na árvore
                limpar_tela();
                int val_input;
                std::cout << "Informe int para incluir na árvore:"<< endl;
                std::cin >> val_input;
                tree_insert(root, val_input);
                std::cout << "Valor inserido."<< endl;
                break;
            case 2: // busca na árvore
                limpar_tela();
                int val_search;
                std::cout << "Informe int para consultar:"<< endl;
                std::cin >> val_search;
                if (tree_search(root, val_search)) {
                    std::cout << "Valor " << val_search << " encontrado!\n";
                } else {
                    std::cout << "Valor " << val_search << " não encontrado...\n";
                }
                break;
            case 3: // sub-menu de exibição
                limpar_tela();
                int menu_exib;
                std::cout<< "Menu:\n0 - Sair\n1 - Exibir Pré-ordem\n2 - Exibir in-ordem\n3 - Exibir Pós-ordem\n";
                std::cin >> menu_exib;
                switch (menu_exib) {
                    case 0: //sair
                        limpar_tela();
                        return 0;
                    case 1: //pre-ordem
                        limpar_tela();
                        std::cout << "Pre-order: ";
                        preorder_walk(root);
                        std::cout << "\n";
                        break;
                    case 2: //in order
                        limpar_tela();
                        std::cout << "In-order: ";
                        inorder_walk(root);
                        std::cout << "\n";
                        break;
                    case 3: // pós-ordem
                        limpar_tela();
                        std::cout << "Post-order: ";
                        postorder_walk(root);
                        std::cout << "\n";
                        break;
                    case 4:
                        place_holder();
                }

        }
        pausar_e_limpar();
    }

    // export_to_dot(root, "arvore.dot");

    return 0;

}
