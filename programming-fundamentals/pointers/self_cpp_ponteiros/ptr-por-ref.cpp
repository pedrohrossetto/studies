#include <iostream>

void alteraPorValor(int* p) {
    static int novo_valor = 99;
    // Muda APENAS a cópia local de 'p'. O chamador não sente nada.
    p = &novo_valor;
}

void alteraPorReferencia(int* &p) {
    static int novo_valor = 99;
    // 'p' é um alias direto. O ponteiro do chamador é alterado na mesma hora.
    p = &novo_valor;
}

void alteraPorDoublePointer(int* *p) {
    static int novo_valor = 99;
    //definir
    *p = &novo_valor;
}

int main() {
    int original = 10;
    int* meu_ponteiro = &original;

    std::cout << "Valor inicial: " << *meu_ponteiro << "\n"; // Imprime 10

    alteraPorValor(meu_ponteiro);
    std::cout << "Apos chamada por valor: " << *meu_ponteiro << "\n"; // Continua 10! Nada mudou.

    alteraPorDoublePointer(&meu_ponteiro);
    std::cout << "Apos chamada por double pointer: " << *meu_ponteiro << "\n";


    alteraPorReferencia(meu_ponteiro);
    std::cout << "Apos chamada por referencia: " << *meu_ponteiro << "\n"; // Imprime 99!

    return 0;
}
