#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <limits> // Necessário para numeric_limits
#include <clocale>   // Para setlocale
#include <windows.h> // Para SetConsole

/**
 * Aguarda o usuário pressionar ENTER antes de prosseguir.
 * Útil para permitir a leitura de relatórios ou mensagens de erro.
 */
void pausar() {
    std::cout << "\nPressione ENTER para continuar...";
    
    // Limpa o buffer caso haja resíduos de um 'cin >>' anterior
    if (std::cin.peek() == '\n') {
        std::cin.ignore();
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cin.get();
}

/**
 * Limpa o console de forma independente.
 */
void limpar_tela() {
    // No Windows: cls | No Linux/macOS: clear
    system("cls");
}


void pausar_e_limpar() {
    std::cout << "\nPressione ENTER para continuar...";
    
    // Limpa qualquer resíduo no buffer (como o '\n' de um cin >> anterior)
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    // Aguarda o usuário pressionar ENTER
    std::cin.get();
    
    // Limpa o console (Windows)
    system("cls");
}

void inverteString(std::string &str) {
    int n = str.length();
    
    // Percorre apenas até a metade da string
    for (int i = 0; i < n / 2; i++) {
        // Lógica de troca manual (sem usar std::swap se preferir)
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}


#endif