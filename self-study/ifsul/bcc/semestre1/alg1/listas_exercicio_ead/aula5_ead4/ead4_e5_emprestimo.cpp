// Autor: Pedro H.C Rossetto
// Data: 30/03/2025
// Descrição: Código para verificar prestação de empréstimo
// Lista EAD 4, Exercício 5, Algoritimos 1


#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;


main() {
cout << fixed << setprecision(2);
float salary_brute, loan_value, salary_compromissed;

bool is_loan_ok;

cout << "Informe seu salário bruto: R$ " << endl;
cin >> salary_brute;

cout << "Informe valor de prestação a simular: R$ " << endl;
cin >> loan_value;

salary_compromissed = (loan_value/salary_brute);

is_loan_ok = salary_compromissed <= 0.300110;

if (is_loan_ok){
cout << "Empréstimo perimitido!" << endl;
cout << "Porcentual do salário que será comprometido: " << salary_compromissed * 100 << " %" << endl;
} else {
    cout << "Empréstimo não permitido.";
    cout << "Porcentual do salário que seria comprometido: " << salary_compromissed * 100 << " %" << endl;
}
}
