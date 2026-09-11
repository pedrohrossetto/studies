#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <ctime>

// #include "../modules/arvore-binaria-avl.hpp"


using namespace std;



struct AVLNode {
    int val; // id_veiculo
    string placa;
    char cat; // C, P ou U
    float km;
    float diaria;
    AVLNode* left;
    AVLNode* right;
    int height;
    AVLNode(int val, string placa, char cat, float km, float diaria) : val(val), placa(placa), cat(cat), km(km),diaria(diaria), left(nullptr), right(nullptr), height(0) {}
    };

// Utilitarios
inline bool tree_is_empty(AVLNode* root);
inline AVLNode* create_avl_node(int val);
inline void tree_clear(AVLNode*& root);
inline int avl_height(AVLNode* node);
inline void avl_update_height(AVLNode* node);
inline int avl_balance(AVLNode* node);
inline bool node_search(AVLNode* root, int val);
inline AVLNode* node_search_placa(AVLNode* root, string placa);
// --- Insercao
inline AVLNode* avl_rotate_right(AVLNode* root);
inline AVLNode* avl_rotate_left(AVLNode* root);
inline AVLNode* avl_rebalance(AVLNode* root);
inline AVLNode* avl_insert_r(AVLNode* root, int val, string placa, char cat, float km, float diaria);
inline void tree_insert(AVLNode*& root, int val, string placa, char cat, float km, float diaria);

// -- Remocao
inline AVLNode* tree_min(AVLNode* root);
inline void node_delete(AVLNode*& root, int val);
inline AVLNode* avl_delete_r(AVLNode* root, int val);

// -- Gravar
inline void gravar_pre_ordem(AVLNode* root,std::ofstream &arquivo);

// -- Arquivos
inline bool abrir_arquivo_escrita(std::ofstream &arquivo, const std::string &caminho);
inline bool abrir_arquivo_leitura(std::ifstream &arquivo, const std::string &caminho);

int main(){




    AVLNode* root = nullptr;
    bool rodando = true;
    ofstream arquivo_saida;
    if(!abrir_arquivo_escrita(arquivo_saida,"frota_atualizada.txt")){
        return 1;
    }
    ifstream arquivo_entrada;
    if(!abrir_arquivo_leitura(arquivo_entrada,"entrada.txt")){
        return 1;
    }


    while(rodando) {
        int menu;
        cout << "Selecione uma opcao:\n 0 - Sair e gravar em frota_atualizada.txt\n 1 - Inserir\n 2 - Aplicar Desconto\n 3 - Relatorio da Frota\n 4 - Ler Arquivo Texto\n\n";
        cin >> menu;

        switch(menu){
            case 0:
                gravar_pre_ordem(root,arquivo_saida);
                rodando = false;

                break;

            case 1:{
                cout<<"Cadastrar Veiculo\n";
                int val;
                string placa;
                char cat;
                float km;
                float diaria;

                cout << "id do veiculo:\n";
                cin >> val;

                cout << "placa:\n";
                cin >> placa;

                cout << "categoria:\n";
                cin >> cat;

                cout << "km:\n";
                cin >> km;

                cout << "diaria:\n";
                cin >> diaria;

                tree_insert(root,val,placa,cat,km,diaria);




                break;}
            case 2:
                cout<<"Aplicar Desconto por Categoria\n";
                break;
            case 3:
                cout<<"Relatorio de Frota\n";
                break;
            case 4:
                cout<<"Ler Arquivo texto\n";

                std::string linha;
                while (std::getline(arquivo_entrada, linha)) {
                    if (linha.empty()) continue;

                    std::istringstream ss(linha);

                    string operacao;
                    int valor = 0;
                    string placa;
                    char cat;
                    float km;
                    float diaria;

                    if (!(ss >> operacao)) continue;

                    if (operacao == "cadastrar") {
                        ss >> valor >> placa >> cat >> km >> diaria;
                        tree_insert(root, valor, placa, cat, km , diaria);
                        std::cout << "Cadastrando " << valor << "\n";
                    } else if (operacao == "remover") {
                        ss >> placa;
                        node_delete(root, node_search_placa(root,placa)->val);
                        std::cout << "Removendo " << placa << "\n";
                    }

                }


                break;
        }
    }

    if (arquivo_entrada.is_open()) {
        arquivo_entrada.close();
    }
    if (arquivo_saida.is_open()) {
        arquivo_saida.close();
    }
    tree_clear(root);

}

