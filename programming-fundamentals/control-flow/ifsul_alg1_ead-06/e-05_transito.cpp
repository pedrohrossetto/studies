// Autor: Pedro H.C Rossetto
// Data: 20/04/2025
// Descrição: Código para para apresentar menu
// Lista de Exercícios, Exercício 5, EAD6

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <string>
using namespace std;

int main() {
string cidade_codigo;
int count_cidade,num_carros,num_acidentes;
float indice_acidentes;

while (count_cidade<5,count_cidade++)
{
cout << "Informe código da cidade:\n";
cin >> cidade_codigo;
cout << "Informe número de veículos:\n";
cin >> num_carros;
while (num_carros < 0) {
    cout << "Erro: O número de veículos não pode ser negativo. Tente novamente:\n";
    cin >> num_carros;
}
cout << "Informe número de acidentes de trânsito com vítimas:\n";
cin >> num_acidentes;
while (num_acidentes < 0) {
    cout << "Erro: O número de acidentes não pode ser negativo. Tente novamente:\n";
    cin >> num_acidentes;
}
}



}