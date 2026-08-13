// Autor: Pedro H.C Rossetto
// Data: 29/03/2025
// Descrição: Código para calcular coordenadas de um ponto em um plano cartesiano.
// Lista EAD 3, Exercício 4, Algoritimos 1


    
#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main() {
    cout << fixed << setprecision(2);
    float value_x,value_y;
    cout << "Informe a coordenada X: " << endl;
    cin >> value_x;
    cout << "Informe a coordenada Y: " << endl;
    cin >> value_y;

    if (value_x == 0 && value_y == 0) {
        cout << "Origem" << endl;
    }
    else if (value_x == 0) {
        cout << "Eixo Y" << endl;
    }
    else if (value_y == 0) {
        cout << "Eixo X" << endl;
    }
    else if (value_x > 0 && value_y > 0) {
        cout << "Q1" << endl;
    }
    else if (value_x < 0 && value_y > 0) {
        cout << "Q2" << endl;
    }
    else if (value_x < 0 && value_y < 0) {
        cout << "Q3" << endl;
    }
    else if (value_x > 0 && value_y < 0) {
        cout << "Q4" << endl;
    }
}