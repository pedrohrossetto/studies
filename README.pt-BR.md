*[Read in English](README.md)*

# studies

Meus estudos de Ciência da Computação (IFSul, 2025–) junto com estudo próprio, organizados por **assunto e
conceito** em vez de por semestre, para que material relacionado fique lado a lado: os exercícios de pilha de
Estrutura de Dados I ao lado do header de pilha, a AVL em C++ ao lado da BST em Rust.

## Assuntos

| Assunto | Conceitos |
|---|---|
| [programming-fundamentals](programming-fundamentals/README.pt-BR.md) | controle de fluxo, vetores, matrizes, strings, ponteiros, structs, funções, recursão, arquivos |
| [data-structures](data-structures/README.pt-BR.md) | alocação de memória, pilhas, filas, listas encadeadas, BST/AVL, grafos |
| [databases](databases/README.pt-BR.md) | projeto físico (DDL), DML, consultas |
| [computer-architecture](computer-architecture/README.pt-BR.md) | circuitos digitais, assembly MIPS |
| [object-oriented](object-oriented/README.pt-BR.md) | padrões de projeto, projetos de POO em Python |
| [software-engineering](software-engineering/README.pt-BR.md) | UML (PlantUML) |
| [web](web/README.pt-BR.md) | HTML, CSS, JavaScript |
| [languages](languages/README.pt-BR.md) | estudo próprio de Rust e Python |

Cada README de assunto lista o material **por conceito** e **por disciplina**.

## Projetos em repositórios próprios

| Repositório | O quê |
|---|---|
| [cpp-data-structures](data-structures/bst/cpp-data-structures/) | BST, AVL e algoritmos em grafos em C++ |
| [mips-assembly-ac1](https://github.com/pedrohrossetto/mips-assembly-ac1) | Atividade em assembly MIPS |
| [logistics-events-python](https://github.com/pedrohrossetto/logistics-events-python) | Modelo de cadeia logística do agronegócio com blockchain de eventos (POO em Python) |
| [rpg-inventory-python](https://github.com/pedrohrossetto/rpg-inventory-python) | Missões e inventário de RPG com o padrão State |
| [cards-game-web](https://github.com/pedrohrossetto/cards-game-web) | Jogo de batalha de cartas (HTML/CSS/JS) |
| [attendance-control-web](https://github.com/pedrohrossetto/attendance-control-web) | Controle de presenças em evento (HTML/CSS/JS) |
| [competitive-programming](https://github.com/pedrohrossetto/competitive-programming) | Soluções do beecrowd e do LeetCode |

Eles estão montados aqui como submódulos git dentro da pasta do conceito. Para clonar tudo:

```bash
git clone --recurse-submodules https://github.com/pedrohrossetto/studies.git
```

## Padrão de nomes

Pastas e arquivos seguem `origem_disciplina_assunto`: `_` separa elementos, `-` une palavras dentro de um
elemento, minúsculas, números com zero à esquerda e datas ISO. Exemplos: `ifsul_ed1_lista-03/`,
`self_rust_bst/`, `2025-12-02_prova-02.sql`. Exceções exigidas por ferramentas: módulos Python usam
`snake_case`, e `Cargo.toml`, `Makefile` e `README.md` mantêm seus nomes padrão.

## Compilando

- C++: `make check` verifica a sintaxe de todos os arquivos C++. Alguns exercícios incluem `<windows.h>`, pois foram escritos para Windows/MinGW, e só compilam lá.
- Rust: `cargo run` dentro da pasta de qualquer crate.
