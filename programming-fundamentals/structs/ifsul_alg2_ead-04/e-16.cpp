/*
    Autor: Pedro H.C Rossetto
    Data: 01/09/2025
    Descrição: Escreva um programa para controlar a venda de ingresso de um estádio de futebol
    Trabalho prático 4, Exercício 1, Algoritimos 2
*/



#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main () {

    int valor_camarote = 350, valor_cadeira_central = 160, valor_cadeira_lateral = 125, valor_arquibancada = 98,
    desconto_proprietario = 0, desconto_idosos_e_estudantes = 0.5, desconto_socios = 0.5, desconto_torcedores = 1;

    string nome_arquivo = "futebol.txt";

    do {
    
    cout << "Menu:\n\n";
    cout << "1 - Comprar Ingresso\n";
    cout << "2 - Relatório de \n";
    cout << "3 - Relatório de \n";
    cout << "4 - Encerrar Partida. \n";
    cout << "0 - Encerrar o Programa.\n";

    } while (cin != 0)

}