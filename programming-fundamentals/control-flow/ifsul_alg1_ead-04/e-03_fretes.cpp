// Autor: Pedro H.C Rossetto
// Data: 30/03/2025
// Descrição: Código para verificar ano bissexto
// Lista EAD 4, Exercício 3, Algoritimos 1


#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main() {
    cout << fixed << setprecision(2);
    int truck_year, cargo_code, state_code, cargo_kg_value, truck_age;
    float cargo_ton_weight, cargo_value, ir_quota;

    cout << "Bem vindo(a) à calculadora de frete!" << endl << endl;
    cout << "Informe as informações solicitadas..." << endl << endl;

    cout << "Informe a tonelagem da carga: " << endl;
    cin >> cargo_ton_weight;

    do {
        cout << "Informe o código da carga (10 - 40): " << endl;
        cin >> cargo_code;
    } 
    while (cargo_code < 10 || cargo_code > 40);

    cout << "Informe ano de fabricação do caminhão: " << endl;
    cin >> truck_year;
    truck_age = 2025 - truck_year;

    if (cargo_ton_weight > 45 || truck_year > 10) {
        ir_quota = 0.05;
    };

    if (cargo_code >= 10 && cargo_code <= 20) {
        cargo_kg_value = 100;
        cargo_value = cargo_ton_weight * (cargo_kg_value * 1000);
    }
    else if (cargo_code >= 21 && cargo_code <= 30)
    {
        cargo_kg_value = 250;
        cargo_value = cargo_ton_weight * (cargo_kg_value * 1000);
    }
    else if (cargo_code >= 31 && cargo_code <= 40)
    {
        cargo_kg_value = 340;
        cargo_value = cargo_ton_weight * (cargo_kg_value * 1000);
    }
    
    do {cout << "Informe o código do estado (1-5): " << endl;
    cin >> state_code;
    } while (state_code < 1 || state_code > 5);

    if (state_code == 1){ir_quota = ir_quota + 0.35;}
    if (state_code == 2){ir_quota = ir_quota + 0.25;}
    if (state_code == 3){ir_quota = ir_quota + 0.15;}
    if (state_code == 4){ir_quota = ir_quota + 0.05;}
    if (state_code == 5){ir_quota = 0;}
    
    float cargo_total_value, ir_value;
    ir_value = cargo_value * ir_quota;
    cargo_total_value = cargo_value + ir_value;
    cout << "Tempo de uso do caminhão: "<< truck_age << " anos." << endl;
    cout << "Peso da carga do caminhão: " << cargo_ton_weight * 1000 << " Kg" << endl;
    cout << "Preço da carga: R$ " << cargo_value << endl;
    cout << "Valor do Imposto: R$ " << ir_value << endl;
    cout << "Valor total (Carga + Imposto): R$ " << cargo_total_value << endl;
}