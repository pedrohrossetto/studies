#include <iostream>
#include <cctype>
using namespace std;

int main() {
char resposta;
do {
    cout << "Deseja continuar? (S/N): ";
    cin >> resposta;
    resposta = toupper(resposta);
} while (resposta != 'N');
}