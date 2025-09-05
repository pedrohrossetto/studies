/*
    Autor: Pedro H.C Rossetto
    Data: 01/09/2025
    Descrição: Escreva um programa para controlar a venda de ingresso de um estádio de futebol
    Trabalho prático 4, Exercício 1, Algoritimos 2
*/



#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>


using namespace std; 

int main () {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    // Valores dos ingressos (removidos se não usados)
    // int valor_camarote = 350, valor_cadeira_central = 160, valor_cadeira_lateral = 125, valor_arquibancada = 98, cadeira_escolhida;

    char absolutePath[FILENAME_MAX];
    if (!_fullpath(absolutePath, __FILE__, FILENAME_MAX)) {
        cerr << "Erro ao obter o caminho absoluto do arquivo." << endl;
        return 1;
    }
    string path_file(absolutePath);
    size_t lastSlash = path_file.find_last_of("\\/");
    string file_name = path_file.substr(lastSlash + 1, path_file.find_last_of('.') - lastSlash - 1);
    path_file = path_file.substr(0, lastSlash + 1);

    string nome_arquivo = path_file + "futebol.txt";

    int opcao_menu_principal = 0;
    int opcao_setor = 0;
    int opcao_categoria = 0;
    
    char delimitador = ',';
    do {


            cout << "Menu:\n\n";
            cout << "1 - Comprar Ingresso\n";
            cout << "2 - Relatório de \n";
            cout << "3 - Relatório de \n";
            cout << "4 - Encerrar Partida. \n";
            cout << "0 - Encerrar o Programa.\n";
            cout << "Escolha uma opção: ";
            cin >> opcao_menu_principal;
            } while (opcao_menu_principal < 0 || opcao_menu_principal > 4);
        switch (opcao_menu_principal)
        {
        case 1: 
        {
            // abrir o arquivo
            ofstream comprar_ingresso(nome_arquivo, ios::app);
            if(!comprar_ingresso) {
                cout << "Arquivo nao foi aberto.\n";
                break;
            }

            // Escolha do setor

            cout << "Informe o setor que deseja comprar: \n";
            do {
                system("cls");
                cout << "1 - Arquibancada\n";
                cout << "2 - Cadeira Lateral\n";
                cout << "3 - Cadeira Central\n";
                cout << "4 - Camarote\n";
                cout << "Escolha uma opção: ";
                cin >> opcao_setor;
            } while (opcao_setor < 1 || opcao_setor > 4);

            comprar_ingresso << opcao_setor << delimitador;

            // Escolha da categoria
            cout << "Informe o tipo de categoria: \n";
            do {
                system("cls");
                cout << "1 - Torcedor comum (sem desconto)\n";
                cout << "2 - Idoso ou Estudante (50%)\n";
                cout << "3 - Sócio (50%)\n";
                cout << "4 - Proprietário (100%)\n";
                cout << "Escolha uma opção: ";
                cin >> opcao_categoria;
            } while (opcao_categoria < 1 || opcao_categoria > 4);

            comprar_ingresso << opcao_categoria << delimitador;

            // Quantidade de ingressos
            int ingressos_quantidade = 0;
            do {
                cout << "Informe a quantidade de ingressos: ";
                cin >> ingressos_quantidade;
            } while (ingressos_quantidade <= 0);
            comprar_ingresso << ingressos_quantidade << '\n';

            comprar_ingresso.close();
            break;
        }

        case 2:
            break;
        case 3:
            cout << "Relatório de total vendido por categoria\n";
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
}


/* 
leitura de cadeiras           
if (opcao_cadeira == 1) {
    cadeira_escolhida = valor_arquibancada;
} else if (opcao_cadeira == 2) {
    cadeira_escolhida = valor_cadeira_lateral;
} else if (opcao_cadeira == 3) {
    cadeira_escolhida = valor_cadeira_central;
} else if (opcao_cadeira == 4) {
    cadeira_escolhida = valor_camarote;
}
// leitura de desconto
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
*/

