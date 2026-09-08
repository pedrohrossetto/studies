# ead5/ — laboratório AVL (consultas)

`bst-avl-ead5.cpp` — dois submenus. Árvore de cada questão é local e é `tree_clear` ao voltar.

Q1 lê `arquivo_ead5_q1.txt` daqui ou da pasta pai.

---

## Q1 — CRUD + arquivo

Menu: inserir, mostrar (in/pré/pós), remover, ler arquivo, limpar, DOT.

Arquivo:

```
inserir 10
inserir 2
inserir 3
inserir 18
remover 2
inserir 21
```

Rotações: LR em 10 (`3`); RR em 3 (`-2`).

Resultado, raiz **10**, size 4, altura 2, soma 52:

```
      10
     /  \
    3    18
           \
           21
```

`<10 <3 <> <>> <18 <> <21 <> <>>>>`

Se a prova pedir “mostre a árvore após o arquivo”, é essa.

---

## Q2 — consultas (o que cada item realmente calcula)

Monta a árvore na mão (inserir / random). Depois:

| Item | Implementação | Cuidado |
|---|---|---|
| Nós por nível | `count_nodes_per_height` | nível 0 = raiz. Imprime até a altura. |
| Fator de balanceamento | `avl_balance` do **nó buscado** | não é o BF da raiz, a menos que você digite a raiz. Folha = 0. |
| Maior + nível | `tree_max` + `node_level` | maior = mais à direita. Nível ≠ altura do nó. |
| LCA | desce enquanto a e b estão do mesmo lado | falha se algum valor não existe. LCA de `x,x` é o próprio `x`. |
| Soma | `tree_sum` | todos os nós. |
| Elementos do nível do menor | `node_level(min)` + `print_nodes_at_height` | menor é o mais à esquerda; imprime **todos** daquele nível, não só o min. |

Random: só valores **distintos**. Se pedir mais do que cabe no `[min,max]` (descontando o que já está na árvore), recusa e não trava.

---

## Respostas-tipo

- “Quantos nós no nível k?” — raiz conta como nível 0. Árvore completa de altura h tem `2^k` nós no nível k, `k = 0..h`.
- “BF do nó X” — `h(esq)-h(dir)` usando a altura **armazenada**. Não recalcule `tree_height` na prova se o desenho já tem as alturas.
- “Nível do máximo” — em AVL não é necessariamente a altura da árvore; o máximo pode estar acima de uma folha mais profunda do lado esquerdo.
