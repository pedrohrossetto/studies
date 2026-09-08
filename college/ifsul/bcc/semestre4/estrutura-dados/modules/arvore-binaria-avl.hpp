#ifndef ARVORE_AVL_HPP
#define ARVORE_AVL_HPP

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <istream>
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

inline bool is_empty(AVLNode* root) {
    return root == nullptr;
}

inline AVLNode* create_avl_node(int val) {
    return new AVLNode(val);
}

// ── Altura e balanceamento ────────────────────────────────────────────────────

// O(1) — lê a altura armazenada no nó; retorna -1 para nullptr (convenção padrão AVL)
inline int avl_height(AVLNode* node) {
    return node ? node->height : -1;
}

// O(1) — atualiza a altura do nó com base nas alturas dos filhos
inline void avl_update_height(AVLNode* node) {
    if (!node) return;
    node->height = 1 + std::max(avl_height(node->left), avl_height(node->right));
}

// Liga/desliga o print das rotações (LL/RR/LR/RL) durante insert/delete.
inline bool& avl_rotation_trace() {
    static bool enabled = false;
    return enabled;
}

inline void avl_set_rotation_trace(bool on) {
    avl_rotation_trace() = on;
}

// fator de balanceamento: altura(esq) - altura(dir)
inline int avl_balance(AVLNode* node) {
    if (!node) return 0;
    return avl_height(node->left) - avl_height(node->right);
}

// altura recursiva genérica O(n) — use avl_height para consultas normais
inline int tree_height(AVLNode* root) {
    if (!root) return -1;
    return 1 + std::max(tree_height(root->left), tree_height(root->right));
}

// ── Busca ─────────────────────────────────────────────────────────────────────

// busca recursiva aproveitando a ordenação BST: O(log n)
// retorna true se o valor for encontrado, false caso contrário
inline bool node_search(AVLNode* root, int val) {
    if (is_empty(root)) return false;
    if (root->val == val) return true;
    if (val < root->val) return node_search(root->left,  val);
    return               node_search(root->right, val);
}
// busca iterativa aproveitando a ordenação BST: O(log n)
// retorna o nó encontrado ou nullptr se não encontrado
inline AVLNode* node_search_iteractive(AVLNode* root, int val) {
    while (root && val != root->val)
        root = (val < root->val) ? root->left : root->right;
    return root;
}

// retorna o nível (profundidade a partir da raiz) de um valor: raiz = nível 0
// -1 se o valor não for encontrado — não confundir com AVLNode::height,
// que mede a altura da subárvore (de baixo para cima), não a profundidade
inline int node_level(AVLNode* root, int val, int nivel = 0) {
    if (is_empty(root)) return -1;
    if (root->val == val) return nivel;
    if (val < root->val) return node_level(root->left,  val, nivel + 1);
    return               node_level(root->right, val, nivel + 1);
}

// ── Busca de extremos ─────────────────────────────────────────────────────────

inline AVLNode* tree_min(AVLNode* root) {
    if (!root) return nullptr;
    while (root->left) root = root->left;
    return root;
}

inline AVLNode* tree_max(AVLNode* root) {
    if (!root) return nullptr;
    while (root->right) root = root->right;
    return root;
}

// Sucessor do nó: só existe se houver filho direito (sem ponteiro para pai).
inline AVLNode* node_sucessor(AVLNode* root) {
    if (!root || !root->right) return nullptr;
    return tree_min(root->right);
}

// Predecessor do nó: só existe se houver filho esquerdo.
inline AVLNode* node_predecessor(AVLNode* root) {
    if (!root || !root->left) return nullptr;
    return tree_max(root->left);
}

