
#ifndef EAD6_E31_HPP
#define EAD6_E31_HPP

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>


// Gera um novo arquivo com 300 valores aleatórios
void gerar_novo_arquivo_valores();

// Preenche a matriz com valores de um arquivo, validando duplicados
bool preencher_matriz(int matriz[][10], int ordem);

// Exibe os elementos da matriz na tela
void mostrar_matriz(const int matriz[][10], int ordem);

// Retorna a soma dos elementos da diagonal principal
int somar_diagonal_principal(const int matriz[][10], int ordem);

// Retorna a soma dos elementos da diagonal secundária
int somar_diagonal_secundaria(const int matriz[][10], int ordem);

// Retorna a soma dos elementos de uma linha específica
int somar_linha(const int matriz[][10], int ordem, int numero_linha);

// Retorna a soma dos elementos de uma coluna específica
int somar_coluna(const int matriz[][10], int ordem, int numero_coluna);

// Valida se a matriz é um Quadrado Mágico utilizando as funções de soma
bool validar_quadrado_magico(const int matriz[][10], int ordem);

#endif // EAD6_E31_HPP