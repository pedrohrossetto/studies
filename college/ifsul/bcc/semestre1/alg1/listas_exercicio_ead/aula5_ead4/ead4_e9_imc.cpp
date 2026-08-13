// Autor: Pedro H.C Rossetto
// Data: 30/03/2025
// Descrição: Código para calcular imc
// Lista EAD 3, Exercício 9, Algoritimos 1


#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
using namespace std;

int main() {
cout << fixed << setprecision(2);
int sex, age;
float height, ideal_weight;
string name;
cout << "Bem vindo(a) à calculadora de IMC!" <<endl;
cout << "Como gostaria de ser chamado?" << endl;
getline(cin, name); // Lê o nome completo

do {
    cout << "Perfeito, " << name <<"! Agora, informe seu sexo de acordo com as opções:\n1 - Masculino\n2 - Feminino" << endl;
    cin >> sex;
} while ( sex > 2 || sex < 1);

do {cout << "Informe sua altura em centímetros: " << endl;
cin >> height;}
while (height <= 0);

do {cout << "Informe sua idade: " << endl;
cin >> age;
} while(age <= 0);

if (sex  == 1) {
 if ( height > 170) {
    if (age <= 20){
        ideal_weight = (0.727 * height) - 58;
    }
   if (age > 20 && age <= 39) {
    ideal_weight = (0.727 * height) - 53;
   }
   else if (age >= 40) {
    ideal_weight = (0.727 * height) - 45;
   }
 }
 if (height <= 170) {
    if (age <= 40) {
        ideal_weight = (0.727 * height) - 50;
    }
    if (age > 40) {
        ideal_weight = (0.727 * height) - 58;
    }
 }
}
if (sex == 2) {
    if ( height > 150) {
            ideal_weight = (0.621 * height) - 45;
     }
     if (height <= 150) {
        if (age < 35) {
            ideal_weight = (0.621 * height) - 49;
        }
        if (age >= 35) {
            ideal_weight = (0.621 * height) - 45;
        }
     }
}
cout << "Nome: " << name << endl;
cout << "Peso ideal: " << ideal_weight << endl;

}