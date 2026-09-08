# exec_menu/ — playground

Dois mains contra os mesmos headers. Servem pra montar um exemplo da prova na hora e conferir pré-ordem / PNG / números.

```bash
g++ -std=c++17 -Wall bst.cpp -o bst          # BST
g++ -std=c++17 -Wall bst_avl.cpp -o bst_avl  # AVL
```

Rodar daqui. `export_to_dot` gera `arvore` + `arvore.png` no cwd.

## bst.cpp

BST puro. Duplicatas vão à direita (o Graphviz mostra os dois).

- “Buscar nó e seu nível” = profundidade, raiz 0. Não é altura da subárvore.
- Predecessor/sucessor pedem o **valor** e usam `tree_predecessor` / `tree_sucessor` (in-ordem completo).
- Min/max/stats recusam árvore vazia em vez de crashar.
- `tree_fill_random` **não** garante distintos.

Use quando a questão for BST sem rebalance (pior caso lista, in-ordem crescente, delete por sucessor).

## bst_avl.cpp

Mesmo menu + BF da raiz + `avl_height` O(1). Duplicata some no insert.

Use quando a questão for AVL: conferir BF, altura após uma sequência, se a figura da prova está errada (foi o caso da Q3 do EAD4).

Pra **ver as rotações**, o EAD4 já liga o trace. Aqui o trace está desligado; se precisar:

```cpp
avl_set_rotation_trace(true);
tree_insert(root, v);
```

no header, ou rode o `ead4`.
