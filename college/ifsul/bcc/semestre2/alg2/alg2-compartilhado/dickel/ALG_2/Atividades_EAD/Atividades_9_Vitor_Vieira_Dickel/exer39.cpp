#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void Cal_Rac_Res (double *peso_saco_kg, int *racao_por_gato_g, double racao_restante_kg);

int main(){

    system("chcp 1252 > nul");

    double peso_saco_kg;
    int racao_por_gato_g;
    double racao_restante_kg;

    cout << "\n === Consulta de ração por gato ===" << endl;

    cout << "\n Digite o peso do saco de ração em kg: " << endl;

    if (!(cin >> peso_saco_kg)){
        cerr << "\n Erro na leitura do peso do saco " << endl;
        return 1;
    }
    cout << "\n Digite a quantidade de ração diária para cada gato em gramas: " << endl;
    if (!(cin >> racao_por_gato_g)){
        cerr << "\n Erro na leitura de ração diária por gato " << endl;
        return 1;
    }

    Cal_Rac_Res (&peso_saco_kg, &racao_por_gato_g, &racao_restante_kg);

    cout << "\n === Resultado daqui 5 dias ===" << endl;

    cout << fixed << setprecision(2);

    cout << "Restará no saco " << racao_restante_kg << "kg de ração." << endl;

    return 0;
}

void calcular_racao_restante(double *peso_saco_kg, int *racao_por_gato_g, double *racao_restante_kg) {

    const int NUM_GATOS = 2;
    const int NUM_DIAS = 5;

    int consumo_total_g = (*racao_por_gato_g) * NUM_GATOS * NUM_DIAS;

    double consumo_total_kg = (double)consumo_total_g / 1000.0;

    double restante = (*peso_saco_kg) - consumo_total_kg;

    *racao_restante_kg = restante;
}