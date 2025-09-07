/*
    Autor: Pedro H.C Rossetto
    Data: 01/09/2025
    Descrição: Escreva um programa para controlar a venda de ingresso de um estádio de futebol
    Trabalho prático 4, Exercício 1, Algoritimos 2
*/



#include <cstring>
#include <iostream>
#include <fstream>
#include <windows.h>


using namespace std; 

void zerarMatriz(int matriz[4][4]) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            matriz[i][j] = 0;
        }
    }
}

int main () {
    system("chcp 1252 > nul");
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    // Valores dos ingressos (removidos se não usados)
    // int valor_camarote = 350, valor_cadeira_central = 160, valor_cadeira_lateral = 125, valor_arquibancada = 98, cadeira_escolhida;

    /*
    Obter o caminho absoluto do arquivo atual, 
    estava tendo problemas com o output do arquivo indo para o diretório do compilador ao invés do diretório do projeto
    */
    char absolutePath[FILENAME_MAX];
    if (!_fullpath(absolutePath, __FILE__, FILENAME_MAX)) {
        cerr << "Erro ao obter o caminho absoluto do arquivo." << "\n";
        return 1;
    }
    string path_file(absolutePath);
    size_t lastSlash = path_file.find_last_of("\\/");
    string file_name = path_file.substr(lastSlash + 1, path_file.find_last_of('.') - lastSlash - 1);
    path_file = path_file.substr(0, lastSlash + 1);

    string nome_arquivo = path_file + "futebol.txt";

    int menu_opcao = 0, setor = 0, categoria = 0, ingressos_quantidade = 0;    
    char delimitador = ' ';

    int setor_precos[4] = {98, 125, 160, 350};
    float categoria_desconto[4] = {1.0, 0.5f, 0.5f, 0.0f};
    int ingressos_setor_categoria[4][4] = {0}; 

    do {
            cout << "Menu:\n\n";
            cout << "1 - Comprar Ingresso\n";
            cout << "2 - Relatório de Setor\n";
            cout << "3 - Relatório de Categoria\n";
            cout << "4 - Encerrar Partida. \n";
            cout << "0 - Encerrar o Programa.\n";
            cout << "Escolha uma opção: ";
            cin >> menu_opcao;
            
        switch (menu_opcao)
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
                cin >> setor;
            } while (setor < 1 || setor > 4);

            comprar_ingresso << setor << delimitador;
            

            // Escolha da categoria
            cout << "Informe o tipo de categoria: \n";
            do {
                system("cls");
                cout << "1 - Torcedor comum (sem desconto)\n";
                cout << "2 - Idoso ou Estudante (50%)\n";
                cout << "3 - Sócio (50%)\n";
                cout << "4 - Proprietário (100%)\n";
                cout << "Escolha uma opção: ";
                cin >> categoria;
            } while (categoria < 1 || categoria > 4);

            comprar_ingresso << categoria << delimitador;

            // Quantidade de ingressos
            do {
                cout << "Informe a quantidade de ingressos: ";
                cin >> ingressos_quantidade;
            } while (ingressos_quantidade <= 0);

            comprar_ingresso << ingressos_quantidade << '\n';
            comprar_ingresso.close();

            system("pause");
            system("cls");    
            break;
        }

        case 2:
            {
            // Zera as estruturas de dados para evitar contagem em dobro
            double faturamento_setor[4] = {0.0}, faturamento_total_geral = 0;
            zerarMatriz(ingressos_setor_categoria);
            system("cls");
            ifstream relatorio_setor(nome_arquivo, ios::in);
            if(!relatorio_setor) {
                cout << "Arquivo nao foi aberto.\n";
                break;
            }   

            while( relatorio_setor >> setor >> categoria >> ingressos_quantidade){
                if ((setor >= 1 && setor <= 4) && (categoria >= 1 && categoria <= 4))
                {
                    ingressos_setor_categoria[setor - 1][categoria - 1] += ingressos_quantidade;
                }
            }
            relatorio_setor.close();
            for (int s = 0; s < 4; s++)
            {
                for (int c = 0; c < 4; c++)
                {
                    faturamento_setor[s] += ingressos_setor_categoria[s][c] * categoria_desconto[c] * setor_precos[s];
                }
            }

            
            for (int s = 0; s < 4; s++)
            {
                faturamento_total_geral += faturamento_setor[s];
            }


            cout << "Faturamento total: R$ " << faturamento_total_geral<< "\n";
            cout << "------------------------------------------------\n";
            cout << "Faturamento do setor da arquibancada: R$ " << faturamento_setor[0] << "\n";
            cout << "Faturamento do setor da cadeira lateral: R$ " << faturamento_setor[1]<< "\n";
            cout << "Faturamento do setor da cadeira central: R$ " << faturamento_setor[2]<< "\n";
            cout << "Faturamento do setor do camarote: R$ " << faturamento_setor[3]<< "\n";

            cout << "\nPressione qualquer tecla para voltar ao menu...";

            system("pause");
            system("cls");

            break;
            }
        case 3:{
            // Zera as estruturas de dados para evitar contagem em dobro
            double faturamento_categoria[4] = {0.0}, faturamento_total_geral = 0;
            zerarMatriz(ingressos_setor_categoria);            
            system("cls");
            cout << "--- Relatório de Faturamento por Categoria ---\n";
            ifstream relatorio_categoria(nome_arquivo);
            if (!relatorio_categoria) {
                cout << "Arquivo de vendas nao encontrado ou vazio.\n";
                break;
            }
            



            // Lê o arquivo e preenche a matriz
            while (relatorio_categoria >> setor >> categoria >> ingressos_quantidade) {
                if ((setor >= 1 && setor <= 4) && (categoria >= 1 && categoria <= 4)) {
                    ingressos_setor_categoria[setor - 1][categoria - 1] += ingressos_quantidade;
                }
            }
            relatorio_categoria.close();

            // Calcula o faturamento, iterando por cada categoria e setor
            for (int c = 0; c < 4; c++) {
                for (int s = 0; s < 4; s++) {
                    faturamento_categoria[c] += ingressos_setor_categoria[s][c] * categoria_desconto[c] * setor_precos[s];
                }
            }

            for (int s = 0; s < 4; s++)
            {
                faturamento_total_geral += faturamento_categoria[s];
            }
            
            // Exibe os resultados
            cout.precision(2);
            cout << fixed;

            cout << "Faturamento total: R$ " << faturamento_total_geral<< "\n";
            cout << "------------------------------------------------\n";
            cout << "Torcedor comum: R$ " << faturamento_categoria[0] << "\n";
            cout << "Idoso ou Estudante: R$ " << faturamento_categoria[1] << "\n";
            cout << "Sócio: R$ " << faturamento_categoria[2] << "\n";
            cout << "Proprietário: R$ " << faturamento_categoria[3] << "\n";

            system("pause");
            system("cls");            
            break;
        }

        case 4:{
        // Apaga o conteúdo do arquivo para "encerrar a partida"
            ofstream encerrar_partida(nome_arquivo, ios::trunc);
            encerrar_partida.close();
            cout << "Partida encerrada. O arquivo de venda de ingressos foi limpo.\n";
            system("pause");
            system("cls");            
            break;
        }
        case 0:
            cout << "Encerrando o programa...\n";
            break;
        default:
            cout << "Opção inválida! Tente novamente.\n";
            system("pause");
            system("cls");
            break;
            }
}
 while (menu_opcao != 0);
 return 0;
}
