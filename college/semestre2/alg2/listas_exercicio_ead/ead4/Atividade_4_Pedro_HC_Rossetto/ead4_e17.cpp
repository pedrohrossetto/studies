/*
    Autor: Pedro H.C Rossetto
    Data: 01/09/2025
    Descrição: Escreva um programa para controlar a venda de ingresso de um estádio de futebol
    Trabalho prático 4, Exercício 1, Algoritimos 2
*/

#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>


using namespace std; 

int main () {
    system("chcp 1252 > nul");
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    char arquivo_saida[11] = "saida.txt", arquivo_entrada[13] = "entrada.txt", vetor[5], operador[20];
    int valor;
    char formato;

    int TAMANHO_VET = 100;
    int v1[TAMANHO_VET], v2[TAMANHO_VET];

    int numero_elementos_v1 = 0, numero_elementos_v2 = 0;
    long long int soma_elementos_v1 = 0, soma_elementos_v2 = 0;

    ofstream escrita_saida(arquivo_saida);
        if (!escrita_saida)
            {
                cout << "Arquivo escrita nao foi aberto.\n";
                return 1;
            }
    ifstream leitura_entradas(arquivo_entrada);
        if (!leitura_entradas)
            {
                cout << "Arquivo leitura nao foi aberto.\n";
                escrita_saida.close();
                return 1;
            }
    
    while (leitura_entradas >> operador)
    {
        if (strcmp(operador, "adiciona") == 0)
        {
            leitura_entradas >> vetor >> valor;
            if (strcmp(vetor, "V1") == 0)
            {
                v1[numero_elementos_v1] = valor;
                soma_elementos_v1 += valor;
                numero_elementos_v1++;
            }
            if (strcmp(vetor, "V2") == 0)
            {
                v2[numero_elementos_v2] = valor;
                soma_elementos_v2 += valor;
                numero_elementos_v2++;
            }
            escrita_saida << "O numero " << valor << " foi adicionado no vetor " << vetor << "\n";
        }
    
        if (strcmp(operador, "mostra") == 0) 
        {
            leitura_entradas >> vetor >> formato;
            
            escrita_saida << vetor << "(" << formato << "): ";

            if (strcmp(vetor, "V1") == 0)
            {
                for (int i = 0; i < numero_elementos_v1; i++)
                {
                    escrita_saida << v1[i];
                    if (i < numero_elementos_v1 - 1) {
                        escrita_saida << ", ";
                    }
                }   
                escrita_saida << "\n";
            }
            if (strcmp(vetor, "V2") == 0)
            {
                for (int i = 0; i < numero_elementos_v2; i++)
                {
                    escrita_saida << v2[i];
                     if (i < numero_elementos_v2 - 1) {
                        escrita_saida << ", ";
                    }
                }   
                escrita_saida << "\n";
            }
        }

        if (strcmp(operador, "qtd") == 0)
        {
            leitura_entradas >> vetor;
            if (strcmp(vetor, "V1") == 0)
            {
                escrita_saida << "Total de elementos no vetor V1: "<<  numero_elementos_v1 << "\n";
            }
            if (strcmp(vetor, "V2") == 0)
            {
                escrita_saida << "Total de elementos no vetor V2: "<<  numero_elementos_v2 << "\n";
            }
        }

        if (strcmp(operador, "media") == 0)
        {
            leitura_entradas >> vetor;
            if (strcmp(vetor, "V1") == 0)
            {
                escrita_saida << "Media dos elementos do vetor V1: ";
                if (numero_elementos_v1 > 0) {
                    float media_v1 = (float)soma_elementos_v1 / numero_elementos_v1;
                    escrita_saida << fixed << setprecision(1) << media_v1 << "\n";
                } else {
                    escrita_saida << "0.0\n";
                }
            }
            if (strcmp(vetor, "V2") == 0)
            {
                escrita_saida << "Media dos elementos do vetor V2: ";
                if (numero_elementos_v2 > 0) {
                    float media_v2 = (float)soma_elementos_v2 / numero_elementos_v2;
                    escrita_saida << fixed << setprecision(1) << media_v2 << "\n";
                } else {
                    escrita_saida << "0.0\n";
                }
            }
        }
    }

    escrita_saida.close();
    leitura_entradas.close();
    cout << "Codigo executado com sucesso. \n\n\n";
    return 0;
}