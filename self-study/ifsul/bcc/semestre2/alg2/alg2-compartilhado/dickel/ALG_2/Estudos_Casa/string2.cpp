#include <iostream>
#include <string> // Biblioteca para std::string
using namespace std;

int main() {
    string nome = "Vitor";
    string sobrenome = "Dickel";

    // Concatenar
    string completo = nome + " " + sobrenome;
    cout << "Nome completo: " << completo << endl;

    // Tamanho
    cout << "Tamanho: " << completo.size() << endl;

    // Verificar se está vazio
    if (completo.empty()) {
        cout << "String está vazia." << endl;
    } else {
        cout << "String contém texto." << endl;
    }

    // Substituir parte da string
    completo.replace(6, 5, "Copilot"); // Substitui "Silva" por "Copilot"
    cout << "Nome modificado: " << completo << endl;

    // Iterar sobre os caracteres
    cout << "Caracteres: ";
    for (char c : completo) {
        cout << c << ' ';
    }
    cout << endl;

    return 0;
}