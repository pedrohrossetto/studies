#include <iostream>
#include <cstdio>

using namespace std;

struct C {
    int num;
    char n[50];
    float s = 0.0;
    int c = 0; 
};

int main() {
    C conta; 
    int op = -1;

    do {
        cout << "\n--- BANCO ---\n1-Cadastrar\n2-Visualizar\n3-Depositar\n4-Sacar\n5-Sair\nO: ";
        cin >> op;

        if (op == 1) {
            cout << "\nCADASTRAR:\nNum: ";
            cin >> conta.num;
            
            cout << "Nome: ";
            cin.ignore(); 
            cin.getline(conta.n, 50);

            cout << "Saldo: ";
            cin >> conta.s;
            
            conta.c = 1;
            cout << "\nConta " << conta.num << " OK.\n";
        }
        else if (op >= 2 && op <= 4) {
            if (conta.c == 0) {
                cout << "\nERRO: Nenhuma conta.\n";
                continue;
            }

            int busca;
            cout << "Num da conta: ";
            cin >> busca;

            if (busca != conta.num) {
                cout << "\nERRO: Conta nao existe.\n";
                continue;
            }

            if (op == 2) {
                cout << "\nDADOS:\nConta: " << conta.num << "\n";
                cout << "Cliente: " << conta.n << "\n";
                cout << "Saldo: R$" << conta.s << "\n";
            }
            else if (op == 3) {
                float v;
                cout << "Valor D: ";
                cin >> v;

                if (v > 0) {
                    conta.s += v;
                    cout << "\nNovo S: R$" << conta.s << "\n";
                } else {
                    cout << "\nERRO: Valor invalido.\n";
                }
            }
            else if (op == 4) {
                float v;
                cout << "Valor S: ";
                cin >> v;

                if (v <= 0) {
                    cout << "\nERRO: Valor invalido.\n";
                }
                else if (v > conta.s) {
                    cout << "\nERRO: Saldo insuficiente. S: R$" << conta.s << "\n";
                }
                else {
                    conta.s -= v;
                    cout << "\nSaque OK. Novo S: R$" << conta.s << "\n";
                }
            }
        }
        else if (op != 5) {
            cout << "\nOp Invalida.\n";
        }

    } while (op != 5);

    cout << "\nFim.\n";
    return 0;
}