# modules/

Headers compartilhados. São a implementação que a prova usa. Tudo `inline` em `.hpp` — não existe `.cpp` correspondente.

## arvore-binaria.hpp — BST

`TreeNode { int val; TreeNode *left, *right; }`

| Função | Nota |
|---|---|
| `tree_insert(root, v)` | iguais → direita. `root` por referência. |
| `node_delete(root, v)` | 0 filhos / 1 filho / 2 filhos (sucessor). Silencia se `v` não existe. |
| `node_search` / `node_search_iteractive` | bool vs ponteiro. Iterativa não estoura stack. |
| `tree_min` / `tree_max` | `nullptr` se vazia. |
| `node_sucessor` / `node_predecessor` | só via filho. `nullptr` se não tem. |
| `tree_sucessor(root, v)` / `tree_predecessor` | in-ordem verdadeiro a partir da raiz. |
| `tree_height` | O(n). Vazia = -1. |
| `tree_balance` | `h(esq)-h(dir)`, O(n). Não rebalanceia. |
| `node_level` / `node_height_search` | **nível** (raiz=0), não altura. -1 se não achar. |
| `tree_size` / `tree_sum` / `tree_sum_conditional` | condicional visita tudo (sem poda). |
| `tree_clear(root)` | pós-ordem + `root = nullptr`. |
| `tree_walk_{in,pre,post}order` | pré/pós imprimem `<>` aninhado. |
| `tree_fill_random` | **permite duplicata**. |

Remoção — copiar o caso 2 filhos se pedir código:

```
suc = min(t->right)
t->val = suc->val
delete suc em t->right
```

## arvore-binaria-avl.hpp — AVL

`AVLNode { int val; AVLNode *left, *right; int height; }` — folha nasce com `height = 0`.

| Função | Nota |
|---|---|
| `avl_height(n)` | O(1). `nullptr` → -1. |
| `avl_balance(n)` | O(1). `h(esq)-h(dir)`. |
| `avl_rotate_left` / `avl_rotate_right` | atualizam altura: antigo pai primeiro. |
| `avl_rebalance` | LL / LR / RR / RL. |
| `tree_insert` | duplicata **ignorada**. |
| `node_delete` | igual BST + `update_height` + `rebalance` na volta. |
| `avl_set_rotation_trace(true)` | imprime `Rotação XX no nó Y`. |
| `lowest_common_ancestor(root, a, b)` | `nullptr` se algum não existe. |
| `node_level` / `print_nodes_at_height` / `count_nodes_at_height` | parâmetro é **nível**, raiz=0. |
| `count_nodes_per_height` | imprime qtd por nível 0..altura. |
| `tree_sum_conditional` | **poda** ramos fora de `[min,max]`. |
| `tree_fill_random` | só distintos; recusa se não cabem no intervalo (não trava). |
| `tree_apply_ops_stream` | linhas `inserir N` / `remover N`. |
| `avl_stats` | filhos `null` se não existirem. |

Insert AVL (esqueleto):

```
desce BST
folha nova height 0
na volta: update_height + rebalance
```

Delete AVL: mesmos 3 casos, na volta `update_height` + `rebalance`. Remover pode desbalancear **vários** ancestrais — por isso o rebalance é em todo o caminho, não só no primeiro.

## graphviz_bintree.hpp

`export_to_dot(root, "nome")` → `nome` (DOT) + `nome.png`. ID do nó = endereço, não a chave — duplicatas BST não fundem.

## menu_funcoes.hpp / utils_plus.hpp / text_files_plus.hpp

Menu encadeado com `std::function`. `lerInteiroValido`, `gerarAleatorio` (troca min/max se invertidos).

`abrir_arquivo_leitura_candidatos({ "a.txt", "ead4/a.txt" })` — tenta na ordem, só erra se todos falharem.
