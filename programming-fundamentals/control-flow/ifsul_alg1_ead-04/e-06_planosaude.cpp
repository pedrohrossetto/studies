// Autor: Pedro H.C Rossetto
// Data: 30/03/2025
// Descrição: Código para verificar plano de saúde
// Lista EAD 4, Exercício 6, Algoritimos 1

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    cout << fixed << setprecision(2);
    string nome;
    int idade;
    float valor_pagar;

    cout << "Bem vindo ao plano de saúde C++ !" << endl;
    cout << "Como gostaria de ser chamado? " << endl;
    getline(cin, nome); // Lê o nome completo
    cout << "Qual sua idade?" << endl;
    cin >> idade;

    // Restante da lógica...
    if (idade >= 0 && idade <= 10) {valor_pagar = 30;}
    else if (idade > 10 && idade <= 29) {valor_pagar = 60;}
    else if (idade > 29 && idade <= 45) {valor_pagar = 120;}
    else if (idade > 45 && idade <= 59) {valor_pagar = 150;}
    else if (idade > 59 && idade <= 65) {valor_pagar = 250;}
    else if (idade > 65) {valor_pagar = 400;}
    else {cout << "Idade inválida"; return 1;}

    cout << "Nome: " << nome << endl;
    cout << "Valor a pagar: R$" << valor_pagar << endl;

    return 0;
}