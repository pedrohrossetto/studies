#include <iostream>
#include <cstring> // Para funções como strlen, strcpy
using namespace std;

int main() {
    char nome1[] = "Vitor";          // Inicialização direta
    const char* nome2 = "Copilot";   // Ponteiro para string literal

    cout << "Nome 1: " << nome1 << endl;
    cout << "Nome 2: " << nome2 << endl;

    // Operações comuns
    cout << "Tamanho de nome1: " << strlen(nome1) << endl;

    char copia[10];
    strcpy(copia, nome1); // Copia conteúdo de nome1 para copia
    cout << "Cópia de nome1: " << copia << endl;

    return 0;
}