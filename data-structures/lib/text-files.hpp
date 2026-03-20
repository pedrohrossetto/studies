
#ifndef text_files_HPP
#define text_files_HPP

#include <iostream>
#include <fstream>

int contar_linhas(std::string nome_arquivo) {
    std::ifstream arquivo(nome_arquivo);
    int contador = 0;
    std::string linha;

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << nome_arquivo << std::endl;
        return -1; // Retorna -1 para indicar erro
    }

    // O laço continua enquanto houver linhas para ler
    while (std::getline(arquivo, linha)) {
        contador++;
    }

    arquivo.close();
    return contador;
}

#endif

