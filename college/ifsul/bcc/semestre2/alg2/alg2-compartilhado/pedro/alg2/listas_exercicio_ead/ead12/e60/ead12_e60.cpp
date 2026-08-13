/*
    Autor: Pedro H.C Rossetto (Adaptado)
    Data: 10/11/2025
    Descrição: Controle de venda de ingressos (Corrigido)
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <cstdlib> 

using namespace std;

int main() {
    system("cls"); // Comando solicitado

    // ALOCAÇÃO DINÂMICA
    int *v1 = new int[100];
    int *v2 = new int[100];

    // Verificação da alocação
    if (!v1 || !v2) {
        cout << "Erro de alocacao de memoria.\n";
        return 1;
    }

    int n_elem_v1 = 0, n_elem_v2 = 0;
    long long int soma_v1 = 0, soma_v2 = 0;

    // --- CORREÇÃO: Declaração das variáveis que faltavam ---
    char operador[20];    // Para armazenar "adiciona", "mostra", etc.
    char vetor_nome[10];  // Para armazenar "V1" ou "V2"
    char formato[10];     // Para armazenar "int"
    int valor;            // Para armazenar o número lido
    // -------------------------------------------------------

    ofstream escrita_saida("arquivo_saida_e60.txt");
    if (!escrita_saida) {
        cout << "Arquivo saida nao foi aberto.\n";
        delete[] v1;
        delete[] v2;
        return 1;
    }

    ifstream leitura_entradas("arquivo_entrada_e60.txt");
    if (!leitura_entradas) {
        cout << "Arquivo entrada nao foi aberto.\n";
        // Se não abriu entrada, fecha saida antes de sair
        escrita_saida.close();
        delete[] v1;
        delete[] v2;
        return 1;
    }

    // Loop principal de leitura de comandos
    while (leitura_entradas >> operador) {
        
        // --- Operação ADICIONA ---
        if (strcmp(operador, "adiciona") == 0) {
            leitura_entradas >> vetor_nome >> valor;
            
            if (strcmp(vetor_nome, "V1") == 0) {
                if (n_elem_v1 < 100) {
                    // ARITMÉTICA DE PONTEIRO: *(base + deslocamento) = valor
                    *(v1 + n_elem_v1) = valor;
                    soma_v1 += valor;
                    n_elem_v1++;
                }
            } else if (strcmp(vetor_nome, "V2") == 0) {
                if (n_elem_v2 < 100) {
                    *(v2 + n_elem_v2) = valor;
                    soma_v2 += valor;
                    n_elem_v2++;
                }
            }
            escrita_saida << "O numero " << valor << " foi adicionado no vetor " << vetor_nome << "\n";
        }

        // --- Operação MOSTRA ---
        else if (strcmp(operador, "mostra") == 0) {
            leitura_entradas >> vetor_nome >> formato;
            escrita_saida << vetor_nome << "(" << formato << "): ";

            int *ptr_inicio = nullptr;
            int *ptr_fim = nullptr;
            int *p = nullptr;

            // Define qual vetor será percorrido
            if (strcmp(vetor_nome, "V1") == 0) {
                ptr_inicio = v1;
                ptr_fim = v1 + n_elem_v1; 
            } else if (strcmp(vetor_nome, "V2") == 0) {
                ptr_inicio = v2;
                ptr_fim = v2 + n_elem_v2;
            }

            // PERCURSO COM ARITMÉTICA DE PONTEIRO
            if (ptr_inicio != nullptr) {
                for (p = ptr_inicio; p < ptr_fim; p++) {
                    escrita_saida << *p;
                    // Verifica se não é o último elemento para adicionar a vírgula
                    if (p < ptr_fim - 1) {
                        escrita_saida << ", ";
                    }
                }
            }
            escrita_saida << "\n";
        }

        // --- Operação QTD ---
        else if (strcmp(operador, "qtd") == 0) {
            leitura_entradas >> vetor_nome;
            if (strcmp(vetor_nome, "V1") == 0) {
                escrita_saida << "Total de elementos no vetor V1: " << n_elem_v1 << "\n";
            } else if (strcmp(vetor_nome, "V2") == 0) {
                escrita_saida << "Total de elementos no vetor V2: " << n_elem_v2 << "\n";
            }
        }

        // --- Operação MEDIA ---
        else if (strcmp(operador, "media") == 0) {
            leitura_entradas >> vetor_nome;
            if (strcmp(vetor_nome, "V1") == 0) {
                escrita_saida << "Media dos elementos do vetor V1: ";
                if (n_elem_v1 > 0) {
                    escrita_saida << fixed << setprecision(1) << ((float)soma_v1 / n_elem_v1) << "\n";
                } else {
                    escrita_saida << "0.0\n";
                }
            } else if (strcmp(vetor_nome, "V2") == 0) {
                escrita_saida << "Media dos elementos do vetor V2: ";
                if (n_elem_v2 > 0) {
                    escrita_saida << fixed << setprecision(1) << ((float)soma_v2 / n_elem_v2) << "\n";
                } else {
                    escrita_saida << "0.0\n";
                }
            }
        }
    }

    // Fechamento de arquivos
    escrita_saida.close();
    leitura_entradas.close();

    // LIBERAÇÃO DE MEMÓRIA
    delete[] v1;
    delete[] v2;

    cout << "Codigo executado com sucesso. Verifique arquivo_saida_e60.txt.\n";

    return 0;
}