// Sucessor in-ordem de um valor, a partir da raiz (cobre o caso sem filho direito).
inline AVLNode* tree_sucessor(AVLNode* root, int val) {
    AVLNode* suc = nullptr;
    while (root) {
        if (val < root->val) {
            suc = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return suc;
}

// Predecessor in-ordem de um valor, a partir da raiz.
inline AVLNode* tree_predecessor(AVLNode* root, int val) {
    AVLNode* pred = nullptr;
    while (root) {
        if (val > root->val) {
            pred = root;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return pred;
}

// ── Busca Específicas ─────────────────────────────────────────────────────────

// retorna o LCA (Lowest Common Ancestor) de dois valores na árvore
// Se um dos valores não for encontrado, retorna nullptr
// Se ambos os valores forem encontrados, retorna o LCA mais próximo
// O(log n)
inline AVLNode* lowest_common_ancestor(AVLNode* root, int val, int val2) {
    if (is_empty(root)) return nullptr;
    if (!node_search(root, val) || !node_search(root, val2)) {
        return nullptr;
    }
    while (root) {
        if (val < root->val && val2 < root->val) root = root->left;
        else if (val > root->val && val2 > root->val) root = root->right;
        else return root;
    }
    return nullptr;
}

// imprime os nós de um nível (profundidade a partir da raiz) específico
// nivel usa contagem regressiva: decrementa a cada descida, imprime ao chegar em 0
inline void print_nodes_at_height(AVLNode* root, int nivel) {
    if (is_empty(root)) return;
    if (nivel == 0) {
        std::cout << root->val << " ";
    } else {
        print_nodes_at_height(root->left,  nivel - 1);
        print_nodes_at_height(root->right, nivel - 1);
    }
}

// conta quantos nós existem exatamente em um nível (profundidade a partir da raiz) específico
inline int count_nodes_at_height(AVLNode* root, int nivel) {
    if (is_empty(root)) return 0;
    if (nivel == 0) return 1;
    return count_nodes_at_height(root->left,  nivel - 1)
         + count_nodes_at_height(root->right, nivel - 1);
}

// exibe a quantidade de nós em cada nível da árvore
inline void count_nodes_per_height(AVLNode* root) {
    if (is_empty(root)) return;
    int altura = tree_height(root); // 0-based (raiz sem filhos = altura 0)
    for (int nivel = 0; nivel <= altura; nivel++) {
        std::cout << "Nível " << nivel << ": "
                   << count_nodes_at_height(root, nivel) << " nós" << std::endl;
    }
}


// ── Métricas ──────────────────────────────────────────────────────────────────

inline int tree_size(AVLNode* root) {
    if (is_empty(root)) return 0;
    return 1 + tree_size(root->left) + tree_size(root->right);
}


// ── Memória ───────────────────────────────────────────────────────────────────

inline void tree_clear(AVLNode*& root) {
    if (!is_empty(root)) {
        tree_clear(root->left);
        tree_clear(root->right);
        delete root;
        root = nullptr;
    }
}

// ── Travessias ────────────────────────────────────────────────────────────────

inline void tree_walk_inorder(AVLNode* root) {
    if (!is_empty(root)) {
        tree_walk_inorder(root->left);
        std::cout << root->val << " ";
        tree_walk_inorder(root->right);
    }
}

inline void tree_walk_preorder(AVLNode* root) {
    std::cout << "<";
    if (!is_empty(root)) {
        std::cout << root->val << " ";
        tree_walk_preorder(root->left);
        std::cout << " ";
        tree_walk_preorder(root->right);
    }
    std::cout << ">";
}

inline void tree_walk_postorder(AVLNode* root) {
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

inline int tree_sum(AVLNode* root, int acumulador = 0) {
    if (is_empty(root)) return acumulador;
    acumulador += root->val;
    acumulador  = tree_sum(root->left,  acumulador);
    return        tree_sum(root->right, acumulador);
}

// soma valores no intervalo [min, max] aproveitando a ordenação BST para podar ramos
inline int tree_sum_conditional(AVLNode* root, int min, int max, int acumulador = 0) {
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
inline AVLNode* avl_rotate_right(AVLNode* root) {
    if (!root || !root->left) return root;
    AVLNode* left = root->left;
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
inline AVLNode* avl_rotate_left(AVLNode* root) {
    if (!root || !root->right) return root;
    AVLNode* right = root->right;
    AVLNode* X     = right->left;

    right->left  = root;
    root->right  = X;

    avl_update_height(root); // root é filho agora — atualizar antes de right
    avl_update_height(right);
    return right;
}



// ── Rebalanceamento ───────────────────────────────────────────────────────────

inline AVLNode* avl_rebalance(AVLNode* root) {
    if (!root) return nullptr;
    int bal = avl_balance(root);

    if (bal > 1) {
        if (avl_balance(root->left) < 0) {        // LR
            if (avl_rotation_trace())
                std::cout << "Rotação LR no nó " << root->val << "\n";
            root->left = avl_rotate_left(root->left);
            return avl_rotate_right(root);
        }
        if (avl_rotation_trace())
            std::cout << "Rotação LL no nó " << root->val << "\n";
        return avl_rotate_right(root);            // LL
    }

    if (bal < -1) {
        if (avl_balance(root->right) > 0) {       // RL
            if (avl_rotation_trace())
                std::cout << "Rotação RL no nó " << root->val << "\n";
            root->right = avl_rotate_right(root->right);
            return avl_rotate_left(root);
        }
        if (avl_rotation_trace())
            std::cout << "Rotação RR no nó " << root->val << "\n";
        return avl_rotate_left(root);             // RR
    }

    return root;
}

// ── Inserção ──────────────────────────────────────────────────────────────────

inline AVLNode* avl_insert_r(AVLNode* root, int val) {
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

inline void tree_insert(AVLNode*& root, int val) {
    root = avl_insert_r(root, val);
}

// ── Remoção ───────────────────────────────────────────────────────────────────

inline AVLNode* avl_delete_r(AVLNode* root, int val) {
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

inline void node_delete(AVLNode*& root, int val) {
    root = avl_delete_r(root, val);
}

// ── Preenchimento aleatório ───────────────────────────────────────────────────

inline int avl_count_in_range(AVLNode* root, int min_val, int max_val) {
    if (!root) return 0;
    int n = (root->val >= min_val && root->val <= max_val) ? 1 : 0;
    if (root->val > min_val) n += avl_count_in_range(root->left,  min_val, max_val);
    if (root->val < max_val) n += avl_count_in_range(root->right, min_val, max_val);
    return n;
}

inline void tree_fill_random(AVLNode*& root, int n, int min_val, int max_val) {
    if (n <= 0) return;
    if (min_val > max_val) {
        std::cout << "[ERRO] Limite menor maior que o maior.\n";
        return;
    }
    int intervalo = max_val - min_val + 1;
    int livres = intervalo - avl_count_in_range(root, min_val, max_val);
    if (n > livres) {
        std::cout << "[ERRO] Pedido " << n << " distintos, mas só restam "
                  << livres << " valores livres em [" << min_val << ", " << max_val << "].\n";
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

inline void tree_insert_random(AVLNode*& root, int min_val, int max_val) {
    tree_insert(root, gerarAleatorio(min_val, max_val));
}

// ── Diagnóstico ───────────────────────────────────────────────────────────────

inline void avl_stats(AVLNode* root) {
    if (!root) {
        std::cout << "Árvore vazia.\n";
        return;
    }
    auto filho = [](AVLNode* n) -> std::string {
        return n ? std::to_string(n->val) : "null";
    };
    std::cout << "Nó atual: " << root->val
              << "\nL/R: "    << filho(root->left) << " / " << filho(root->right)
              << "\nnos="     << tree_size(root)
              << "\naltura="  << root->height
              << "\nbalance=" << avl_balance(root) << "\n";
}

// Aplica linhas "inserir N" / "remover N". Ignora linhas vazias ou malformadas.
inline void tree_apply_ops_stream(AVLNode*& root, std::istream& in) {
    std::string linha;
    while (std::getline(in, linha)) {
        if (linha.empty()) continue;
        std::istringstream ss(linha);
        std::string operacao;
        int valor = 0;
        if (!(ss >> operacao >> valor)) continue;
        if (operacao == "inserir") {
            tree_insert(root, valor);
            std::cout << "Inserindo " << valor << "\n";
        } else if (operacao == "remover") {
            node_delete(root, valor);
            std::cout << "Removendo " << valor << "\n";
        }
    }
}

#endif // ARVORE_AVL_HPP
