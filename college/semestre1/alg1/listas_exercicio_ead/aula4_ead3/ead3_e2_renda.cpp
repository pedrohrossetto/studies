// Autor: Pedro H.C Rossetto
// Data: 29/03/2025
// Descrição: Código para calcular valor de imposte de renda e salário líquido.
// Lista EAD 3, Exercício 2, Algoritimos 1


    
    #include <iostream>
    #include <cstdio>
    #include <iomanip>
    using namespace std;

    int main() {
    cout << fixed << setprecision(2);
    float salary_brute,ir_quota,ir_value,salary_liquid;
    cout << "Informe seu salário R$: " << endl;
    cin >> salary_brute;

    if (salary_brute <= 0) {
        cout << "Salário inválido!" << endl;
        return 1;
    }

    if (salary_brute >= 0 && salary_brute <= 2000) {
        cout << "Imposto de Renda R$: Isento" << endl;
        cout << "Salário Líquido R$: " << salary_brute << endl;
    }
    else if (salary_brute > 2000 && salary_brute <= 3000)
    {
        ir_quota = 0.08;
        ir_value = salary_brute * ir_quota;
        salary_liquid = salary_brute - ir_value;
        cout << "Imposto de Renda R$: " << ir_value << endl;
        cout << "Salário Líquido R$: " << salary_liquid << endl;
    }
    else if (salary_brute > 3000 && salary_brute <= 4500)
    {
        ir_quota = 0.18;
        ir_value = salary_brute * ir_quota;
        salary_liquid = salary_brute - ir_value;
        cout << "Imposto de Renda R$: " << ir_value << endl;
        cout << "Salário Líquido R$: " << salary_liquid << endl;
    }
    else if (salary_brute > 4500)
    {
        ir_quota = 0.28;
        ir_value = salary_brute * ir_quota;
        salary_liquid = salary_brute - ir_value;
        cout << "Imposto de Renda R$: " << ir_value << endl;
        cout << "Salário Líquido R$: " << salary_liquid << endl;
    }
    }