#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

struct A {
    char nome[50];
    char email[50];
    char nasc[11];
    float notas[5];
    int s = 0;
};

int main() {
    A aluno;
    int op = -1;

    do {
        cout << "\n--- Aluno ---\n0-Sair\n1-Cadastrar\n2-Mostrar\n3-Media\nO: ";
        cin >> op;

        if (op == 1) { // Cadastrar
            cout << "\nCADASTRO:\nNome: ";
            cin.ignore(); 
            cin.getline(aluno.nome, 50);

            cout << "Email: ";
            cin.getline(aluno.email, 50);

            cout << "Data Nasc (dd/mm/aaaa): ";
            cin.getline(aluno.nasc, 11);
            
            cout << "Notas (5):\n";
            for (int i = 0; i < 5; i++) {
                cout << "Nota " << i + 1 << ": ";
                cin >> aluno.notas[i];
            }
            aluno.s = 1;
            cout << "\nAluno cadastrado!\n";
        }
        else if (op == 2) {
            if (aluno.s == 0) {
                cout << "\nNao ha aluno.\n";
                continue;
            }
            cout << "\nDADOS:\nNome: " << aluno.nome << "\n";
            cout << "Email: " << aluno.email << "\n";
            cout << "Nasc: " << aluno.nasc << "\n";
            cout << "Notas: ";
            for (int i = 0; i < 5; i++) {
                cout << aluno.notas[i] << (i < 4 ? ", " : "");
            }
            cout << "\n";
        }
        else if (op == 3) {
            if (aluno.s == 0) {
                cout << "\nCadastre primeiro.\n";
                continue;
            }
            
            float soma = 0;
            for (int i = 0; i < 5; i++) {
                soma += aluno.notas[i];
            }
            float media = soma / 5.0;
            
            cout << "\nMEDIA:\nNome: " << aluno.nome << "\n";
            cout << "Media Aritmetica: " << media << "\n";
        }
        else if (op != 0) {
            cout << "\nOp Invalida.\n";
        }
    } while (op != 0);

    cout << "\nFim.\n";
    return 0;
}