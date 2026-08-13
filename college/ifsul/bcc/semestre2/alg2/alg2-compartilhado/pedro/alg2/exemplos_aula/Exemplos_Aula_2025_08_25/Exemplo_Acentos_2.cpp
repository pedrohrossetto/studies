#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>


using namespace std;

main()
{
   //setlocale(LC_ALL,"portuguese");

   //altera a codificação para 1252 para exibição e entrada de dados acentuados
   //usando o comando system
   system("chcp 1252 > nul");

   string texto;

   cout << "Exibindo um texto acentuado: é maçã número" << endl << endl;

   cout << "Informe um texto qualquer acentuado: ";
   getline(cin, texto);

   cout << texto;

}
