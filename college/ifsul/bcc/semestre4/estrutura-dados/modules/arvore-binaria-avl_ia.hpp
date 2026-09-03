#ifndef ARVORE_AVL_HPP
#define ARVORE_AVL_HPP

#include "arvore-binaria.hpp"

// GERADO POR IA

/*
 * Funções reaproveitadas de arvore-binaria.hpp (não redefinidas aqui):
 *   is_empty, tree_min, tree_max, node_sucessor, node_predecessor
 *   tree_size, tree_clear, tree_height  (recursivo genérico, O(n))
 *   node_search, node_search_iteractive
 *   tree_walk_inorder, tree_walk_preorder, tree_walk_postorder
 *   tree_sum, tree_sum_conditional
 */

// Nó AVL: estende TreeNode com altura armazenada para consulta O(1)
struct AVLNode : public TreeNode {
    int height;
    AVLNode(int val) : TreeNode(val), height(1) { }
};

static AVLNode* create_avl_node(int val) {
    return new AVLNode(val);
}

// Altura armazenada — O(1), retorna 0 para nullptr
static int avl_height(AVLNode* node) {
    return node ? node->height : 0;
}

static void avl_update_height(AVLNode* node) {
    int lh = avl_height(static_cast<AVLNode*>(node->left));
    int rh = avl_height(static_cast<AVLNode*>(node->right));
    node->height = 1 + std::max(lh, rh);
}

// Fator de balanceamento: altura(esq) - altura(dir)
static int avl_balance(AVLNode* node) {
    return avl_height(static_cast<AVLNode*>(node->left))
         - avl_height(static_cast<AVLNode*>(node->right));
}

/*
 *     y                x
 *    / \      =>      / \
 *   x   C            A   y
 *  / \                  / \
 * A   B                B   C
 */
static AVLNode* avl_rotate_right(AVLNode* y) {
    AVLNode* x = static_cast<AVLNode*>(y->left);
    AVLNode* B = static_cast<AVLNode*>(x->right);

    x->right = y;
    y->left  = B;

    avl_update_height(y); // y é filho agora — atualizar primeiro
    avl_update_height(x);
    return x;
}

/*
 *   x                y
 *  / \      =>      / \
 * A   y            x   C
 *    / \          / \
 *   B   C        A   B
 */
static AVLNode* avl_rotate_left(AVLNode* x) {
    AVLNode* y = static_cast<AVLNode*>(x->right);
    AVLNode* B = static_cast<AVLNode*>(y->left);

    y->left  = x;
    x->right = B;

    avl_update_height(x);
    avl_update_height(y);
    return y;
}

// Detecta o caso de desequilíbrio e aplica a rotação adequada
static AVLNode* avl_rebalance(AVLNode* root) {
    int bal = avl_balance(root);

    if (bal > 1) { // pesado à esquerda
        AVLNode* esq = static_cast<AVLNode*>(root->left);
        if (avl_balance(esq) < 0)          // Caso LR: dupla rotação
            root->left = avl_rotate_left(esq);
        return avl_rotate_right(root);     // Caso LL
    }

    if (bal < -1) { // pesado à direita
        AVLNode* dir = static_cast<AVLNode*>(root->right);
        if (avl_balance(dir) > 0)          // Caso RL: dupla rotação
            root->right = avl_rotate_right(dir);
        return avl_rotate_left(root);      // Caso RR
    }

    return root;
}

static AVLNode* avl_insert_r(AVLNode* root, int val) {
    if (root == nullptr) return create_avl_node(val);

    if (val < root->val)
        root->left  = avl_insert_r(static_cast<AVLNode*>(root->left),  val);
    else if (val > root->val)
        root->right = avl_insert_r(static_cast<AVLNode*>(root->right), val);
    else
        return root; // duplicados ignorados

    avl_update_height(root);
    return avl_rebalance(root);
}

// Override de tree_insert — compilador prefere esta sobrecarga quando root é AVLNode*&
static void tree_insert(AVLNode* &root, int val) {
    root = avl_insert_r(root, val);
}

static AVLNode* avl_delete_r(AVLNode* root, int val) {
    if (root == nullptr) return nullptr;

    if (val < root->val) {
        root->left  = avl_delete_r(static_cast<AVLNode*>(root->left),  val);
    } else if (val > root->val) {
        root->right = avl_delete_r(static_cast<AVLNode*>(root->right), val);
    } else {
        if (root->left == nullptr || root->right == nullptr) {
            AVLNode* filho = static_cast<AVLNode*>(root->left ? root->left : root->right);
            delete root;
            return filho;
        }
        // dois filhos: substitui pelo sucessor (menor da sub-árvore direita)
        TreeNode* suc = tree_min(root->right);
        root->val     = suc->val;
        root->right   = avl_delete_r(static_cast<AVLNode*>(root->right), suc->val);
    }

    avl_update_height(root);
    return avl_rebalance(root);
}

// Override de node_delete
static void node_delete(AVLNode* &root, int val) {
    root = avl_delete_r(root, val);
}

// Overrides das funções de preenchimento aleatório
static void tree_fill_random(AVLNode* &root, int n, int min_val, int max_val) {
    for (int i = 0; i < n; ++i)
        tree_insert(root, gerarAleatorio(min_val, max_val));
}

static void tree_insert_random(AVLNode* &root, int min_val, int max_val) {
    tree_insert(root, gerarAleatorio(min_val, max_val));
}

static void avl_stats(AVLNode* root) {
    std::cout << "Nó atual: " << root->val
              << "\nL/R: "    << root->left->val  << " / " << root->right->val
              << "\nnos="     << tree_size(root)
              << "\naltura="  << root->height
              << "\nbalance=" << avl_balance(root) << "\n";
}

// Override de tree_clear
// to-do algoritmo de limpeza completa da árvore
inline void tree_clear(AVLNode* &root){
    if (!is_empty(root)) { //
        tree_clear(root->left);
        tree_clear(root->right);
        delete root; // destruindo os dados
        root = nullptr; // desreferenciando o ponteiro, agora para nulo
    }
}

#endif // ARVORE_AVL_HPP
