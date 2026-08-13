/*
    Autor: Pedro H.C Rossetto
    Data: 13/10/2025
    Descrição: Utilize ponteiros para calcular consumo de racao
    Algoritimos 2, Trabalho prático 9, Exercício 1
*/

#include <iostream>
#include <iomanip>

using namespace std;


void lerDados(float* ptr_peso_saco, float* ptr_qtd_gato1, float* ptr_qtd_gato2);
float calcularRacaoRestante(float peso_saco_kg, float qtd_gato1_g, float qtd_gato2_g);
void exibirResultado(float racao_restante);

int main() {

    float peso_saco_kg;
    float qtd_gato1_g;
    float qtd_gato2_g;
    float racao_final_g;


    lerDados(&peso_saco_kg, &qtd_gato1_g, &qtd_gato2_g);
    racao_final_g = calcularRacaoRestante(peso_saco_kg, qtd_gato1_g, qtd_gato2_g);
    exibirResultado(racao_final_g);

    return 0;
}


void lerDados(float* ptr_peso_saco, float* ptr_qtd_gato1, float* ptr_qtd_gato2) {
    cout << "Digite o peso do saco de racao (em kg): ";
    cin >> *ptr_peso_saco;

    cout << "Digite a quantidade diaria de racao para o primeiro gato (em gramas): ";
    cin >> *ptr_qtd_gato1;

    cout << "Digite a quantidade diaria de racao para o segundo gato (em gramas): ";
    cin >> *ptr_qtd_gato2;
}


float calcularRacaoRestante(float peso_saco_kg, float qtd_gato1_g, float qtd_gato2_g) {
    float peso_saco_em_gramas = peso_saco_kg * 1000;
    float consumo_diario_total = qtd_gato1_g + qtd_gato2_g;
    float consumo_em_5_dias = consumo_diario_total * 5;
    
    return peso_saco_em_gramas - consumo_em_5_dias;
}


void exibirResultado(float racao_restante) {
    cout << "\n-----------------------------------------\n";
    if (racao_restante >= 0) {
        cout << "Apos 5 dias, restara(o) " << fixed << setprecision(2) 
                  << racao_restante << " gramas de racao no saco." << endl;
    } else {
        cout << "A racao do saco nao sera suficiente para os 5 dias." << endl;
    }
    cout << "-----------------------------------------\n";
}
