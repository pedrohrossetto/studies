#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

struct ResultadosOperacoes {
    int adicao;
    int subtracao;
    int multiplicacao;
    int potenciacao;
};

ResultadosOperacoes calcularOperacoes(int num1, int num2) {
    ResultadosOperacoes resultados;

    resultados.adicao = num1 + num2;
    resultados.subtracao = num1 - num2;
    resultados.multiplicacao = num1 * num2;
    
    resultados.potenciacao = (int)pow(num1, num2); 

    return resultados;
}

int main() {
    int numero1, numero2;

    cout << "Digite o primeiro numero inteiro (base para a potenciacao): ";
    cin >> numero1;

    cout << "Digite o segundo numero inteiro (expoente para a potenciacao): ";
    cin >> numero2;

    ResultadosOperacoes resultados = calcularOperacoes(numero1, numero2);

    cout << "\nResultados das operacoes entre " << numero1 << " e " << numero2 << ":\n";
    cout << "Adicao (Soma): " << resultados.adicao << "\n";
    cout << "Subtracao: " << resultados.subtracao << "\n";
    cout << "Multiplicacao: " << resultados.multiplicacao << "\n";
    cout << "Potenciacao (" << numero1 << "^" << numero2 << "): " << resultados.potenciacao << "\n";

    return 0;
}