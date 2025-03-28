// Autor: Pedro H.C Rossetto
// Data: 20/03/2025
// Descrição: Código para verificar direito à aposentadoria
// Lista de Exercícios, Exercício 1, EAD4

#include <iostream>
#include <cctype>  // Added for toupper()
#include <iomanip>
using namespace std;

int main() {
    int work_hours, num_dependents, overtime_hours, minimum_wage;

    cout << "Bem vindo à Calculadora de Salário!" << endl;
    cout << "Para calcular seu salário bruto, imposto de renda, e salário líquido, informe os seguintes dados:" << endl;

    cout << "Informe o salário mínimo praticado:" << endl;
    cin >> minimum_wage;

    float work_hours_value = minimum_wage/10.0f;  // Changed to 10.0f for floating-point division

    cout << "O valor de sua hora é de: R$" << work_hours_value << endl;  // Removed ",00" to show accurate decimal value

    cout << "Informe número de horas trabalhadas no mês:" << endl;
    cin >> work_hours;
    cout << "Informe número de horas extras trabalhadas no mês:" << endl;
    cin >> overtime_hours;

    float overtime_value = overtime_hours*work_hours_value*1.5f;
    float salary_base = work_hours*work_hours_value;
    float salary_overtime = salary_base + overtime_value;

    cout << "Seu salário base é de: R$ " << salary_base << endl;  // Removed ",00"

    cout << "Sua remuneração por horas extras trabalhadas é de: R$ " << overtime_value << endl;  // Fixed "renumeração" to "remuneração"
    cout << "Seu salário desse mês, com horas extras é de: R$ " << salary_overtime << endl;  // Removed ",00"

    char resposta_pcd;
    bool is_pcd;

   

    do {cout << "Informe se possui deficiência (S/N): "<<endl;
        cin >> resposta_pcd;
        resposta_pcd = toupper(resposta_pcd);} 
    while (resposta_pcd != 'N' and resposta_pcd != 'S');




    cout << "Informe o número de dependentes em sua família: " << endl;
    cin >> num_dependents;

    int dependents_value = num_dependents*32;

    cout << "A remuneração extra em virtude de dependentes é de: R$ " << dependents_value << endl;  // Fixed "renumeração" to "remuneração"

    float salary_brute = salary_base + overtime_value + dependents_value;

    cout << "Seu salário bruto é de: R$ " << salary_brute << endl;

    float ir_quota;
    float salary_liquid = salary_brute;
    if (work_hours < 0 | minimum_wage < 0 |num_dependents < 0 | overtime_hours < 0) {
        cout << "Valor inválido.";
        return 0;
    }
    if (salary_brute < 2500 | is_pcd == true) {
        cout << "Salário bruto: " << salary_brute << endl;
        cout << "Isento do imposto de renda." << endl;
        cout << "Salário líquido: " << salary_liquid << endl;
        }
    else if (salary_brute >= 2500 && salary_brute <= 4999) {
        float ir_quota = 10.0f;
        float ir_value = ((ir_quota/100) * salary_brute);
        salary_liquid = (salary_brute - (salary_brute * (ir_quota/100)));
        cout << "Salário bruto: R$ " << salary_brute << endl;
        cout << "Imposto de renda: R$ " << fixed << setprecision(2) << ir_value<<endl;
        cout << "Salário liquido: R$ " << salary_liquid << endl;
        }
    else if (salary_brute >= 5000 && salary_brute <= 6999) {
        float ir_quota = 18.0f;
        float ir_value = ((ir_quota/100) * salary_brute);
        salary_liquid = (salary_brute - (salary_brute * (ir_quota/100)));
        cout << "Salário bruto: R$ " << salary_brute << endl;
        cout << "Imposto de renda: R$ "  << fixed << setprecision(2) << ir_value<<endl;
        cout << "Salário liquido: R$ " << salary_liquid << endl;
        }
    else if (salary_brute > 6999) {
        float ir_quota = 25.0f;
        float ir_value = ((ir_quota/100) * salary_brute);
        salary_liquid = (salary_brute - (salary_brute * (ir_quota/100)));
        cout << "Salário bruto: R$ " << salary_brute << endl;
        cout << "Imposto de renda: R$ "  << fixed << setprecision(2) << ir_value<<endl;
        cout << "Salário liquido: R$ " << salary_liquid << endl;
        }
    }
    