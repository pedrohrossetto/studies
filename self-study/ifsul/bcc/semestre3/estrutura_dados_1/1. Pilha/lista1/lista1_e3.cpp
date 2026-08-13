#include <iostream>
#include <ctime>   
#include <cstdlib> 
#include "../modules/vetor_dinamico.hpp"

using namespace std;

int main() {
    // Inicializa a semente para números aleatórios
    srand(static_cast<unsigned int>(time(0)));

    int* meuVetor = nullptr; // Ponteiro inicializado como nulo para controle
    int tamanho = 10;
    int opcao;

    do {
        cout << "\n========== MENU DE VETORES ==========" << endl;
        cout << "1. Gerar novo vetor (10 posicoes, 15-30)" << endl;
        cout << "2. Mostrar vetor atual" << endl;
        cout << "3. Sair e liberar memoria" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                // Se já existir um vetor, liberamos antes de criar um novo
                if (meuVetor != nullptr) {
                    liberar_vetor(meuVetor);
                }
                
                meuVetor = alocar_vetor(tamanho);
                preencher_aleatorio(meuVetor, tamanho, 15, 30);
                cout << ">> Vetor gerado e preenchido com sucesso!" << endl;
                break;

            case 2:
                // A função mostrar_vetor no seu .hpp já trata se o ponteiro é null
                cout << ">> Status do Vetor: ";
                mostrar_vetor(meuVetor, tamanho);
                break;

            case 3:
                liberar_vetor(meuVetor);
                cout << ">> Memoria liberada. Encerrando o programa..." << endl;
                break;

            default:
                cout << ">> Opcao invalida! Tente novamente." << endl;
        }

    } while (opcao != 3);

    return 0;
}