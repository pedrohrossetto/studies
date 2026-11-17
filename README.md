*[Leia em português](README.pt-BR.md)*

# studies

My Computer Science studies (IFSul, 2025–) together with self-study, organized by **subject and concept**
instead of by semester, so related material sits side by side: the stack exercises from Data Structures I
next to the shared stack header, the C++ AVL tree next to the Rust BST.

## Subjects

| Subject | Concepts |
|---|---|
| [programming-fundamentals](programming-fundamentals/) | control flow, arrays, matrices, strings, pointers, structs, functions, recursion, file I/O |
| [data-structures](data-structures/) | memory allocation, stacks, queues, linked lists, BST/AVL, graphs |
| [databases](databases/) | physical design (DDL), DML, queries |
| [computer-architecture](computer-architecture/) | digital circuits, MIPS assembly |
| [object-oriented](object-oriented/) | design patterns, Python OOP projects |
| [software-engineering](software-engineering/) | UML (PlantUML) |
| [web](web/) | HTML, CSS, JavaScript |
| [languages](languages/) | Rust and Python self-study |

Each subject README lists its material **by concept** and **by course**.

## Projects in their own repositories

| Repository | What |
|---|---|
| [cpp-data-structures](data-structures/bst/cpp-data-structures/) | BST, AVL and graph algorithms in C++ |
| [mips-assembly-ac1](https://github.com/pedrohrossetto/mips-assembly-ac1) | MIPS assembly assignment |
| [logistics-events-python](https://github.com/pedrohrossetto/logistics-events-python) | Agribusiness supply-chain model with an event blockchain (Python OOP) |
| [rpg-inventory-python](https://github.com/pedrohrossetto/rpg-inventory-python) | RPG quests and inventory with the State pattern |
| [cards-game-web](https://github.com/pedrohrossetto/cards-game-web) | Card battle game (HTML/CSS/JS) |
| [attendance-control-web](https://github.com/pedrohrossetto/attendance-control-web) | Event attendance control (HTML/CSS/JS) |
| [competitive-programming](https://github.com/pedrohrossetto/competitive-programming) | beecrowd and LeetCode solutions |

They are mounted here as git submodules inside their concept folder. Clone everything with:

```bash
git clone --recurse-submodules https://github.com/pedrohrossetto/studies.git
```

## Naming convention

Folders and files follow `origin_course_what`: `_` separates elements, `-` joins words inside an element,
lowercase, zero-padded numbers and ISO dates. Examples: `ifsul_ed1_lista-03/`, `self_rust_bst/`,
`2025-12-02_prova-02.sql`. Exceptions where tools require it: Python modules use `snake_case`,
and `Cargo.toml`, `Makefile` and `README.md` keep their standard names.

## Building

- C++: `make check` syntax-checks every C++ file. Some exercises include `<windows.h>`, since they were written for Windows/MinGW, and only compile there.
- Rust: `cargo run` inside any crate folder.
