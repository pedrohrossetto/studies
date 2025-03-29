/* 1 - Criar um algoritmo que leia a idade de uma pessoa e informar a sua classe eleitoral:
• não-eleitor (abaixo de 16 anos)
• eleitor obrigatório (entre 18 e 65 anos)
• eleitor facultativo (entre 16 e 18 anos ou maior de 65
*/

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
