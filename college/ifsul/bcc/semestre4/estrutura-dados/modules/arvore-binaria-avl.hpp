#ifndef ARVORE_AVL_HPP
#define ARVORE_AVL_HPP

#include <iostream>
#include "utils_plus.hpp"

// ── Struct ────────────────────────────────────────────────────────────────────

struct AVLNode {
    int val;
    AVLNode* left;
    AVLNode* right;
    int height;
    AVLNode(int val) : val(val), left(nullptr), right(nullptr), height(0) {}
};

// ── Utilitários básicos ───────────────────────────────────────────────────────

static bool is_empty(AVLNode* root) {
    return root == nullptr;
}

static AVLNode* create_avl_node(int val) {
    return new AVLNode(val);
}

// ── Altura e balanceamento ────────────────────────────────────────────────────

// O(1) — lê a altura armazenada no nó; retorna -1 para nullptr (convenção padrão AVL)
static int avl_height(AVLNode* node) {
    return node ? node->height : -1;
}

// O(1) — atualiza a altura do nó com base nas alturas dos filhos
static void avl_update_height(AVLNode* node) {
    node->height = 1 + std::max(avl_height(node->left), avl_height(node->right));
}

// fator de balanceamento: altura(esq) - altura(dir)
static int avl_balance(AVLNode* node) {
    if (!node) return 0;
    return avl_height(node->left) - avl_height(node->right);
}

// altura recursiva genérica O(n) — use avl_height para consultas normais
static int tree_height(AVLNode* root) {
    if (!root) return -1;
    return 1 + std::max(tree_height(root->left), tree_height(root->right));
}

// ── Busca ─────────────────────────────────────────────────────────────────────

// busca recursiva aproveitando a ordenação BST: O(log n)
// retorna true se o valor for encontrado, false caso contrário
static bool node_search(AVLNode* root, int val) {
    if (is_empty(root)) return false;
    if (root->val == val) return true;
    if (val < root->val) return node_search(root->left,  val);
    return               node_search(root->right, val);
}
// busca iterativa aproveitando a ordenação BST: O(log n)
// retorna o nó encontrado ou nullptr se não encontrado
static AVLNode* node_search_iteractive(AVLNode* root, int val) {
    while (root && val != root->val)
        root = (val < root->val) ? root->left : root->right;
    return root;
}

// retorna o nível (profundidade a partir da raiz) de um valor: raiz = nível 0
// -1 se o valor não for encontrado — não confundir com AVLNode::height,
// que mede a altura da subárvore (de baixo para cima), não a profundidade
static int node_level(AVLNode* root, int val, int nivel = 0) {
    if (is_empty(root)) return -1;
    if (root->val == val) return nivel;
    if (val < root->val) return node_level(root->left,  val, nivel + 1);
    return               node_level(root->right, val, nivel + 1);
}

// ── Busca de extremos ─────────────────────────────────────────────────────────

static AVLNode* tree_min(AVLNode* root) {
    if (!root) return nullptr;
    while (root->left) root = root->left;
    return root;
}

static AVLNode* tree_max(AVLNode* root) {
    if (!root) return nullptr;
    while (root->right) root = root->right;
    return root;
}

// menor valor na sub-árvore direita (sucessor imediato)
static AVLNode* node_sucessor(AVLNode* root) {
    if (root->right) return tree_min(root->right);
    return nullptr;
}

// maior valor na sub-árvore esquerda (predecessor imediato)
static AVLNode* node_predecessor(AVLNode* root) {
    if (root->left) return tree_max(root->left);
    return nullptr;
}

// ── Busca Específicas ─────────────────────────────────────────────────────────

// retorna o LCA (Lowest Common Ancestor) de dois valores na árvore
// Se um dos valores não for encontrado, retorna nullptr
// Se ambos os valores forem encontrados, retorna o LCA mais próximo
// O(log n)
static AVLNode* lowest_common_ancestor(AVLNode* root, int val, int val2) {
    if (is_empty(root)) return nullptr;
    if (!node_search(root,val) || !node_search(root,val2)) {
        return nullptr;
    }
    if (val < root->val && val2 < root->val) return lowest_common_ancestor(root->left, val, val2);
    if (val > root->val && val2 > root->val) return lowest_common_ancestor(root->right, val, val2);
    return root;
}

