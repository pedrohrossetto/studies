#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <string>
#include <limits>    // Necessário para numeric_limits
#include <clocale>   // Para setlocale
#include <windows.h> // Para manipulação nativa do Console Windows
#include <cstdlib>   // Para rand() e srand()
#include <ctime>     // Para time() na semente do aleatório
#include <iomanip>   // Para std::fixed e std::setprecision

/**
 * @brief Limpa o buffer de entrada do cin de forma segura.
 * @details Remove qualquer caractere residual (como o '\n') que possa estragar o próximo getline.
 */
inline void limpar_buffer() {
    if (std::cin.bad()) {
        std::cin.clear();
    }
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else if (std::cin.rdbuf()->in_avail() > 0 || std::cin.peek() == '\n') {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

/**
 * @brief Aguarda o usuário pressionar ENTER antes de prosseguir.
 */
void pausar() {
    std::cout << "\nPressione ENTER para continuar...";
    limpar_buffer();
    std::cin.get();
}

/**
 * @brief Limpa o console de forma nativa e extremamente rápida no Windows.
 * @details Substitui o perigoso e lento 'system("cls")' usando a API do Windows.
 */
void limpar_tela() {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdOut == INVALID_HANDLE_VALUE) return;

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD count;
    DWORD cellCount;
    COORD homeCoords = { 0, 0 };

    if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;

    // Preenche o console com espaços em branco
    if (!FillConsoleOutputCharacter(hStdOut, (TCHAR) ' ', cellCount, homeCoords, &count)) return;
    // Atribui os atributos de cor padrão de volta
    if (!FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, cellCount, homeCoords, &count)) return;
    // Move o cursor de volta para o topo (0,0)
    SetConsoleCursorPosition(hStdOut, homeCoords);
}

/**
 * @brief Combina a pausa de tela e a limpeza subsequente de forma modular.
 */
void pausar_e_limpar() {
    pausar();
    limpar_tela();
}

/**
 * @brief Inverte uma string in-place (diretamente na memória).
 */
void inverteString(std::string &str) {
    size_t n = str.length();
    for (size_t i = 0; i < n / 2; ++i) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

/**
 * @brief Lê um número inteiro garantindo que o usuário não digite letras ou sujeira.
 * @details Loop eterno até que uma entrada estritamente numérica válida seja fornecida.
 */
int lerInteiroValido(const std::string& mensagem) {
    int valor;
    while (true) {
        std::cout << mensagem;
        if (std::cin >> valor) {
            limpar_buffer();
            return valor;
        }
        std::cout << "[ERRO] Entrada inválida. Digite apenas números inteiros.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

/**
 * @brief Inicializa o gerador de números aleatórios baseado no relógio do sistema.
 */
inline void inicializarAleatorio() {
    static bool inicializado = false;
    if (!inicializado) {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        inicializado = true;
    }
}

/**
 * @brief Gera um número inteiro aleatório dentro de uma faixa inclusiva [min, max].
 */
int gerarAleatorio(int min, int max) {
    inicializarAleatorio();
    return min + std::rand() % (max - min + 1);
}

/**
 * @brief Formata e exibe um valor float/double no formato de moeda (R$).
 */
void mostrarMoeda(double valor) {
    std::cout << "R$ " << std::fixed << std::setprecision(2) << valor;
}

/**
 * @brief Desenha uma linha divisória estilizada no console para organizar relatórios.
 */
void desenharLinha(char caractere = '-', int tamanho = 50) {
    for (int i = 0; i < tamanho; ++i) {
        std::cout << caractere;
    }
    std::cout << "\n";
}

#endif // UTILS_HPP