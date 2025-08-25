#include <iostream>

using namespace std;

int main() {
    char frase[201];
    bool letras_encontradas[26] = {false};

    cout << "Forneça uma frase para verificar se é um pangrama: " << endl;
    cin.getline(frase, 201);

    for (int i = 0; frase[i] != '\0'; i++) {
        if (frase[i] >= 'a' && frase[i] <= 'z') {
            letras_encontradas[frase[i] - 'a'] = true;
        }
    }

    const char* alfabeto = "abcdefghijlmnopqrstuvxz";

    for (int i = 0; alfabeto[i] != '\0'; i++) {
        if (!letras_encontradas[alfabeto[i] - 'a']) {
            cout << "Não é um pangrama" << endl;
            return 0;
        }
    }

    cout << "É um pangrama" << endl;

    return 0;
}