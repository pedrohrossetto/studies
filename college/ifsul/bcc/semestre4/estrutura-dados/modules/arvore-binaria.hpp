#ifndef ARVORE_BINARIA_HPP
#define ARVORE_BINARIA_HPP
#include <iostream>
#include "utils_plus.hpp"



// Struct básica para manipulação de Árvores Binárias
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {  }
};

// Factory básica de criação de novos Nós
inline TreeNode* create_node(int val) {
    return new TreeNode(val);
}

inline bool is_empty(TreeNode* root){
    return root == nullptr;
}

// Busca pelo menor valor da árvore (o valor mais à esquerda)
inline TreeNode* tree_min(TreeNode* root){
    if (root == nullptr) {
        return nullptr;
    }
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Busca pelo maior valor da árvore (o valor mais à direita)
inline TreeNode* tree_max(TreeNode *root){
    if (root == nullptr) {
        return nullptr;
    }
    while (root->right != nullptr) {
        root = root->right;
    }
    return root;
}

// Busca pelo menor valor na sub-árvore à direita
inline TreeNode* node_sucessor(TreeNode* root){
    if (root->right != nullptr) {
        return tree_min(root->right);
    }
    return nullptr;
}


// Busca pelo Maior valor na sub-árvore à esquerda
inline TreeNode* node_predecessor(TreeNode* root){
    if (root->left != nullptr) {
        return tree_max(root->left);
    }
    return nullptr;
}

// Algoritmo de definição de altura da árvore
// Complexidade de tempo O(n) e espaço O(h) n = nós da árvore e h = altura da árvore
// assume padrão nível da raiz = 0
inline int tree_height(TreeNode* root){
    if (root == nullptr) {
        return -1;
    }
    else {
        return 1 + std::max(tree_height(root->left),tree_height(root->right));
    }
}

// Conta nós. Base para a probabilidade 1/(n+1) da inserção randomizada.
inline int tree_size(TreeNode* root) {
    if (is_empty(root)) {
        return 0;
    }
    return 1 + tree_size(root->left) + tree_size(root->right);
}

inline int tree_balance(TreeNode* root){
    if (root == nullptr) {
        return 0;
    }
    return tree_height(root->left) - tree_height(root->right);
}

// to-do algoritmo de limpeza completa da árvore
inline void tree_clear(TreeNode* &root){
    if (!is_empty(root)) { //
        tree_clear(root->left);
        tree_clear(root->right);
        delete root; // destruindo os dados
        root = nullptr; // desreferenciando o ponteiro, agora para nulo
    }
}


// busca por um valor específico presenta na árvore
inline bool node_search(TreeNode *root, int val)
    {
        if(is_empty(root))
            return false;
        if (root->val == val) {
            return true;
        }
        if (val < root->val) {
            return node_search(root->left, val);
        }
        return node_search(root->right, val);
    }

    /*
     * Recebe como argumento a raiz da árvore e o valor do nó que se deseja remover
     */

// busca de forma iterativa (sem recursão) por um valor específico presente na árvore e o retorna
inline TreeNode* node_search_iteractive(TreeNode* root,int val){
    while (root != nullptr && val != root->val) {
        if (val < root->val) {
            root = root->left;
        }
        else {
            root = root->right;
        }
    }
    return root;
}

// não implementado
inline int node_height_search(TreeNode* root, int val){
    return -1;
}

// Remoção de um node da árvore e sequente manipulação dos ramos
inline void node_delete(TreeNode* &root, int val)
    {

        if (root == nullptr) return; // Condição de parada

        else if (val < root->val) {
            node_delete(root->left,val);
        }
        else if (val > root->val) {
            node_delete(root->right,val);
        }
        // o caso que resta é que val == root->val
        else {
            // testa se o node tem apenas um filho
            if (root->left == nullptr || root->right == nullptr) {
                TreeNode *aux = root; // salvando o endereço do nó a ser excluído
                root = (root->left != nullptr) ? root->left : root->right; // t->l != vazio? se sim, t == t->l, se não, t == t->r
                delete aux;
            }
            else { // caso em que há dois filhos
                TreeNode* sucessor = root->right; // o ponteiro sucessor aponta para o endereço de t->r
                while (sucessor->left != nullptr) {
                    sucessor = sucessor->left; // busca o menor valor (ultimo à esquerda) que é o sucessor
                }
                root->val = sucessor->val; //valor do node a ser removido passa a ser o do sucessor, mantendo a estrutura
                node_delete(root->right, root->val); // recursão para percorrer o ramo à direita
            }
        }
    }

// Insere seguindo as regras um node na árvore
inline void tree_insert(TreeNode* &root, int val){
    if(is_empty(root)){
        root = create_node(val);
        // Caso Base
        // Insere apenas  quando chega ao final da estrutura
        // um left/right de tipo TreeNode nullptr é encontrado
    }
    else {
        if(val < root->val)
            tree_insert(root->left,val); // passo recursivo 1
        else
            tree_insert(root->right,val); // passo recursivo 2
    }
}

// n valores aleatórios no intervalo [min_val, max_val], inserção BST comum.
inline void tree_fill_random(TreeNode* &root, int n, int min_val, int max_val) {
    for (int i = 0; i < n; ++i) {
        tree_insert(root, gerarAleatorio(min_val, max_val));
    }
}

inline void tree_insert_random(TreeNode* &root, int min_val, int max_val) {
        tree_insert(root, gerarAleatorio(min_val, max_val));
}

// Lógica de ordenação crescente
inline void tree_walk_inorder(TreeNode* root){
    if (!is_empty(root)) {
        tree_walk_inorder(root->left);
        std::cout << root->val << " ";
        tree_walk_inorder(root->right);
    }
}

// lógica de <raiz<left><right>>
inline void tree_walk_preorder(TreeNode* root) {
    std::cout << "<";
    if (!is_empty(root)) {
        std::cout << root->val << " ";
        tree_walk_preorder(root->left);
        std::cout << " ";
        tree_walk_preorder(root->right);
    }
    std::cout << ">";
}

// lógica de <<left><right>raiz>
inline void tree_walk_postorder(TreeNode* root){
    // Pos ordem é geralmente utilizado para exclusão e liberação de memória
    // Complexidade: O(n) para tempo e O(h) para espaço de pilha
    // (n é o número de nós e h é a altura da árvore).
    std::cout << "<";
    if(!is_empty(root)){
        tree_walk_postorder(root->left);
        std::cout << " ";
        tree_walk_postorder(root->right);
        std::cout << root->val << " ";
    }
    std::cout << ">";

}

inline void tree_stats(TreeNode* root) {
    if (root == nullptr) {
        std::cout << "Root nullptr.\n";
        return;
    }
    std::cout << "Nó atual: " << root->val
              <<  "\nL/R: "   << root->left     <<   " / "   << root->right
              << "\nnos="     << tree_size(root)
              << "\naltura="  << tree_height(root)
              << "\nbalance=" << tree_balance(root)   << "\n";

}


// Funções de Leetcode

inline int tree_sum(TreeNode* root, int acumulador = 0){
    if (is_empty(root)) { // caso base
       return acumulador;
    }
    // soma o nó atual
    acumulador += root->val;

    // passa o acumulador já somado como parametro e salva o resultado em acumulador
    acumulador = tree_sum(root->left,acumulador);

    // todo passo recursivo tem uma chamada de retorna oculta que retorna para a chamada que o criou ao final

    // acessa o nó da direita
    return tree_sum(root->right, acumulador);

    // return implicito da chamada filha para a criadora
}

// soma todos os nós da árvore atual com base em intervalo definido (inclusivo)
inline int tree_sum_conditional(TreeNode* root, int min, int max, int acumulador = 0){
    if (is_empty(root)) { // caso base
       return acumulador;
    }
    if (root->val >= min && root->val <= max) {
        acumulador += root->val;

    }

    // passa o acumulador já somado como parametro e salva o resultado em acumulador
    acumulador = tree_sum_conditional(root->left,min, max,acumulador);

    // todo passo recursivo tem uma chamada de retorna oculta que retorna para a chamada que o criou ao final

    // acessa o nó da direita
    return tree_sum_conditional(root->right, min, max, acumulador);

    // return implicito da chamada filha para a criadora
}

#endif
