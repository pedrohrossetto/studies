#include <iostream>
using namespace std;

int main() {
    int opcao;

    cout << "=== Menu de Operações ===" << endl;
    cout << "1. Somar dois números" << endl;
    cout << "2. Subtrair dois números" << endl;
    cout << "3. Multiplicar dois números" << endl;
    cout << "4. Sair" << endl;
    cout << "Escolha uma opção: ";
    cin >> opcao;

    int a, b;

    switch (opcao) {
        case 1:
            cout << "Digite dois números para somar: ";
            cin >> a >> b;
            cout << "Resultado: " << a + b << endl;
            break;

        case 2:
            cout << "Digite dois números para subtrair: ";
            cin >> a >> b;
            cout << "Resultado: " << a - b << endl;
            break;

        case 3:
            cout << "Digite dois números para multiplicar: ";
            cin >> a >> b;
            cout << "Resultado: " << a * b << endl;
            break;

        case 4:
            cout << "Saindo do programa..." << endl;
            break;

        default:
            cout << "Opção inválida. Tente novamente." << endl;
    }

    return 0;
}