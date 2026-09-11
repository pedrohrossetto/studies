#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<windows.h>


using namespace std;

main()
{

   //altera a codificação para 1252 para exibição e entrada de dados acentuados
   //usando a biblioteca do sistema operacional
   SetConsoleCP(1252);
   SetConsoleOutputCP(1252);

   string texto;

   cout << "Exibindo um texto acentuado: é maçã número" << endl << endl;

   cout << "Informe um texto qualquer acentuado: ";
   getline(cin, texto);

   cout << texto;
}
