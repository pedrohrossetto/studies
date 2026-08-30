/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high, int acumulador = 0) {
        if (root == nullptr) { // caso base
       return acumulador;
    }
    if (root->val >= low && root->val <= high) {
        acumulador += root->val;

    }

    // passa o acumulador já somado como parametro e salva o resultado em acumulador
    acumulador = rangeSumBST(root->left, low, high, acumulador);

    // todo passo recursivo tem uma chamada de retorna oculta que retorna para a chamada que o criou ao final

    // acessa o nó da direita
    return rangeSumBST(root->right, low, high, acumulador);

    // return implicito da chamada filha para a criadora
}
    };
