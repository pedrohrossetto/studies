// Autor: Pedro H.C Rossetto
// Data: 29/03/2025
// Descrição: Código para verificar idade de eleitor
// Lista EAD 3, Exercício 1, Algoritimos 1

#include <iostream>
#include <iomanip>
using namespace std;

main()
{
int idade;
cout << "\n Informe sua idade: ";
cin>> idade;

if ((idade < 16) && (idade >= 0))
cout<< "\nNão eleitor";
else if ((idade == 16) || (idade == 17) || (idade >= 65))
    cout<<"\nEleitor facultativo";
else if ((idade >=18) && (idade < 65))
    cout<<"\nEleitor obrigatório";
else
    cout<<"Idade Inválida";

    cout<<"\n\n\n";
    main();
}
