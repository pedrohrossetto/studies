#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>


using namespace std;

typedef struct {
    int *pt_dia, *pt_mes, *pt_ano;
} t_data;


int main(){
    int dia = 1;
    int mes = 12;
    int ano = 2025;

    t_data hoje;
    hoje.pt_dia = &dia;
    hoje.pt_mes = &mes;
    hoje.pt_ano = &ano;

    // PARA ACESSAR CAMPOS DO STRUCT COM PONTEIRO USA-SE " -> " OU (*pt).elemento
    // o operador " . " tem prioridade sobre o operador " * ", por isso usa-se parenteses
    
    cout << "Endereços " << hoje.pt_dia << hoje.pt_mes << hoje.pt_ano;
    cout << "Valores por ponteiro" << *hoje.pt_dia << *hoje.pt_mes << *hoje.pt_ano;
    
    // nesse caso se aproveita da ordem de preferencia
    // para acessar o conteúdo das variaveis de tipo ponteiro do struct
    
    return 0;
}