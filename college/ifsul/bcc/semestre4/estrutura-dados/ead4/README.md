# ead4/ — exercícios AVL (inserção, remoção, rotações)

`bst-avl-ead4.cpp` — cada opção **zera** a árvore antes. Rotações são impressas. PNG em `arvore_qN.png` (cwd).

Rodar daqui ou da pasta pai. Q5 acha `arquivo_ead4_q5.txt` nos dois.

Pré-ordem abaixo é o dump `tree_walk_preorder` (`<val <esq> <dir>>`).

---

## Q1 — inserir

`53, 26, 14, 7, 30, 36, 23, 86, 35, 18, 40, 25, 90`

Rotações:
- `14` → **LL** em 53
- `36` → **LR** em 53

Raiz final **26**:

```
            26
          /    \
        14      36
       /  \    /  \
      7   23  30  53
         / \   \  / \
       18  25  35 40 86
                       \
                       90
```

Pré-ordem: `<26 <14 <7 <> <>> <23 <18 <> <>> <25 <> <>>>> <36 <30 <> <35 <> <>>> <53 <40 <> <>> <86 <> <90 <> <>>>>>>`

---

## Q2 — mix

Build: `4, 2, 3, 10, 9, 5`

Rotações no build: LR em 4 (`3`), RL em 4 (`9`), RL em 3 (`5`).

Original: raiz **4** — `<4 <3 <2 <> <>> <>> <9 <5 <> <>> <10 <> <>>>>`

Depois: `-2`, `+7`, `+16`, `+20`, `-4`, `-9`

- `+7` → **RL** em 4
- `+20` → **RR** em 10
- `-4` → **RR** em 5

Final, raiz **10**:

```
        10
       /  \
      5    16
     / \     \
    3   7     20
```

`<10 <5 <3 <> <>> <7 <> <>>> <16 <> <20 <> <>>>>`

---

## Q3 — a figura da questão estava errada

`47, 35, 40, 32, 42, 30`

- `40` → **LR** em 47
- `30` → **LL** em 35  (não em 40)

Raiz **40**:

```
        40
       /  \
     32    47
    /  \   /
   30  35 42
```

`<40 <32 <30 <> <>> <35 <> <>>> <47 <42 <> <>> <>>>`

---

## Q4 — insert/delete

Build: `30, 25, 15, 45, 41, 35, 43, 56, 50`

Rotações no build: LL em 30 (`15`), RL em 30 (`41`), RL em 25 (`35`), RR em 41 (`50`).

Original, raiz **30**: `<30 <25 <15 <> <>> <>> <45 <41 <35 <> <>> <43 <> <>>> <56 <50 <> <>> <>>>>`

Ops: `-45`, `-25`, `+12`, `+42`, `+38`, `-41`, `-56`, `+23`

- `-25` → **RL** em 30. O resto desta sequência não rotaciona.

Final, raiz **42**:

```
            42
          /    \
        30      50
       /  \     /
     15    35  43
    /  \     \
   12  23     38
```

`<42 <30 <15 <12 <> <>> <23 <> <>>> <35 <> <38 <> <>>>> <50 <43 <> <>> <>>>`

---

## Q5 — arquivo `arquivo_ead4_q5.txt`

```
inserir 10, 2, 3, 18, 5
remover 3
inserir 21
remover 2
```

Rotações: LR em 10 (`3`); RR em 10 (`21`); RR em 5 (`-2`).

Final, raiz **18**:

```
      18
     /  \
    5    21
     \
     10
```

`<18 <5 <> <10 <> <>>> <21 <> <>>>`
