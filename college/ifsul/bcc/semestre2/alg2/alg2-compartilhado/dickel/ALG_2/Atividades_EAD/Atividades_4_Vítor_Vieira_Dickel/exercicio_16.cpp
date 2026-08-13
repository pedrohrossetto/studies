#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main() {
    system("chcp 1252 > nul");

    int menu, categoria, setor;
    double valor, base;
    int existeVenda = 0;

    do {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1 - Comprar ingresso\n";
        cout << "2 - Total de ingressos vendidos\n";
        cout << "3 - Total de torcedores\n";
        cout << "4 - Encerrar partida\n";
        cout << "Escolha: ";
        cin >> menu;

        if (menu == 1) {
            cout << "\nInforme categoria (1-4): ";
            cin >> categoria;

            if (categoria < 1 || categoria > 4) {
                cout << "Categoria inválida!\n";
            } else {
                cout << "Informe setor (1-4): ";
                cin >> setor;

                if (setor < 1 || setor > 4) {
                    cout << "Setor inválido!\n";
                } else {
                    // preço base do setor
                    if (setor == 1) base = 350;
                    else if (setor == 2) base = 160;
                    else if (setor == 3) base = 125;
                    else base = 98;

                    // desconto pela categoria
                    if (categoria == 1) valor = 0;
                    else if (categoria == 2) valor = base * 0.5;
                    else if (categoria == 3) valor = base * 0.5;
                    else valor = base;

                    cout << fixed << setprecision(2);
                    cout << "Valor do ingresso: R$ " << valor << "\n";

                    // salva no arquivo
                    ofstream arq("Futebol.txt", ios::app);
                    arq << categoria << " " << setor << " " << valor << "\n";
                    arq.close();

                    existeVenda = 1;
                    cout << "Venda registrada com sucesso!\n";
                }
            }
        }

        else if (menu == 2) {
            ifstream arq("Futebol.txt");
            int c, s, total = 0;
            double v;
            if (!arq) {
                cout << "Nenhum ingresso vendido ainda.\n";
            } else {
                while (arq >> c >> s >> v) {
                    total++;
                }
                cout << "Total de ingressos vendidos: " << total << "\n";
                arq.close();
            }
        }

        else if (menu == 3) {
            ifstream arq("Futebol.txt");
            int c, s, cat1 = 0, cat2 = 0, cat3 = 0, cat4 = 0;
            double v;
            if (!arq) {
                cout << "Nenhum torcedor registrado.\n";
            } else {
                while (arq >> c >> s >> v) {
                    if (c == 1) cat1++;
                    else if (c == 2) cat2++;
                    else if (c == 3) cat3++;
                    else if (c == 4) cat4++;
                }
                cout << "\n--- TOTAL DE TORCEDORES ---\n";
                cout << "Categoria 1: " << cat1 << "\n";
                cout << "Categoria 2: " << cat2 << "\n";
                cout << "Categoria 3: " << cat3 << "\n";
                cout << "Categoria 4: " << cat4 << "\n";
                arq.close();
            }
        }

        else if (menu == 4) {
            cout << "Encerrando partida...\n";
        }

        else {
            cout << "Opção inválida!\n";
        }

    } while (menu != 4);

    return 0;
}