// imprime os nós de um nível (profundidade a partir da raiz) específico
// nivel usa contagem regressiva: decrementa a cada descida, imprime ao chegar em 0
static void print_nodes_at_height(AVLNode* root, int nivel) {
    if (is_empty(root)) return;
    if (nivel == 0) {
        std::cout << root->val << " ";
    } else {
        print_nodes_at_height(root->left,  nivel - 1);
        print_nodes_at_height(root->right, nivel - 1);
    }
}

// conta quantos nós existem exatamente em um nível (profundidade a partir da raiz) específico
static int count_nodes_at_height(AVLNode* root, int nivel) {
    if (is_empty(root)) return 0;
    if (nivel == 0) return 1;
    return count_nodes_at_height(root->left,  nivel - 1)
         + count_nodes_at_height(root->right, nivel - 1);
}

// exibe a quantidade de nós em cada nível da árvore
static void count_nodes_per_height(AVLNode* root) {
    if (is_empty(root)) return;
    int altura = tree_height(root); // 0-based (raiz sem filhos = altura 0)
    for (int nivel = 0; nivel <= altura; nivel++) {
        std::cout << "Nível " << nivel << ": "
                   << count_nodes_at_height(root, nivel) << " nós" << std::endl;
    }
}


// ── Métricas ──────────────────────────────────────────────────────────────────

static int tree_size(AVLNode* root) {
    if (is_empty(root)) return 0;
    return 1 + tree_size(root->left) + tree_size(root->right);
}


// ── Memória ───────────────────────────────────────────────────────────────────

static void tree_clear(AVLNode*& root) {
    if (!is_empty(root)) {
        tree_clear(root->left);
        tree_clear(root->right);
        delete root;
        root = nullptr;
    }
}

// ── Travessias ────────────────────────────────────────────────────────────────

static void tree_walk_inorder(AVLNode* root) {
    if (!is_empty(root)) {
        tree_walk_inorder(root->left);
        std::cout << root->val << " ";
        tree_walk_inorder(root->right);
    }
}

static void tree_walk_preorder(AVLNode* root) {
    std::cout << "<";
    if (!is_empty(root)) {
        std::cout << root->val << " ";
        tree_walk_preorder(root->left);
        std::cout << " ";
        tree_walk_preorder(root->right);
    }
    std::cout << ">";
}

static void tree_walk_postorder(AVLNode* root) {
    std::cout << "<";
    if (!is_empty(root)) {
        tree_walk_postorder(root->left);
        std::cout << " ";
        tree_walk_postorder(root->right);
        std::cout << root->val << " ";
    }
    std::cout << ">";
}

// ── Soma ──────────────────────────────────────────────────────────────────────

static int tree_sum(AVLNode* root, int acumulador = 0) {
    if (is_empty(root)) return acumulador;
    acumulador += root->val;
    acumulador  = tree_sum(root->left,  acumulador);
    return        tree_sum(root->right, acumulador);
}

// soma valores no intervalo [min, max] aproveitando a ordenação BST para podar ramos
static int tree_sum_conditional(AVLNode* root, int min, int max, int acumulador = 0) {
    if (is_empty(root)) return acumulador;
    if (root->val >= min && root->val <= max)
        acumulador += root->val;
    if (root->val > min)  // sub-árvore esquerda pode ter valores >= min
        acumulador = tree_sum_conditional(root->left,  min, max, acumulador);
    if (root->val < max)  // sub-árvore direita pode ter valores <= max
        return tree_sum_conditional(root->right, min, max, acumulador);
    return acumulador;
}

// ── Rotações ──────────────────────────────────────────────────────────────────

/*
 *     root              left
 *    /    \      =>    /    \
 *  left    C          A    root
 *  /  \                   /  \
 * A    X                 X    C
 */
