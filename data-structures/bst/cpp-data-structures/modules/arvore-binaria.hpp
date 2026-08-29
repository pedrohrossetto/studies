#ifndef _HPP_ARVORE_BINARIA
#define _HPP_ARVORE_BINARIA
#include <iostream>

// Struct básica para manipulação de Árvores Binárias
struct BinTreeNode
{
    int value;
    BinTreeNode *left_child;
    BinTreeNode *right_child;

    BinTreeNode(int val) : value(val), left_child(nullptr), right_child(nullptr) {  }
};

// Factory básica de criação de novos Nós
static BinTreeNode* create_node(int val) {
    return new BinTreeNode(val);
}

static bool is_empty(BinTreeNode* tree){
    return tree == nullptr;
}

// Busca pelo menor valor da árvore (o valor mais à esquerda)
static BinTreeNode* tree_min(BinTreeNode* tree){
    while (tree->left_child != nullptr) {
        tree = tree->left_child;
    }
    return tree;
}

// Busca pelo maior valor da árvore (o valor mais à direita)
static BinTreeNode* tree_max(BinTreeNode *tree){
    while (tree->right_child != nullptr) {
        tree = tree->right_child;
    }
    return tree;
}

// Busca pelo menor valor na sub-árvore à direita
static BinTreeNode* node_sucessor(BinTreeNode* tree){
    if (tree->right_child != nullptr) {
        return tree_min(tree->right_child);
    }
}

// Busca pelo Maior valor na sub-árvore à esquerda
static BinTreeNode* node_predecessor(BinTreeNode* tree){
    if (tree->left_child != nullptr) {
        return tree_max(tree->left_child);
    }
}



// Algoritmo de definição de altura da árvore
// Complexidade de tempo O(n) e espaço O(h) n = nós da árvore e h = altura da árvore
// assume padrão nível da raiz = 0
static int tree_height(BinTreeNode* tree){
    if (tree == nullptr) {
        return -1;
    }
    else {
        return 1 + std::max(tree_height(tree->left_child),tree_height(tree->right_child));
    }
}

// to-do algoritmo de limpeza completa da árvore
static void tree_clear(BinTreeNode* &tree){
    if (!is_empty(tree)) { //
        tree_clear(tree->left_child);
        tree_clear(tree->right_child);
        delete tree; // destruindo os dados
        tree = nullptr; // desreferenciando o ponteiro, agora para nulo
    }
}



// busca por um valor específico presenta na árvore
static bool node_search(BinTreeNode *tree, int val)
    {
        if(is_empty(tree))
            return 0;
        return tree->value == val || node_search(tree->left_child, val) || node_search(tree->right_child, val);
    }

    /*
     * Recebe como argumento a raiz da árvore e o valor do nó que se deseja remover
     */

// busca de forma iterativa (sem recursão) por um valor específico presente na árvore e o retorna
static BinTreeNode* node_search_iteractive(BinTreeNode* tree,int val){
    while (tree != nullptr && val != tree->value) {
        if (val < tree->value) {
            tree = tree->left_child;
        }
        else {
            tree = tree->right_child;
        }
    }
    return tree;
}

// Remoção de um node da árvore e sequente manipulação dos ramos
static void node_delete(BinTreeNode* &tree, int val)
    {

        if (tree == nullptr) return; // Condição de parada

        else if (val < tree->value) {
            node_delete(tree->left_child,val);
        }
        else if (val > tree->value) {
            node_delete(tree->right_child,val);
        }
        // o caso que resta é que val == tree->value
        else {
            // testa se o node tem apenas um filho
            if (tree->left_child == nullptr || tree->right_child == nullptr) {
                BinTreeNode *aux = tree; // salvando o endereço do nó a ser excluído
                tree = (tree->left_child != nullptr) ? tree->left_child : tree->right_child; // t->l != vazio? se sim, t == t->l, se não, t == t->r
                delete aux;
            }
            else { // caso em que há dois filhos
                BinTreeNode* sucessor = tree->right_child; // o ponteiro sucessor aponta para o endereço de t->r
                while (sucessor->left_child != nullptr) {
                    sucessor = sucessor->left_child; // busca o menor valor (ultimo à esquerda) que é o sucessor
                }
                tree->value = sucessor->value; //valor do node a ser removido passa a ser o do sucessor, mantendo a estrutura
                node_delete(tree->right_child, tree->value); // recursão para percorrer o ramo à direita
            }
        }
    }

// Insere seguindo as regras um node na árvore
static void tree_insert(BinTreeNode* &tree, int val){
    if(is_empty(tree)){
        tree = create_node(val);
        // Caso Base
        // Insere apenas  quando chega ao final da estrutura
        // um left_child/right_child de tipo BinTreeNode nullptr é encontrado
    }
    else {
        if(val < tree->value)
            tree_insert(tree->left_child,val); // passo recursivo 1
        else
            tree_insert(tree->right_child,val); // passo recursivo 2
    }
}

// Lógica de ordenação crescente
static void tree_walk_inorder(BinTreeNode* tree){
    if (!is_empty(tree)) {
        tree_walk_inorder(tree->left_child);
        std::cout << tree->value << " ";
        tree_walk_inorder(tree->right_child);
    }
}

// lógica de <raiz<left><right>>
static void tree_walk_preorder(BinTreeNode* tree) {
    std::cout << "<";
    if (!is_empty(tree)) {
        std::cout << tree->value << " ";
        tree_walk_preorder(tree->left_child);
        std::cout << " ";
        tree_walk_preorder(tree->right_child);
    }
    std::cout << ">";
}

// lógica de <<left><right>raiz>
static void tree_walk_postorder(BinTreeNode* tree){
    // Pos ordem é geralmente utilizado para exclusão e liberação de memória
    // Complexidade: O(n) para tempo e O(h) para espaço de pilha
    // (n é o número de nós e h é a altura da árvore).
    std::cout << "<";
    if(!is_empty(tree)){
        tree_walk_postorder(tree->left_child);
        std::cout << " ";
        tree_walk_postorder(tree->right_child);
        std::cout << tree->value << " ";
    }
    std::cout << ">";

}

#endif
