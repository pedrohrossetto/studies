#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    char absolutePath[FILENAME_MAX];
    if (!_fullpath(absolutePath, __FILE__, FILENAME_MAX)) {
        cerr << "Erro ao obter o caminho absoluto do arquivo." << endl;
        return 1;
    }
    string path_file(absolutePath);
    size_t lastSlash = path_file.find_last_of("\\/");
    string file_name = path_file.substr(lastSlash + 1, path_file.find_last_of('.') - lastSlash - 1);
    path_file = path_file.substr(0, lastSlash + 1);

    string custom_output_file = path_file + file_name + "_output.txt";

    ofstream outFile(custom_output_file, ios::app);
    if (!outFile) {
        cerr << "Erro ao abrir o arquivo para escrita." << endl;
        return 1;
    }

    char resposta;
    do {
        string texto;
        cout << "Digite um texto: ";
        getline(cin, texto);

        outFile << texto << endl;

        cout << "Deseja incluir mais um texto? (S/s para sim, qualquer outra tecla para nao):\n";
        cin >> resposta;
    } while (resposta == 'S' || resposta == 's');

    outFile.close();

    ifstream inFile(custom_output_file);
    if (!inFile) {
        cerr << "Erro ao abrir o arquivo para leitura." << endl;
        return 1;
    }

    cout << "\nConteúdo do arquivo:" << endl;
    string linha;
    while (getline(inFile, linha)) {
        cout << linha << endl;
    }

    inFile.close();
}