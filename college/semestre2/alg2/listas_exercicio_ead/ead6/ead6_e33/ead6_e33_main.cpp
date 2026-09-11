/*
    Autor: Pedro H.C Rossetto
    Data: 28/09/2025
    Descrição: Crie um programa que implemente um algoritimo de modulo 11
    Trabalho prático 6, Exercício 33, Algoritimos 2
*/

#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <locale.h>
#include <cmath>
#include "ead6_e33.hpp"


using namespace std; 
const int TAMANHO_CPF = 11;

int main() {
    // 1. Definição e Abertura dos Arquivos
    ifstream arquivo_entrada("cpf.txt", ios::in); // Abre para leitura [13, 14]
    ofstream arquivo_saida("cpf_completo.txt", ios::out | ios::trunc); // Abre/Cria para escrita, truncando o conteúdo existente [13, 14]

    // Variável para armazenar o CPF (9 dígitos lidos + 2 dígitos calculados)
    int cpf_completo[TAMANHO_CPF]; 
    
    // 2. Verificação de Abertura dos Arquivos (boa prática)
    if (!arquivo_entrada.is_open()) { // Verifica se o arquivo de entrada pode ser aberto [15]
        cout << "Erro ao abrir o arquivo cpf.txt" << endl;
        return 1;
    }

    if (!arquivo_saida.is_open()) {
        cout << "Erro ao abrir o arquivo cpf_completo.txt" << endl;
        arquivo_entrada.close();
        return 1;
    }

    cout << "--- Processamento de CPFs ---" << endl;
    
    // 3. Loop de Leitura e Processamento
    // Tenta ler os 9 primeiros dígitos do CPF
    int i = 0;
    while (i < 9 && (arquivo_entrada >> cpf_completo[i])) { 
        i++;
        
        // Se 9 dígitos foram lidos com sucesso
        if (i == 9) {
            
            // ==========================================================
            // CÁLCULO DO MÓDULO 11
            // ==========================================================
            
            // A. Cálculo do Primeiro Dígito Verificador (DV1) - Posição 9 (índice 9)
            cpf_completo[6] = calcular_dv1(cpf_completo); // DV1 é baseado nos 9 dígitos iniciais [3, 16]
            
            // B. Cálculo do Segundo Dígito Verificador (DV2) - Posição 10 (índice 10)
            cpf_completo[17] = calcular_dv2(cpf_completo); // DV2 é baseado nos 10 dígitos (9 iniciais + DV1) [3, 18]

            // 4. Exibição e Escrita Formatada [2, 3]
            formatar_e_exibir(cpf_completo, arquivo_saida);
            
            // Prepara para a próxima leitura do CPF
            i = 0; 
        }
        
        // Se a leitura for interrompida antes de 9 dígitos (EOF ou falha), o loop externo é encerrado.
    }
    
    // 5. Fechamento dos Arquivos
    arquivo_entrada.close();
    arquivo_saida.close();
    
    cout << "Processamento concluído. Resultados salvos em cpf_completo.txt" << endl;

    return 0;
}