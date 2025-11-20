#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>


using namespace std;

typedef struct {
    int dia, mes, ano;
} t_data;


int main(){
    t_data hoje, *pt;
    pt = &hoje;
    // PARA ACESSAR CAMPOS DO STRUCT COM PONTEIRO USA-SE " -> " OU (*pt).elemento
    // o operador " . " tem prioridade sobre o operador " * ", por isso usa-se parenteses
    pt -> dia = 14;
    pt -> mes = 11;
    pt -> ano = 2025;

    cout << hoje.dia << hoje.mes << hoje.ano;
    return 0;
}