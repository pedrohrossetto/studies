#include <iostream>
#include <cstdio>

using namespace std;

const int TAMANHO = 10;

void preencher_vetor(char *p_vetor, const char nome_vetor);
void mostrar_vetor(const char *p_vetor, const char nome_vetor);
void trocar_elementos(char *p_a, char *p_b);

int main() {
    char vetor_A[TAMANHO];
    char vetor_B[TAMANHO];

    preencher_vetor(vetor_A, 'A');
    preencher_vetor(vetor_B, 'B');

    cout << "\n--- VETORES ANTES DA TROCA ---\n";
    mostrar_vetor(vetor_A, 'A');
    mostrar_vetor(vetor_B, 'B');

    trocar_elementos(vetor_A, vetor_B);

    cout << "\n--- VETORES DEPOIS DA TROCA ---\n";
    mostrar_vetor(vetor_A, 'A');
    mostrar_vetor(vetor_B, 'B');

    return 0;
}

void preencher_vetor(char *p_vetor, const char nome_vetor) {
    cout << "Digite 10 caracteres para o Vetor " << nome_vetor << ":\n";
    
    for (int i = 0; i < TAMANHO; ++i) {
        char *p_atual = p_vetor + i; 
        
        cout << nome_vetor << "[" << i + 1 << "]: ";
        
        cin >> *p_atual;

        cin.ignore(256, '\n'); 
    }
}

void mostrar_vetor(const char *p_vetor, const char nome_vetor) {
    cout << "Vetor " << nome_vetor << ": [";
    for (int i = 0; i < TAMANHO; ++i) {
        cout << *(p_vetor + i) << (i < TAMANHO - 1 ? ", " : "");
    }
    cout << "]\n";
}

void trocar_elementos(char *p_a, char *p_b) {
    char *p_temp = new char; 
    
    cout << "\nRealizando a troca de elementos...\n";

    for (int i = 0; i < TAMANHO; ++i) {
        char *p_elemento_A = p_a + i;
        char *p_elemento_B = p_b + (TAMANHO - 1 - i);

        // Troca (swap)
        *p_temp = *p_elemento_A;
        *p_elemento_A = *p_elemento_B;
        *p_elemento_B = *p_temp;
    }
}