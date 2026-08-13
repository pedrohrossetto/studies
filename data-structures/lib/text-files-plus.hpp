#ifndef TEXT_FILES_HPP
#define TEXT_FILES_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstring> // Para strerror
#include <cerrno>  // Para errno

/**
 * @brief Tenta abrir um arquivo para leitura e fornece feedback detalhado em caso de falha.
 * @param arquivo Referência para o objeto ifstream.
 * @param caminho String com o caminho do arquivo.
 * @return true se abriu com sucesso, false caso contrário.
 */
bool abrir_arquivo_leitura(std::ifstream &arquivo, const std::string &caminho) {
    if (arquivo.is_open()) {
        arquivo.close();
    }
    
    arquivo.open(caminho);

    if (!arquivo.is_open()) {
        std::cerr << "\n[ERRO DE ARQUIVO]" << std::endl;
        std::cerr << "Operação: Abertura para LEITURA" << std::endl;
        std::cerr << "Caminho tentado: " << caminho << std::endl;
        std::cerr << "Causa provável: " << std::strerror(errno) << std::endl;
        
        if (errno == ENOENT) {
            std::cerr << "Dica: Verifique se o arquivo existe na pasta correta ou se a extensão não está duplicada (ex: arquivo.txt.txt)." << std::endl;
        } else if (errno == EACCES) {
            std::cerr << "Dica: Permissão negada. O arquivo pode estar aberto em outro programa ou protegido." << std::endl;
        }
        return false;
    }
    return true;
}

/**
 * @brief Tenta abrir ou criar um arquivo para escrita (sobreposição ou anexação).
 * @param arquivo Referência para o objeto ofstream.
 * @param caminho String com o caminho do arquivo.
 * @param anexar Se true, adiciona o conteúdo ao fim do arquivo. Se false, limpa o arquivo atual.
 * @return true se abriu/criou com sucesso, false caso contrário.
 */
bool abrir_arquivo_escrita(std::ofstream &arquivo, const std::string &caminho, bool anexar = false) {
    if (arquivo.is_open()) {
        arquivo.close();
    }

    if (anexar) {
        arquivo.open(caminho, std::ios::app);
    } else {
        arquivo.open(caminho, std::ios::trunc);
    }

    if (!arquivo.is_open()) {
        std::cerr << "\n[ERRO DE ARQUIVO]" << std::endl;
        std::cerr << "Operação: Abertura para ESCRITA" << std::endl;
        std::cerr << "Caminho tentado: " << caminho << std::endl;
        std::cerr << "Causa provável: " << std::strerror(errno) << std::endl;
        
        if (errno == EACCES) {
            std::cerr << "Dica: O arquivo pode estar sendo usado por outro programa (como Excel) ou o diretório é somente leitura." << std::endl;
        }
        return false;
    }
    return true;
}

/**
 * @brief Conta quantas linhas existem em um arquivo e reseta de forma segura o ponteiro de leitura.
 * @param arquivo Referência para o objeto ifstream.
 * @return Quantidade total de linhas encontradas.
 */
int contar_linhas(std::ifstream &arquivo) {
    if (!arquivo.is_open()) return 0;

    int contador = 0;
    std::string linha;
    
    // Garante que a leitura comece do topo absolute do arquivo antes de contar
    arquivo.clear();
    arquivo.seekg(0, std::ios::beg);

    while (std::getline(arquivo, linha)) {
        contador++;
    }
    
    // Reseta o estado do fluxo e volta para o topo para que o arquivo possa ser lido de novo
    arquivo.clear();
    arquivo.seekg(0, std::ios::beg);
    return contador;
}

/**
 * @brief Grava uma string de texto em um arquivo de forma direta e fecha o fluxo.
 * @param caminho Caminho do arquivo a ser criado ou atualizado.
 * @param conteudo Texto completo que será escrito dentro do arquivo.
 * @param anexar Se true, adiciona o texto ao final do arquivo em vez de apagar o antigo.
 * @return true se a operação de escrita foi bem-sucedida, false caso contrário.
 */
bool gravar_texto_direto(const std::string &caminho, const std::string &conteudo, bool anexar = false) {
    std::ofstream arquivo;
    if (!abrir_arquivo_escrita(arquivo, caminho, anexar)) {
        return false;
    }
    arquivo << conteudo;
    arquivo.close();
    return true;
}

/**
 * @brief Lê todo o conteúdo de um arquivo de texto e o retorna como uma única string.
 * @param caminho Caminho do arquivo de origem.
 * @param conteudoSaida Referência para a string onde o texto lido será depositado.
 * @return true se leu com sucesso, false caso ocorra algum erro de abertura.
 */
bool ler_arquivo_completo(const std::string &caminho, std::string &conteudoSaida) {
    std::ifstream arquivo;
    if (!abrir_arquivo_leitura(arquivo, caminho)) {
        return false;
    }

    conteudoSaida.clear();
    std::string linha;
    bool primeiraLinha = true;

    while (std::getline(arquivo, linha)) {
        if (!primeiraLinha) {
            conteudoSaida += "\n";
        }
        conteudoSaida += linha;
        primeiraLinha = false;
    }

    arquivo.close();
    return true;
}

#endif // text_files_HPP