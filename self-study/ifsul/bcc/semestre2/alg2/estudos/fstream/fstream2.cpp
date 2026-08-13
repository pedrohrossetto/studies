#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    // Define a standard path for the file
    const string filePath = R"(C:\Users\20251pf.cc0009\Documents\fstreamexample2.txt)";

    // Writing to a file using ofstream
    ofstream escreve(filePath);
    if (escreve.is_open()) {
        escreve << "1;2;3;4;5;6;7;8;9";
        escreve.close();
    } else {
        cerr << "Unable to open file for writing.\n";
    }

    int lista[10], indice_lista;
    string line;
    // Reading from a file using ifstream
    ifstream leitura(filePath);
    if (leitura.is_open()) {
        indice_lista = 0;
        while (getline(leitura, line, ';')) {
            lista[indice_lista] = stoi(line);
            indice_lista++;
        }
        leitura.close();
    } else {
        cerr << "Unable to open file for reading.\n";
    }

    // Print the list
    for (int i = 0; i < indice_lista; i++) {
        cout << lista[i] << " ";
    }

}