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

    int 
    valor_camarote = 350, valor_cadeira_central = 160, valor_cadeira_lateral = 125, valor_arquibancada = 98, cadeira_escolhida;
    string nome_arquivo = "futebol.txt";

    int opcao_menu_principal, opcao_cadeira, opcao_desconto;

    do {

        cout << "Menu:\n\n";
        cout << "1 - Comprar Ingresso\n";
        cout << "2 - Relatório de \n";
        cout << "3 - Relatório de \n";
        cout << "4 - Encerrar Partida. \n";
        cout << "0 - Encerrar o Programa.\n";
        cout << "Escolha uma opção: ";
        cin >> opcao_menu_principal;

        switch (opcao_menu_principal)
        {
        case 1: {
            // Escolha da cadeira
            cout << "Informe a cadeira que deseja comprar: \n";
            do {
                cout << "1 - Arquibancada\n";
                cout << "2 - Cadeira Lateral\n";
                cout << "3 - Cadeira Central\n";
                cout << "4 - Camarote\n";
                cout << "0 - Encerrar o Programa.\n";
                cout << "Escolha uma opção: ";
                cin >> opcao_cadeira;
            } while (opcao_cadeira < 1 || opcao_cadeira > 4);

            if (opcao_cadeira == 1) {
                cadeira_escolhida = valor_arquibancada;
            } else if (opcao_cadeira == 2) {
                cadeira_escolhida = valor_cadeira_lateral;
            } else if (opcao_cadeira == 3) {
                cadeira_escolhida = valor_cadeira_central;
            } else if (opcao_cadeira == 4) {
                cadeira_escolhida = valor_camarote;
            }

            // Escolha do desconto
            cout << "Informe o tipo de desconto: \n";
            do {
                cout << "1 - Torcedor comum (sem desconto)\n";
                cout << "2 - Idoso ou Estudante (50%)\n";
                cout << "3 - Sócio (50%)\n";
                cout << "4 - Proprietário (100%)\n";
                cout << "Escolha uma opção: ";
                cin >> opcao_desconto;
            } while (opcao_desconto < 1 || opcao_desconto > 4);

            double desconto = 1.0;
            if (opcao_desconto == 1) {
                desconto = 1.0;
                
            } 
            else if (opcao_desconto == 2 || opcao_desconto == 3) {
                desconto = 0.5;
            }
            else if (opcao_desconto == 4) {
                desconto = 0;
            }

            // Quantidade de ingressos
            int quantidade = 0;
            do {
                cout << "Informe a quantidade de ingressos: ";
                cin >> quantidade;
            } while (quantidade <= 0);

            double valor_total = cadeira_escolhida * desconto * quantidade;
            cout << "Valor total da compra: R$ " << valor_total << endl;
            break;
        }

        case 2:
            // Relatório de (implementar)
            cout << "Relatório de (em desenvolvimento)\n";
            break;
        case 3:
            // Relatório de (implementar)
            cout << "Relatório de (em desenvolvimento)\n";
            break;
        case 4:
            // Encerrar Partida (implementar)
            cout << "Encerrando partida...\n";
            break;
        case 0:
            cout << "Encerrando o programa...\n";
            break;
        default:
            cout << "Opção inválida!\n";
            break;
        }

    } while (opcao_menu_principal != 0);

}