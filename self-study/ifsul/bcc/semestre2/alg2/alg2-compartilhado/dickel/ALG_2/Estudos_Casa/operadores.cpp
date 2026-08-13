#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");

    cout << "Exemplo de Operadores em C++" << endl;
    cout << "================================" << endl;

    cout << " < menor que" << endl;
    cout << " <= menor ou igual a" << endl;
    cout << " > maior que" << endl;
    cout << " >= maior ou igual a" << endl;
    cout << " == igual a" << endl;
    cout << " != diferente de" << endl;
    cout << " && operador lógico AND" << endl;
    cout << " || operador lógico OR" << endl;
    cout << " ! operador lógico NOT" << endl;
    
    // Declaração de variáveis
    int a = 10, b = 20;

    // Operadores Aritméticos
    cout << "Soma: " << (a + b) << endl;
    cout << "Subtração: " << (a - b) << endl;
    cout << "Multiplicação: " << (a * b) << endl;
    cout << "Divisão: " << (b / a) << endl;
    cout << "Módulo: " << (b % a) << endl;

    // Operadores de Atribuição
    a += 5; // a = a + 5
    cout << "Atribuição com adição: " << a << endl;

    // Operadores de Comparação
    cout << "Igualdade: " << (a == b) << endl;
    cout << "Desigualdade: " << (a != b) << endl;
    cout << "Maior que: " << (a > b) << endl;
    cout << "Menor que: " << (a < b) << endl;

    // Operadores Lógicos
    bool x = true, y = false;
    cout << "AND lógico: " << (x && y) << endl;
    cout << "OR lógico: " << (x || y) << endl;
    cout << "NOT lógico: " << (!x) << endl;

    int legth;
    int width;
    int area;

    legth = 7; // Atribuição de valor à variável legth (comprimento)
    width = 5; // Atribuição de valor à variável width (largura)

    area = legth * width; // Cálculo da área
    cout << "Área do retângulo: " << area << endl;

    return 0;
}