inline bool tree_is_empty(AVLNode* root) {
    return root == nullptr;
}

inline AVLNode* create_avl_node(int val, string placa, char cat, float km, float diaria) {
    return new AVLNode(val,placa,cat,km,diaria);
}

inline void tree_clear(AVLNode*& root) {
    if (!(root == nullptr)) {
        tree_clear(root->left);
        tree_clear(root->right);
        delete root;
        root = nullptr;
    }
}

// O(1) — lê a altura armazenada no nó; retorna -1 para nullptr (convenção padrão AVL)
inline int avl_height(AVLNode* node) {
    return node ? node->height : -1;
}

// O(1) — atualiza a altura do nó com base nas alturas dos filhos
inline void avl_update_height(AVLNode* node) {
    if (!node) return;
    node->height = 1 + std::max(avl_height(node->left), avl_height(node->right));
}

inline int avl_balance(AVLNode* node) {
    if (!node) return 0;
    return avl_height(node->left) - avl_height(node->right);
}

// busca recursiva aproveitando a ordenação BST: O(log n)
// retorna true se o valor for encontrado, false caso contrário
inline bool node_search(AVLNode* root, int val) {
    if (tree_is_empty(root)) return false;
    if (root->val == val) return true;
    if (val < root->val) return node_search(root->left,  val);
    return               node_search(root->right, val);
}

inline AVLNode* node_search_placa(AVLNode* root, string placa) {
    while (root && placa != root->placa)
        root = (placa < root->placa) ? root->left : root->right;
    return root;
}


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
            root->left = avl_rotate_left(root->left);
            return avl_rotate_right(root);
        }
        return avl_rotate_right(root);            // LL
    }

    if (bal < -1) {
        if (avl_balance(root->right) > 0) {       // RL
            root->right = avl_rotate_right(root->right);
            return avl_rotate_left(root);
        }
        return avl_rotate_left(root);             // RR
    }

    return root;
}

// ── Inserção ──────────────────────────────────────────────────────────────────

inline AVLNode* avl_insert_r(AVLNode* root, int val, string placa, char cat, float km, float diaria) {
    if (!root) return create_avl_node(val,placa,cat,km,diaria);

    if (val < root->val)
        root->left  = avl_insert_r(root->left,val, placa,cat,km,diaria);
    else if (val > root->val)
        root->right = avl_insert_r(root->right,val, placa,cat,km,diaria);
    else
        return root; // duplicados ignorados

    avl_update_height(root);
    return avl_rebalance(root);
}

inline void tree_insert(AVLNode*& root, int val, string placa, char cat, float km, float diaria) {
    root = avl_insert_r(root, val,placa,cat,km,diaria);
}

// ── Remoção ───────────────────────────────────────────────────────────────────

inline AVLNode* tree_min(AVLNode* root) {
    if (!root) return nullptr;
    while (root->left) root = root->left;
    return root;
}


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

// Pre-order

inline void gravar_pre_ordem(AVLNode* root,std::ofstream &arquivo) {
    if (!tree_is_empty(root)) {
        arquivo << root->val   << " ";
        arquivo << root->placa << " ";
        arquivo << root->cat   << " ";
        arquivo << root->km    << " ";
        arquivo << root->diaria  << endl;

        gravar_pre_ordem(root->left,arquivo);
        gravar_pre_ordem(root->right,arquivo);
    }
}

// -- Funcoes de Arquivos

inline bool abrir_arquivo_escrita(std::ofstream &arquivo, const std::string &caminho) {
    if (arquivo.is_open()) {
        arquivo.close();
    }

    arquivo.open(caminho, std::ios::trunc);


    if (!arquivo.is_open()) {
        std::cout << "\n[ERRO DE ARQUIVO]" << std::endl;
        std::cout << "Operação: Abertura para ESCRITA" << std::endl;
        std::cout << "Caminho tentado: " << caminho << std::endl;
        return false;
    }
    return true;
}
inline bool abrir_arquivo_leitura(std::ifstream &arquivo, const std::string &caminho) {
    if (arquivo.is_open()) {
        arquivo.close();
    }

    arquivo.open(caminho);

    if (!arquivo.is_open()) {
        std::cout << "\n[ERRO DE ARQUIVO]" << std::endl;
        std::cout << "Operação: Abertura para LEITURA" << std::endl;
        std::cout << "Caminho tentado: " << caminho << std::endl;

        return false;
    }
    return true;
}
