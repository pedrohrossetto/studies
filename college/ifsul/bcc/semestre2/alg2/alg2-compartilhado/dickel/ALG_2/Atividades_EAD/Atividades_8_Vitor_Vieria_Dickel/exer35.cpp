#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

struct A {
    char n[50];
    char d[50];
    float n1, n2, n3;
    int s = 0; 
};

int main() {
    A aluno;
    int op = -1;

    do {
        cout << "\n---M---\n0-S\n1-C\n2-M\n3-Media\nO: ";
        cin >> op;

        if (op == 1) {
            cout << "\nC:\nNome: ";
            cin.ignore(); 
            cin.getline(aluno.n, 50);

            cout << "Disc: ";
            cin.getline(aluno.d, 50);

            cout << "N1(2): ";
            cin >> aluno.n1;

            cout << "N2(3): ";
            cin >> aluno.n2;

            cout << "N3(5): ";
            cin >> aluno.n3;
            
            aluno.s = 1;
            cout << "\nCadastrado!\n";
        }
        else if (op == 2) {
            if (aluno.s == 0) {
                cout << "\nNao ha aluno.\n";
                continue;
            }
            cout << "\nD:\nNome: " << aluno.n << "\n";
            cout << "Disc: " << aluno.d << "\n";
            cout << "N1: " << aluno.n1 << "\n";
            cout << "N2: " << aluno.n2 << "\n";
            cout << "N3: " << aluno.n3 << "\n";
        }
        else if (op == 3) {
            if (aluno.s == 0) {
                cout << "\nCadastre primeiro.\n";
                continue;
            }

            float m = ((aluno.n1 * 2) + (aluno.n2 * 3) + (aluno.n3 * 5)) / 10;
            
            cout << "\nMedia: " << m << "\n";
            if (m >= 7) {
                cout << "Aprovado!\n";
            } else {
                cout << "Reprovado.\n";
            }
        }
        else if (op != 0) {
            cout << "\nOp Invalida.\n";
        }

    } while (op != 0);

    cout << "\nFim.\n";
    return 0;
}