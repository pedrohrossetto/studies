#ifndef _HPP_ARVORE_BINARIA
#define _HPP_ARVORE_BINARIA
#include <iostream>

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

static bool is_empty(BinTreeNode *t){
    return t == nullptr;
}

static bool tree_search(BinTreeNode *t, int val)
    {
        if(is_empty(t))
            return 0;
        return t->value == val || tree_search(t->left_child, val) || tree_search(t->right_child, val);
    }

static void tree_insert(BinTreeNode* &t, int val){
    if(is_empty(t)){
        t = create_node(val);
        // Caso Base
        // Insere apenas  quando chega ao final da estrutura
        // um left_child/right_child de tipo BinTreeNode nullptr é encontrado
    }
    else {
        if(val < t->value)
            tree_insert(t->left_child,val); // passo recursivo 1
        else
            tree_insert(t->right_child,val); // passo recursivo 2
    }
}

static void inorder_walk(BinTreeNode* t){
    if (!is_empty(t)) {
        inorder_walk(t->left_child);
        std::cout << t->value << " ";
        inorder_walk(t->right_child);
    }
}

static void preorder_walk(BinTreeNode* t) {
    std::cout << "<";
    if (!is_empty(t)) {
        std::cout << t->value << " ";
        preorder_walk(t->left_child);
        std::cout << " ";
        preorder_walk(t->right_child);
    }
    std::cout << ">";
}

// Pos ordem é geralmente utilizado para exclusão e liberação de memória
// Complexidade: O(n) para tempo e O(h) para espaço de pilha
// (n é o número de nós e h é a altura da árvore).

static void postorder_walk(BinTreeNode* t){
    std::cout << "<";
    if(!is_empty(t)){
        postorder_walk(t->left_child);
        std::cout << " ";
        postorder_walk(t->right_child);
        std::cout << t->value << " ";
    }
    std::cout << ">";

}

#endif
