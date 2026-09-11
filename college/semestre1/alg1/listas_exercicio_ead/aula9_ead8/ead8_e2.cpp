// Autor: Pedro H.C Rossetto
// Data: 19/05/2025
// Descrição: Código para manipulação de vetor
// Lista de Exercícios, Exercício 2, EAD8

//Vou tentar utilizar funções secundárias, classes e headers nessa lista de exercicios



#include "includes/vet_funcs.cpp"
#include <iostream>
#include <vector>

int main(){
    using namespace std;
    int tam_vet = 10;
    VetorFunctions classeVetor;
    vector<float> vet_original = classeVetor.VetElementInput(tam_vet, 0.0f, 10.0f);
    cout << "Lista original:" << endl;
    classeVetor.CoutVetElements(vet_original);
    float media_vet = classeVetor.mediaVector(vet_original);
    cout << "\nMedia do Vector: "<< media_vet<< endl;
    
}