static AVLNode* avl_rotate_right(AVLNode* root) {
    AVLNode* left   = root->left;
    AVLNode* X    = left->right;

    left->right = root;
    root->left  = X;

    avl_update_height(root); // root é filho agora — atualizar antes de left
    avl_update_height(left);
    return left;
}

/*
 *   root              right
 *  /    \      =>    /     \
 * A    right       root     C
 *      /  \        /  \
*    X   C         A    X
 */
static AVLNode* avl_rotate_left(AVLNode* root) {
    AVLNode* right  = root->right;
    AVLNode* X    = right->left;

    right->left  = root;
    root->right  = X;

    avl_update_height(root); // root é filho agora — atualizar antes de right
    avl_update_height(right);
    return right;
}



// ── Rebalanceamento ───────────────────────────────────────────────────────────

static AVLNode* avl_rebalance(AVLNode* root) {
    int bal = avl_balance(root);

    if (bal > 1) {
        if (avl_balance(root->left) < 0)          // left right rotation
            root->left = avl_rotate_left(root->left);
        return avl_rotate_right(root);            // right rotation
    }

    if (bal < -1) {
        if (avl_balance(root->right) > 0)          // right left rotation
            root->right = avl_rotate_right(root->right);
        return avl_rotate_left(root);              // left rotation

    }

    return root;
}

// ── Inserção ──────────────────────────────────────────────────────────────────

static AVLNode* avl_insert_r(AVLNode* root, int val) {
    if (!root) return create_avl_node(val);

    if (val < root->val)
        root->left  = avl_insert_r(root->left,  val);
    else if (val > root->val)
        root->right = avl_insert_r(root->right, val);
    else
        return root; // duplicados ignorados

    avl_update_height(root);
    return avl_rebalance(root);
}

static void tree_insert(AVLNode*& root, int val) {
    root = avl_insert_r(root, val);
}

// ── Remoção ───────────────────────────────────────────────────────────────────

static AVLNode* avl_delete_r(AVLNode* root, int val) {
    if (!root) return nullptr;

    if (val < root->val) {
        root->left  = avl_delete_r(root->left,  val);
    } else if (val > root->val) {
        root->right = avl_delete_r(root->right, val);
    } else {
        if (!root->left || !root->right) {
            AVLNode* filho = root->left ? root->left : root->right;
            delete root;
            return filho;
        }
        // dois filhos: substitui pelo sucessor (menor da sub-árvore direita)
        AVLNode* suc = tree_min(root->right);
        root->val    = suc->val;
        root->right  = avl_delete_r(root->right, suc->val);
    }

    avl_update_height(root);
    return avl_rebalance(root);
}

static void node_delete(AVLNode*& root, int val) {
    root = avl_delete_r(root, val);
}

// ── Preenchimento aleatório ───────────────────────────────────────────────────

static void tree_fill_random(AVLNode*& root, int n, int min_val, int max_val) {
    int intervalo = max_val - min_val + 1;
    if (n > intervalo) {
        std::cout << "[ERRO] Não é possível inserir " << n
                   << " valores distintos em um intervalo de tamanho " << intervalo << ".\n";
        return;
    }

    int inseridos = 0;
    while (inseridos < n) {
        int valor = gerarAleatorio(min_val, max_val);
        if (!node_search(root, valor)) {
            tree_insert(root, valor);
            inseridos++;
        }
    }
}

static void tree_insert_random(AVLNode*& root, int min_val, int max_val) {
    tree_insert(root, gerarAleatorio(min_val, max_val));
}

// ── Diagnóstico ───────────────────────────────────────────────────────────────

static void avl_stats(AVLNode* root) {
    std::cout << "Nó atual: " << root->val
              << "\nL/R: "    << root->left  << " / " << root->right
              << "\nnos="     << tree_size(root)
              << "\naltura="  << root->height
              << "\nbalance=" << avl_balance(root) << "\n";
}

#endif // ARVORE_AVL_HPP
