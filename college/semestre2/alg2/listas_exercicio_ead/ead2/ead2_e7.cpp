#include <iostream>
#include <cstring>
#include <clocale>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(1252);

    const int TAMANHO_MAXIMO = 500;
    char texto_original[TAMANHO_MAXIMO];
    char texto_filtrado[TAMANHO_MAXIMO];

    cout << "Verificador de Palindromos" << endl;
    cout << "Digite uma palavra ou frase: ";
    cin.getline(texto_original, TAMANHO_MAXIMO);

    int j = 0;
    for (int i = 0; i < strlen(texto_original); i++) {
        char caractere_atual = texto_original[i];
        
        if (caractere_atual >= 'A' && caractere_atual <= 'Z') {
            caractere_atual = caractere_atual + 32;
        }

        if (caractere_atual == 'á' || caractere_atual == 'à' || caractere_atual == 'â' || caractere_atual == 'ã') {
            caractere_atual = 'a';
        } else if (caractere_atual == 'é' || caractere_atual == 'è' || caractere_atual == 'ê') {
            caractere_atual = 'e';
        } else if (caractere_atual == 'í' || caractere_atual == 'ì' || caractere_atual == 'î') {
            caractere_atual = 'i';
        } else if (caractere_atual == 'ó' || caractere_atual == 'ò' || caractere_atual == 'ô' || caractere_atual == 'õ') {
            caractere_atual = 'o';
        } else if (caractere_atual == 'ú' || caractere_atual == 'ù' || caractere_atual == 'û') {
            caractere_atual = 'u';
        } else if (caractere_atual == 'ç') {
            caractere_atual = 'c';
        }
        
        if ((caractere_atual >= 'a' && caractere_atual <= 'z') || (caractere_atual >= '0' && caractere_atual <= '9')) {
            texto_filtrado[j] = caractere_atual;
            j++;
        }
    }
    texto_filtrado[j] = '\0';

    bool eh_palindromo = true;
    int tamanho_filtrado = strlen(texto_filtrado);

    for (int i = 0; i < tamanho_filtrado / 2; i++) {
        if (texto_filtrado[i] != texto_filtrado[tamanho_filtrado - 1 - i]) {
            eh_palindromo = false;
            break;
        }
    }

    cout << "Texto original: \"" << texto_original << "\"" << endl;
    cout << "Texto considerado para analise: \"" << texto_filtrado << "\"" << endl;

    if (eh_palindromo && tamanho_filtrado > 0) {
        cout << "\nResultado: E um palindromo!" << endl;
    } else {
        cout << "\nResultado: NAO e um palindromo." << endl;
    }

    return 0;
}