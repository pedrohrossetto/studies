#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <limits> // Necessário para numeric_limits

void pausar_e_limpar() {
    std::cout << "\nPressione ENTER para continuar...";
    
    // Limpa qualquer resíduo no buffer (como o '\n' de um cin >> anterior)
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    // Aguarda o usuário pressionar ENTER
    std::cin.get();
    
    // Limpa o console (Windows)
    system("cls");
}


#endif