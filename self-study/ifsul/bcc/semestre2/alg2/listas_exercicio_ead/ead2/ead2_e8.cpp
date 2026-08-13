#include <iostream>
#include <cstring>

using namespace std;


// ordena em ordem alfabética.
void ordenarPalavra(char palavra[]) {
    int tamanho = strlen(palavra);
    bool trocado; 
    for (int i = 0; i < tamanho - 1; i++) {
        trocado = false;
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (palavra[j] > palavra[j + 1]) {
                // Troca os caracteres de lugar
                char temp = palavra[j];
                palavra[j] = palavra[j + 1];
                palavra[j + 1] = temp;
                trocado = true;
            }
        }
        if (trocado == false) {
            break;
        }
    }
}


int main() {
    const int TAMANHO_MAXIMO = 100;
    char palavraA[TAMANHO_MAXIMO];
    char palavraB[TAMANHO_MAXIMO];

    cout << "Verificador de Anagramas" << endl;
    cout << "Digite a primeira palavra: ";
    cin >> palavraA; // cin' pois são palavras únicas sem espaços

    cout << "Digite a segunda palavra: ";
    cin >> palavraB;

    // VERIFICA SE AS PALAVRAS TÊM O MESMO TAMANHO
    if (strlen(palavraA) != strlen(palavraB)) {
        cout << "\nResultado: NAO" << endl;
        return 0; // Encerra o programa se nao tiver o mesmo tamanho
    }

    // ORDENA AS DUAS PALAVRAS
    ordenarPalavra(palavraA);
    ordenarPalavra(palavraB);

    // COMPARA AS PALAVRAS JÁ ORDENADAS
    if (strcmp(palavraA, palavraB) == 0) {
        cout << "\nResultado: SIM" << endl;
    } else {
        cout << "\nResultado: NAO" << endl;
    }

    return 0;
}