# mips-assembly-ac1-core
Implementar programas em linguagem MIPS Assembly utilizando exclusivamente os conceitos, técnicas e instruções estudados em aula.  A atividade tem por objetivo consolidar os conhecimentos relacionados à organização da memória, utilização de registradores, acesso à memória principal, operações aritméticas, estruturas condicionais e laços de repetição, considerando processadores MIPS.

# Declaração de Diretrizes para o Uso de Inteligência Artificial e Autoria

Este documento estabelece as regras e os limites para o desenvolvimento de programas e soluções nesta disciplina. A submissão de qualquer atividade implica a aceitação integral destas normas.

## 1. Alinhamento Metodológico e Conteúdo Programático
* **Aderência Estrita:** Todos os programas desenvolvidos e entregues deverão refletir rigorosamente as técnicas, instruções, pseudo-instruções e métodos apresentados nas aulas.
* **Incompatibilidade e Penalização:** O uso de construções, comandos, estilos de programação ou quaisquer recursos dissonantes do conteúdo efetivamente ministrado será classificado como incompatível com os objetivos pedagógicos da atividade. Soluções que incorram nessa desconformidade receberão automaticamente a **nota zero**.

## 2. Processo de Verificação e Defesa Oral
* **Examinação de Autoria:** O professor reserva-se o direito de, a qualquer momento, exigir explicações orais detalhadas sobre a implementação, o funcionamento e as decisões técnicas adotadas na solução submetida.
* **Evidência de Incompatibilidade:** A incapacidade do aluno em explicar de forma adequada e fundamentada o conteúdo do código entregue será considerada evidência clara de incompatibilidade entre a autoria declarada e a solução apresentada. Nesses casos, a atividade receberá **nota zero**.

## 3. Como rodar este projeto
### 1. Pré-requisitos (Windows):
Você precisa ter o ecossistema MSYS2 (UCRT64) instalado com o GCC e o NASM.

Baixe o MSYS2.

Este repositório contém código Assembly e já está configurado para compilação, execução e depuração automatizadas dentro do Visual Studio Code no Windows.

## 🛠️ 1. Pré-requisitos do Sistema

Para rodar o código, é necessário instalar o compilador (`gcc`), o montador (`nasm`) e o depurador (`gdb`) através do ecossistema MSYS2.

1. Baixe e instale o [MSYS2](https://www.msys2.org/).
2. Abra o terminal **MSYS2 UCRT64** (procure no Iniciar do Windows) e execute o comando abaixo:
   ```bash
   pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-nasm mingw-w64-ucrt-x86_64-gdb

### 2. No VS Code:

Instale as extensões recomendadas em ".extensions.json"

### 3. Executando:
(após instalação das extensões e configuração do ambiente)
Para rodar pelo terminal: Abra o .asm e aperte Ctrl + Shift + B.

Para debugar: Coloque seus breakpoints e aperte F5.