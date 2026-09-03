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

    lista_adicionar(acoes, {"Seguindo o critério de inserção em uma árvores AVL realize a inclusão dos elementos, e apresente a árvore resultante", [&]() {
        int lista[13] = {53, 26, 14, 7, 30, 36, 23, 86, 35, 18, 40, 25, 90};
        for (int i = 0; i < sizeof(lista)/sizeof(lista[0]); i++) {
            tree_insert(root, lista[i]);
        }
        std::cout << "Árvore resultante em pré-ordem: ";
        tree_walk_preorder(root);
        std::cout << std::endl;
        export_to_dot(root, "arvore_q1");

    }});
    lista_adicionar(acoes, {"Implemente as funcoes requisitadas pela questao e apresente a árvore resultante", [&]() {
        int lista[6] = {4,2,3,10,9,5};
        for (int i = 0; i < sizeof(lista)/sizeof(lista[0]); i++) {
            tree_insert(root, lista[i]);
        }
        std::cout << "Árvore original em pré-ordem: ";
        tree_walk_preorder(root);
        node_delete(root,2);
        std::cout << "Removendo 2" << std::endl;
        tree_insert(root,7);
        std::cout << "Inserindo 7" << std::endl;
        tree_insert(root,16);
        std::cout << "Inserindo 16" << std::endl;
        tree_insert(root,20);
        std::cout << "Inserindo 20" << std::endl;
        node_delete(root,4);
        std::cout << "Removendo 4" << std::endl;
        node_delete(root,9);
        std::cout << "Removendo 9" << std::endl;
        std::cout << "Árvore resultante em pré-ordem: ";
        tree_walk_preorder(root);
        std::cout << std::endl;
        export_to_dot(root, "arvore_q2");
    }});
    lista_adicionar(acoes, {"Teste insercao de elementos e aponte o resultado correto",[&](){
        int lista[6] = {47,35,40,32,42,30};
        for (int i = 0; i < sizeof(lista)/sizeof(lista[0]); i++) {
            tree_insert(root, lista[i]);
        }
        std::cout << "Árvore resultante em pré-ordem: ";
        tree_walk_preorder(root);

        std::cout << "Resposta:\nArvore apresentada pela questao estava errada. foi necessario fazer um LR na 3 insercao e um LL na ultima." << std::endl;
        export_to_dot(root, "arvore_q3");
    }});
    lista_adicionar(acoes, {"Executar acoes listadas, indique arvore resultante e rotacoes necessarias", [&](){
        int lista[9] = {30,25,15,45,41,35,43,56,50};
        for (int i = 0; i < sizeof(lista)/sizeof(lista[0]); i++) {
            tree_insert(root, lista[i]);
        }
        std::cout << "Árvore Original em pré-ordem: ";
        tree_walk_preorder(root);

        node_delete(root,45);
        std::cout << "\nExclusão de 45: ";

        node_delete(root,25);
        std::cout << "\nExclusão de 25: RL Rotation";

        tree_insert(root,12);
        std::cout << "\nInserção de 12: ";

        tree_insert(root,42);
        std::cout << "\nInserção de 42: ";

        tree_insert(root,38);
        std::cout << "\nInserção de 38: ";

        node_delete(root,41);
        std::cout << "\nExclusão de 41: ";

        node_delete(root,56);
        std::cout << "\nExclusão de 56: ";

        tree_insert(root,23);
        std::cout << "\nInserção de 23: ";

        std::cout << "\nÁrvore Resultante em pré-ordem: ";
        tree_walk_preorder(root);
        std::cout << std::endl;
        export_to_dot(root, "arvore_q4");
    }});
    lista_adicionar(acoes, {"Ler Arquivo, executar acoes e mostrar resultado", [&](){
        std::ifstream arquivo;
        if (!abrir_arquivo_leitura(arquivo, "arquivo_ead4_q5.txt")) return;

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
        export_to_dot(root, "arvore_q5");


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
