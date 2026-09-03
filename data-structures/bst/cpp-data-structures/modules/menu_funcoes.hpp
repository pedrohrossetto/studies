#ifndef _HPP_MENU_FUNCOES
#define _HPP_MENU_FUNCOES

#include <functional>
#include <iostream>

struct MenuAcao {
    const char* nome;
    std::function<void()> executar;
};

struct NodoMenu {
    MenuAcao acao;
    NodoMenu* proximo;
};

struct ListaMenuAcao {
    NodoMenu* cabeca;
    int tamanho;
};

static ListaMenuAcao lista_criar() {
    ListaMenuAcao lista;
    lista.cabeca  = nullptr;
    lista.tamanho = 0;
    return lista;
}

static void lista_adicionar(ListaMenuAcao& lista, MenuAcao acao) {
    NodoMenu* novo = new NodoMenu;
    novo->acao     = acao;
    novo->proximo  = nullptr;

    if (lista.cabeca == nullptr) {
        lista.cabeca = novo;
    } else {
        NodoMenu* atual = lista.cabeca;
        while (atual->proximo != nullptr)
            atual = atual->proximo;
        atual->proximo = novo;
    }
    lista.tamanho++;
}

static void menu_listar(const ListaMenuAcao& lista) {
    NodoMenu* atual = lista.cabeca;
    int i = 0;
    while (atual != nullptr) {
        std::cout << i << " - " << atual->acao.nome << "\n";
        atual = atual->proximo;
        i++;
    }
}

static void menu_executar(const ListaMenuAcao& lista, int indice) {
    if (indice < 0 || indice >= lista.tamanho) {
        std::cout << "Índice fora da lista.\n";
        return;
    }
    NodoMenu* atual = lista.cabeca;
    for (int i = 0; i < indice; i++)
        atual = atual->proximo;
    atual->acao.executar();
}

static void lista_liberar(ListaMenuAcao& lista) {
    NodoMenu* atual = lista.cabeca;
    while (atual != nullptr) {
        NodoMenu* proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }
    lista.cabeca  = nullptr;
    lista.tamanho = 0;
}

#endif
