#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "Portuguese");
    
    double resultado, n, d;

    cout << "Digite o numerador: ";
    cin >> n;

    cout << "Digite o divisor: ";
    cin >> d;

    // O alvo desta condição if é um bloco
    if (d != 0) {
        cout << "O divisor é diferente de zero, então dá para dividir" << endl;
        resultado = n / d;
        cout << n << " dividido por " << d << " é " << resultado << endl;
    }
    return 0;
}