#ifndef _HPP_MENU_FUNCOES
#define _HPP_MENU_FUNCOES

#include <functional>
#include <iostream>
#include <string>
#include <vector>

struct MenuAcao {
    std::string nome;
    std::function<void()> executar;
};

static void menu_listar(const std::vector<MenuAcao>& acoes) {
    for (size_t i = 0; i < acoes.size(); ++i) {
        std::cout << i << " - " << acoes[i].nome << "\n";
    }
}

static void menu_executar(const std::vector<MenuAcao>& acoes, int indice) {
    if (indice < 0 || indice >= static_cast<int>(acoes.size())) {
        std::cout << "Índice fora da lista.\n";
        return;
    }
    acoes[indice].executar();
}

#endif
