#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    // Define a standard path for the file
    const string filePath = R"(C:\Users\20251pf.cc0009\Documents\fstreamexample.txt)";

    // Writing to a file using ofstream
    ofstream escreve(filePath);
    if (escreve.is_open()) {
        escreve << "This is a line written to the file.\n";
        escreve << "Another line written to the file.\n";
        escreve.close();
    } else {
        cerr << "Unable to open file for writing.\n";
    }
    int contador_letra = 0;
    char letra_contar;
    cout << "Escolha a letra (char) para contar: " << endl;
    cin >> letra_contar;
    char a;
    // Reading from a file using ifstream
    ifstream leitura(filePath);
    if (leitura.is_open()) {
        while (leitura.get(a)) {
            a = toupper(a);
            letra_contar = toupper(letra_contar);
            if ( a == letra_contar){
                contador_letra++;
            }
            cout << a;
        }
        leitura.close();
    } else {
        cerr << "Unable to open file for reading.\n";
    }
    cout << "Contador de Letra '"<<letra_contar<< "': " << contador_letra << endl;

    // Using fstream for both reading and writing
    fstream file(filePath, ios::in | ios::out | ios::app);
    if (file.is_open()) {
        file << "Appending a new line to the file.\n";
        file.seekg(0); // Move the read pointer to the beginning of the file
        string line;
        while (getline(file, line)) {
            cout << line << '\n';
        }
        file.close();
    } else {
        cerr << "Unable to open file for reading and writing.\n";
    }

    return 0;
}