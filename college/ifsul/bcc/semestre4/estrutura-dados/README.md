# Estrutura de Dados — Árvores (prova)

Pasta de consulta: BST em `modules/arvore-binaria.hpp`, AVL em `modules/arvore-binaria-avl.hpp`.
Menus em `exec_menu/`. Exercícios EAD em `ead4/` e `ead5/`.

Compilar a partir **desta** pasta (ou da subpasta; os `.txt` são procurados nos dois lugares):

```bash
g++ -std=c++17 -Wall ead4/bst-avl-ead4.cpp -o ead4 && ./ead4
g++ -std=c++17 -Wall ead5/bst-avl-ead5.cpp -o ead5 && ./ead5
g++ -std=c++17 -Wall exec_menu/bst.cpp -o bst && ./bst
g++ -std=c++17 -Wall exec_menu/bst_avl.cpp -o bst_avl && ./bst_avl
```

Graphviz (`dot`) é opcional. Sem ele o `.dot` ainda é gerado; o PNG falha com aviso.

---

## Convenções (não misturar na prova)

| Nome | O que é | Vazio | Folha |
|---|---|---|---|
| **Altura** (`tree_height` / `AVLNode::height`) | caminho mais longo até uma folha, de baixo pra cima | `-1` | `0` |
| **Nível / profundidade** (`node_level`) | distância da raiz, de cima pra baixo | valor inexistente → `-1` | raiz = `0` |
| **Fator de balanceamento** | `h(esq) - h(dir)` | `0` | `0` |

AVL válido ⇔ `|BF| ≤ 1` em **todo** nó. Altura AVL de `n` nós: `⌊log₂ n⌋` … `~1.44 log₂ n`.

`avl_height(n)` é O(1) (campo no nó). `tree_height` BST é O(n) — recalcula.

---

## BST vs AVL (o que muda de verdade)

- **BST** (`TreeNode`): sem altura armazenada. Inserção de iguais **vai à direita**. Pior caso O(n) se a sequência for ordenada.
- **AVL** (`AVLNode`): campo `height`, rebalanceia depois de cada insert/delete. **Duplicata é ignorada**.
- Remoção com dois filhos: copia o **sucessor** (mínimo da subárvore direita) e remove o sucessor. Não usa predecessor.
- `node_sucessor(n)` / `node_predecessor(n)` só olham filho dir/esq. Sem ponteiro pra pai, **não sobem**. Pra sucessor in-ordem real use `tree_sucessor(raiz, val)`.

---

## Rotações AVL — decidir em 5 segundos

Olha o nó com `|BF| > 1` (o primeiro desbalanceado no caminho de volta):

```
BF > +1  (pesada à esquerda)
  filho esq BF < 0  → LR   (esq no filho, dir no nó)
  senão             → LL   (só dir no nó)     // inclui BF do filho == 0 na remoção

BF < -1  (pesada à direita)
  filho dir BF > 0  → RL   (dir no filho, esq no nó)
  senão             → RR   (só esq no nó)
```

Desenho mental:

```
LL:  3          2          RR:  1          2
    /    →     / \             \    →     / \
   2          1   3             2        1   3
  /                              \
 1                                3

LR:  3          3          2     RL: simétrico
    /          /          / \
   1    →     2    →     1   3
    \        /
     2      1
```

Na prova: insere/remove, atualiza alturas **de baixo pra cima**, aplica **uma** rotação (simples ou dupla) no primeiro `|BF|>1`. Depois disso aquele caminho volta a `|BF|≤1`.

O EAD4 imprime `Rotação LL/RR/LR/RL no nó X` sozinho. Liga/desliga com `avl_set_rotation_trace(true)`.

---

## Complexidade (resposta padrão)

| Op | BST médio | BST pior | AVL |
|---|---|---|---|
| busca / insert / delete | O(log n) | O(n) | O(log n) |
| in/pré/pós-ordem | O(n) | O(n) | O(n) |
| espaço extra (recursão) | O(h) | O(n) | O(log n) |

Travessias:
- **in-ordem** = crescente (BST/AVL)
- **pré-ordem** = raiz, esq, dir — reproduz a forma; é o dump dos menus
- **pós-ordem** = esq, dir, raiz — mesma ordem do `tree_clear`

---

## Armadilhas que caem em prova

1. Altura da árvore vazia é **-1**, não 0. Folha tem altura 0, BF 0.
2. Nível da raiz é **0**. Não chame isso de altura do nó.
3. LCA em BST: se ambos `<` nó, desce esq; se ambos `>`, desce dir; senão o nó **é** o LCA. Os dois valores têm que existir.
4. Sequência crescente numa BST vira lista. Na AVL vira árvore quase completa.
5. Depois de rotação, atualiza altura do **filho primeiro**, depois do novo pai. O código já faz isso.
6. `tree_stats` / BF de um nó: é o BF **daquele** nó, não da árvore inteira.
7. Arquivos `inserir N` / `remover N` — rode o binário da pasta certa (ou da raiz; os programas tentam os dois caminhos).

Detalhe por pasta: `modules/README.md`, `ead4/README.md`, `ead5/README.md`, `exec_menu/README.md`.
