// Autor: Pedro H.C Rossetto
// Data: 20/03/2025
// Descrição: Código para verificar direito à aposentadoria
// Lista de Exercícios, Exercício 1, EAD4

   
   #include <iostream>
    using namespace std;

    int main () {
        int age,work_years;
        float salary_personal,salary_bracket, salary_reference;
        cout << "Bem vindo ao sistema de aposentadoria!" << endl;
        cout << "Para saber se você tem direito à aposentadoria, informe os seguintes dados: " << endl;
        cout << "Idade, total de anos trabalhados, média salarial dos 80 maiores salários em sua profissão e seu salário." << endl;
        cout << "Lembrando que para ter direito à aposentadoria, você deve atender a um dos seguintes critérios: " << endl;
        cout << "1 - Ter 65 anos ou mais e ter um salário que corresponda a 90% da média salarial dos 80 maiores salários em sua profissão." << endl;
        cout << "2 - Ter entre 55 e 60 anos, ter trabalhado por 30 anos ou mais e ter um salário que corresponda a 85% da média salarial dos 80 maiores salários em sua profissão." << endl;
        cout << "3 - Ter entre 60 e 65 anos, ter trabalhado por 25 anos ou mais e ter um salário que corresponda a 75% da média salarial dos 80 maiores salários em sua profissão." << endl;
        cout << "Informe os dados solicitados: " << endl;
        cout << "--------------------------------------------" << endl;    //COPILOT(l.13-21)

        cout << "Informe sua idade: ";
        cin >> age;
        cout << "Informe o total de anos trabalhados: ";
        cin >> work_years;
        cout << "Informe qual é a média salarial dos 80 maiores salários em sua profissão: ";
        cin >> salary_reference;
        cout << "Informe qual é o seu salário: ";
        cin >> salary_personal;
        salary_bracket = (salary_personal/salary_reference)*100;


        if( age >= 65 && salary_bracket >= 90){
                cout << "Tem direito à aposentadoria." << endl;
        } else if ( (age >= 55 && age < 60) && work_years >= 30 && salary_bracket >= 85){
            cout << "Tem direito à aposentadoria." << endl;
        } else if ( (age >= 60 && age < 65) && work_years >= 25 && salary_bracket >= 75){
            cout << "Tem direito à aposentadoria." << endl;
        } else {
            cout << "Não tem direito à aposentadoria." << endl;
            return 0;
        }
        return main();
    }