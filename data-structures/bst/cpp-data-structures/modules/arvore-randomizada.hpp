#ifndef _HPP_ARVORE_RANDOMIZADA
#define _HPP_ARVORE_RANDOMIZADA

#include "arvore-binaria.hpp"
#include "utils_plus.hpp"




// Árvore BST randomizada (Martínez–Roura):
// com probabilidade 1/(n+1) o novo valor vira raiz da subárvore atual.
static void tree_insert_randomized(BinTreeNode* &tree, int val) {
    int n = tree_size(tree);
    if (is_empty(tree) || gerarAleatorio(0, n) == 0) {
        tree_insert(tree, val);
    } else if (val < tree->value) {
        tree_insert_randomized(tree->left_child, val);
    } else {
        tree_insert_randomized(tree->right_child, val);
    }
}

// Fisher–Yates. Cada permutação das chaves tem a mesma chance.
static void array_shuffle(int *arr, int n) {
    for (int i = n - 1; i > 0; --i) {
        int j = gerarAleatorio(0, i);
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

// Embaralha e insere com a inserção BST já existente.
static void tree_insert_shuffled(BinTreeNode* &tree, int *arr, int n) {
    array_shuffle(arr, n);
    for (int i = 0; i < n; ++i) {
        tree_insert(tree, arr[i]);
    }
}

// n valores aleatórios no intervalo [min_val, max_val], inserção BST comum.
static void tree_fill_random(BinTreeNode* &tree, int n, int min_val, int max_val) {
    for (int i = 0; i < n; ++i) {
        tree_insert(tree, gerarAleatorio(min_val, max_val));
    }
}

// 1, 2, ..., n em ordem — pior caso clássico da BST (vira uma lista).
static void tree_fill_sequential(BinTreeNode* &tree, int n) {
    for (int i = 1; i <= n; ++i) {
        tree_insert(tree, i);
    }
}

// Mesmas chaves 1..n, mas em ordem aleatória, inserção BST comum.
static void tree_fill_range_shuffled(BinTreeNode* &tree, int n) {
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = i + 1;
    }
    tree_insert_shuffled(tree, arr, n);
    delete[] arr;
}

// Mesmas chaves 1..n com inserção randomizada (pode subir para a raiz).
static void tree_fill_range_randomized(BinTreeNode* &tree, int n) {
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = i + 1;
    }
    array_shuffle(arr, n);
    for (int i = 0; i < n; ++i) {
        tree_insert_randomized(tree, arr[i]);
    }
    delete[] arr;
}

#endif
