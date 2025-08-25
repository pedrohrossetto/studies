#include <iostream>
#include <cstring>

using namespace std;

int main() {
    const int TAMANHO_MAXIMO = 256;
    char email[TAMANHO_MAXIMO];
    bool email_valido = false; 

    cout << "Validador de E-mail" << endl;
    cout << "Digite um e-mail: ";
    cin >> email;

    int posicao_arroba = -1;
    int contador_arroba = 0;
    int tamanho_total = strlen(email);

    for (int i = 0; i < tamanho_total; i++) {
        if (email[i] == '@') {
            contador_arroba++;
            posicao_arroba = i;
        }
    }

    
    if (contador_arroba == 1) {
        if (posicao_arroba > 0) {
            char* dominio = &email[posicao_arroba + 1];
            if (strcmp(dominio, "gmail.com") == 0 || strcmp(dominio, "google.com") == 0) {
                // Se todas as regras passaram, o e-mail é válido.
                email_valido = true;
            }
        }
    }
    
    if (email_valido) {
        cout << email << "\" é um e-mail do Google válido" << endl;
    } else {
        cout << email << "\" é inválido." << endl;
    }

    return 0;
}