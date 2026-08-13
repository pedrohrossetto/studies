/*
    Autor: Pedro H.C Rossetto
    Data: 13/10/2025
    Descrição: Utiliza ponteiros para preencher dois vetores de caracteres
               e trocar seus elementos de forma invertida.
    Algoritimos 2, Trabalho prático 9, Exercício 3
*/

#include <iostream>
using namespace std;
const int TAMANHO = 10;

void preencherVetor(char* ponteiroVetor, char nomeDoVetor);
void mostrarVetores(const char* ponteiroA, const char* ponteiroB, const char* momento);
void trocarElementos(char* ponteiroA, char* ponteiroB);

int main() {
    
    char vetorA[TAMANHO];
    char vetorB[TAMANHO];

    cout << "--- Preenchimento dos Vetores ---\n";
    preencherVetor(vetorA, 'A');
    preencherVetor(vetorB, 'B');
    mostrarVetores(vetorA, vetorB, "ANTES DA TROCA");
    trocarElementos(vetorA, vetorB);
    mostrarVetores(vetorA, vetorB, "DEPOIS DA TROCA");

    return 0;
}


void preencherVetor(char* ponteiroVetor, char nomeDoVetor) {
    cout << "\nDigite os " << TAMANHO << " caracteres para o Vetor " << nomeDoVetor << ":" << endl;
    for (int i = 0; i < TAMANHO; ++i) {
        cout << "Posicao " << i << ": ";
        
        cin >> *(ponteiroVetor + i);
    }
}



void mostrarVetores(const char* ponteiroA, const char* ponteiroB, const char* momento) {
    cout << "\n-----------------------------------------\n";
    cout << "      VETORES " << momento << "      \n";
    cout << "-----------------------------------------\n";
    cout << "Vetor A: [ ";
    for (int i = 0; i < TAMANHO; ++i) {
        
        cout << *(ponteiroA + i) << " ";
    }
    cout << "]" << endl;

    cout << "Vetor B: [ ";
    for (int i = 0; i < TAMANHO; ++i) {
        cout << *(ponteiroB + i) << " ";
    }
    cout << "]" << endl;
    cout << "-----------------------------------------\n";
}



void trocarElementos(char* ponteiroA, char* ponteiroB) {
    char* temp = new char; 

    for (int i = 0; i < TAMANHO; ++i) {        
        *temp = *(ponteiroA + i);
        *(ponteiroA + i) = *(ponteiroB + TAMANHO - 1 - i);
        *(ponteiroB + TAMANHO - 1 - i) = *temp;
    }
    delete temp; 
    cout << "\n... Elementos trocados com sucesso! ...\n";
}