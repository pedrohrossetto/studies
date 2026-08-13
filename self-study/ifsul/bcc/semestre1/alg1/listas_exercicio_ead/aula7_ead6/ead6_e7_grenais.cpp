/*
 * Programa para Estatística de GRENAIS
 *
 * A Federação Gaúcha de Futebol contratou você para escrever um programa que faça
 * uma estatística dos resultados de vários GRENAIS. O programa deve realizar as
 * seguintes operações:
 *
 * 1. Ler o número de gols marcados pelo Inter e pelo Grêmio em um GRENAL.
 * 2. Após cada partida, exibir a mensagem "Novo grenal (S-sim N-nao)" e solicitar
 *    uma resposta do usuário.
 * 3. Se a resposta for 'S', o programa deve ser executado novamente solicitando
 *    o número de gols marcados pelos times em uma nova partida.
 * 4. Caso contrário, o programa deve ser encerrado e exibir as seguintes estatísticas:
 *
 *    - Quantos GRENAIS fizeram parte da estatística.
 *    - O percentual de vitórias do Grêmio em relação ao total.
 *    - O número de vitórias do Inter.
 *    - O número de vitórias do Grêmio.
 *    - O número de Empates.
 *    - A média de gols por partida.
 *    - Uma mensagem indicando qual o time venceu o maior número de GRENAIS
 *      (ou "Não houve vencedor", caso termine empatado).
 */
// Autor: Pedro H.C Rossetto
// Data: 21/04/2025
// Descrição: // Menu de registro de grenais
// Lista de Exercícios, Exercício 6, EAD6

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    int gols_total = 0, gols_partida = 0, vitorias_inter = 0, vitorias_gremio = 0, empates = 0, num_partidas = 0;
    float media_gols = 0, media_gremio = 0, media_inter = 0;
    char option_menu, option_partida;

    do
    {
        cout << "Novo Grenal:\n"
             << "N - Não\n"
             << "S - Sim\n";

        cin >> option_menu;
        if (option_menu == 'N')
        {
            break;
        }
        if (option_menu == 'S')
        {
            num_partidas++;
            cout << "Quem venceu o grenal número \"" << num_partidas << "\"?"
                 << endl
                 << "G - Grêmio\nI - Internacional\nE - Empate\n";
            cin >> option_partida;

            cout << "Quantos gols ocorreram na partida? ";
            cin >> gols_partida;
            // validação de erro
            while (cin.fail() || gols_partida < 0)
            {
                cin.clear();            // limpa
                cin.ignore(1000, '\n'); // descarta
                cout << "Entrada inválida. Insira um número inteiro não negativo: ";
                cin >> gols_partida;
            }
            gols_total += gols_partida;

            switch (option_partida)
            {
            case 'G':
                vitorias_gremio++;
                break;
            case 'I':
                vitorias_inter++;
                break;
            case 'E':
                empates++;
                break;
            default:
                cout << "Opção inválida. Por favor, insira 'G', 'I' ou 'E'." << endl;
                break;
            }
        }
        else
        {
            cout << "Opção inválida. Por favor, insira 'S' ou 'N'." << endl;
        }
    } while (true); // perpétuo, n enceerra em condição no início
    // Exibe as estatísticas finais
    cout << "\nEstatísticas dos Grenais:\n";
    cout << "Total de Grenais: " << num_partidas << endl;
    cout << "Vitórias do Inter: " << vitorias_inter << endl;
    cout << "Vitórias do Grêmio: " << vitorias_gremio << endl;
    cout << "Empates: " << empates << endl;

    // Calcula e exibe o percentual de vitórias do Grêmio
    std::cout << std::fixed << std::setprecision(2);
    if (num_partidas > 0)
    {
        media_gremio = (static_cast<float>(vitorias_gremio) / num_partidas) * 100; // static_cast<float> pesquisado
        cout << "Percentual de vitórias do Grêmio: " << media_gremio << "%" << endl;

        media_inter = (static_cast<float>(vitorias_inter) / num_partidas) * 100; // static_cast<float> pesquisado
        cout << "Percentual de vitórias do Inter: " << media_inter << "%" << endl;

        // Calcula e exibe a média de gols por partida
        media_gols = static_cast<float>(gols_total) / num_partidas;
        cout << "Média de gols por partida: " << media_gols << endl;

        // Determina e exibe o vencedor geral
        if (vitorias_inter > vitorias_gremio)
        {
            cout << "O Inter venceu mais Grenais." << endl;
        }
        else if (vitorias_gremio > vitorias_inter)
        {
            cout << "O Grêmio venceu mais Grenais." << endl;
        }
        else
        {
            cout << "Não houve vencedor geral." << endl;
        }
    }
    else
    {
        cout << "Nenhum Grenal foi registrado." << endl;
    }

    return 0;
}