#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

main() {
    
cout << fixed << setprecision(2);
int salary_brute,ir_quota,ir_value,salary_liquid;
cout << "Informe seu salário: R$ " << endl;
cin >> salary_brute;

if (salary_brute >= 0 && salary_brute <= 2000) {
    cout << "Salário Líquido: R$ Isento" << endl;
}
else if (salary_brute > 2000 && salary_brute <= 3500)
{
    ir_quota = 0.08;
    ir_value = salary_brute * ir_quota;
    salary_liquid = salary_brute - ir_value;
    cout << "Imposto de Renda: R$ " << ir_value << endl;
    cout << "Salário Líquido: R$ " << salary_liquid << endl;
}
else if (salary_brute > 3000 && salary_brute <= 4500)
{
    ir_quota = 0.18;
    ir_value = salary_brute * ir_quota;
    salary_liquid = salary_brute - ir_value;
    cout << "Imposto de Renda: R$ " << ir_value << endl;
    cout << "Salário Líquido: R$ " << salary_liquid << endl;
}
else if (salary_brute > 4500)
{
    ir_quota = 0.28;
    ir_value = salary_brute * ir_quota;
    salary_liquid = salary_brute - ir_value;
    cout << "Imposto de Renda: R$ " << ir_value << endl;
    cout << "Salário Líquido: R$ " << salary_liquid << endl;
}
}