#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

struct Contato {
    char nome[50];
    char telefone[20];
};

int main() {
    Contato agenda[100];
    int qtd = 0;
    int opcao;
    char nome[50], telefone[20];
    ifstream arqIn("agenda.txt");

    // Carrega contatos do arquivo
    if (arqIn.is_open()) {
        while (arqIn.getline(nome, 50, ';')) {
            arqIn.getline(telefone, 20);
            strcpy(agenda[qtd].nome, nome);
            strcpy(agenda[qtd].telefone, telefone);
            qtd++;
        }
        arqIn.close();
    }

    do {
        cout << "\n--- MENU ---\n";
        cout << "0 - Sair\n";
        cout << "1 - Cadastrar contato\n";
        cout << "2 - Mostrar contatos\n";
        cout << "3 - Consultar contato\n";
        cout << "4 - Excluir contato\n";
        cout << "Opcao: ";
        cin >> opcao;

        if (opcao == 1) {
            cin.ignore();
            cout << "Nome: ";
            cin.getline(nome, 50);
            cout << "Telefone: ";
            cin.getline(telefone, 20);

            bool repetido = false;
            for (int i = 0; i < qtd; i++) {
                if (strcmp(agenda[i].telefone, telefone) == 0)
                    repetido = true;
            }

            if (repetido)
                cout << "Telefone ja cadastrado!\n";
            else {
                strcpy(agenda[qtd].nome, nome);
                strcpy(agenda[qtd].telefone, telefone);
                qtd++;
                cout << "Contato adicionado!\n";
            }
        }

        else if (opcao == 2) {
            if (qtd == 0)
                cout << "Agenda vazia.\n";
            else {
                for (int i = 0; i < qtd; i++)
                    cout << "Nome: " << agenda[i].nome
                         << " | Telefone: " << agenda[i].telefone << endl;
            }
        }

        else if (opcao == 3) {
            cin.ignore();
            cout << "Digite o nome: ";
            cin.getline(nome, 50);
            bool achou = false;
            for (int i = 0; i < qtd; i++) {
                if (strcmp(agenda[i].nome, nome) == 0) {
                    cout << "Telefone: " << agenda[i].telefone << endl;
                    achou = true;
                }
            }
            if (!achou) cout << "Contato nao encontrado.\n";
        }

        else if (opcao == 4) {
            cin.ignore();
            cout << "Digite o telefone para excluir: ";
            cin.getline(telefone, 20);
            bool achou = false;
            for (int i = 0; i < qtd; i++) {
                if (strcmp(agenda[i].telefone, telefone) == 0) {
                    for (int j = i; j < qtd - 1; j++)
                        agenda[j] = agenda[j + 1];
                    qtd--;
                    achou = true;
                    cout << "Contato excluido!\n";
                    break;
                }
            }
            if (!achou) cout << "Contato nao encontrado.\n";
        }

    } while (opcao != 0);

    // Salva no arquivo
    ofstream arqOut("agenda.txt");
    for (int i = 0; i < qtd; i++)
        arqOut << agenda[i].nome << ";" << agenda[i].telefone << endl;
    arqOut.close();

    cout << "Agenda salva. Programa encerrado.\n";
    return 0;
}