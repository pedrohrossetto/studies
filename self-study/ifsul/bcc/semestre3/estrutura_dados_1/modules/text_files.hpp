
#ifndef text_files_HPP
#define text_files_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstring> // Para strerror
#include <cerrno>  // Para errno


/**
 * Tenta abrir um arquivo para leitura e fornece feedback detalhado em caso de falha.
 * @param arquivo Referência para o objeto ifstream.
 * @param caminho String com o caminho do arquivo.
 * @return true se abriu com sucesso, false caso contrário.
 */
bool abrir_arquivo(std::ifstream &arquivo, const std::string &caminho) {
    arquivo.open(caminho);

    if (!arquivo.is_open()) {
        std::cerr << "\n[ERRO DE DEBUG]" << std::endl;
        std::cerr << "Caminho tentado: " << caminho << std::endl;
        std::cerr << "Causa provavel: " << std::strerror(errno) << std::endl;
        
        // Dicas úteis de debug baseadas no erro comum
        if (errno == ENOENT) {
            std::cerr << "Dica: Verifique se o arquivo esta na pasta correta ou se a extensao (.txt) nao esta duplicada." << std::endl;
        } else if (errno == EACCES) {
            std::cerr << "Dica: O arquivo pode estar sendo usado por outro programa (como Excel)." << std::endl;
        }
        
        return false;
    }

    return true;
}



/**
 * Conta quantas linhas existem em um arquivo e reseta o ponteiro de leitura.
 */
int contar_linhas(std::ifstream &arquivo) {
    int contador = 0;
    std::string linha;
    while (std::getline(arquivo, linha)) contador++;
    
    arquivo.clear();
    arquivo.seekg(0);
    return contador;
}


#endif

