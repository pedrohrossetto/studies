#include <iostream>
#include <string>

using namespace std;

int main() {
    
    string texto;
    int vogais = 0;
    int consoantes = 0;
    int numeros = 0;
    int espacos = 0;

    cout << "Digite um texto qualquer: ";
    getline(cin, texto);

    string texto_minusculo = texto;
    for (char &c : texto_minusculo) {
        if (c >= 'A' && c <= 'Z') {
            c += 32;
        }
    }

    for (char c : texto_minusculo) {
        if (c >= 'a' && c <= 'z') {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vogais++;
            } else {
                consoantes++;
            }
        } else if (c >= '0' && c <= '9') {
            numeros++;
        } else if (c == ' ') {
            espacos++;
        }
    }

    string texto_maiusculo = texto;
    for (char &c : texto_maiusculo) {
        if (c >= 'a' && c <= 'z') {
            c -= 32;
        }
    }
    cout << "\n Resultados \n";
    cout << "Texto em maiusculo: " << texto_maiusculo <<endl;
    cout << "Texto em minusculo: " << texto_minusculo <<endl;
    cout << "Total de caracteres: " << texto.length() <<endl;
    cout << "Total de vogais: " << vogais <<endl;
    cout << "Total de consoantes: " << consoantes <<endl;
    cout << "Total de numeros: " << numeros <<endl;
    cout << "Total de espacos em branco: " << espacos <<endl;

    return 0;
}