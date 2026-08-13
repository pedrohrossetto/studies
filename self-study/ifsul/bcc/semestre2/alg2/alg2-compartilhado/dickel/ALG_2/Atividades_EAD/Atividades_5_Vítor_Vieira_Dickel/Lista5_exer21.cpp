/*
21- Faça um programa contendo uma função que recebe, por parâmetro, a altura (alt) e o sexo
de uma pessoa e retorna o seu peso ideal.
Para homens, calcular o peso ideal usando a fórmula peso ideal = 72.7 x alt - 58 e ,
Para mulheres, peso ideal = 62.1 x alt - 44.7
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

int calculaPesoIdeal(float alt, char sexo) {
    float pesoIdeal;
    if (sexo == 'M' || sexo == 'm') {
        pesoIdeal = 72.7 * alt - 58;
    } else if (sexo == 'F' || sexo == 'f') {
        pesoIdeal = 62.1 * alt - 44.7;
    } else {
        cout << "Sexo invalido!" << endl;
        return -1;
    }
    return pesoIdeal;
}

int main() {
    float altura;
    char sexo;
    cout << "Digite a altura (em metros): ";
    cin >> altura;
    cout << "Digite o sexo (M/F): ";
    cin >> sexo;
    float pesoIdeal = calculaPesoIdeal(altura, sexo);
    if (pesoIdeal != -1) {
        cout << fixed << setprecision(2);
        cout << "O peso ideal e: " << pesoIdeal << " kg" << endl;
    }
    return 0;
}