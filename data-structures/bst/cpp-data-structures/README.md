*[Leia em português](README.pt-BR.md)*


# cpp-data-structures

Binary search trees, AVL trees and graphs in C++17, written for the Data Structures II course
(IFSul, Computer Science, 2026/2). Part of my [studies](https://github.com/pedrohrossetto/studies) archive.

## What's inside

| Folder | Contents |
|---|---|
| `lib/` | Reusable headers: BST (`arvore-binaria.hpp`), AVL with LL/RR/LR/RL rotations (`arvore-binaria-avl.hpp`), Graphviz export of trees, menu and text-file helpers |
| `exec-menu/` | Interactive menus to play with a BST and an AVL tree |
| `ifsul_ed2_ead-04/` | AVL exercises: insertion, removal, rotations (prints each rotation) |
| `ifsul_ed2_ead-05/` | AVL queries: height, level, balance factor, successor/predecessor |
| `ifsul_ed2_trabalho-01/` | Graded assignment using the AVL tree with file input/output |
| `ifsul_ed2_grafos/` | Graph representation and algorithms (in progress) |

## Build and run

```bash
g++ -std=c++17 -Wall exec-menu/bst-avl.cpp -o bst-avl && ./bst-avl
g++ -std=c++17 -Wall ifsul_ed2_ead-04/bst-avl.cpp -o ead4 && ./ead4
```

[Graphviz](https://graphviz.org/) (`dot`) is optional: trees are exported to `.dot`, and to PNG when `dot` is installed.

The detailed study notes (conventions, rotation cheat sheet, complexity) are in the
[Portuguese README](README.pt-BR.md).
