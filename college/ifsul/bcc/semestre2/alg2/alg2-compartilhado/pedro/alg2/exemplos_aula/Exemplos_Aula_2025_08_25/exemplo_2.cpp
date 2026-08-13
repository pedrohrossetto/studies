#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

main()
{
   setlocale(LC_ALL,"portuguese");

   string teste;
   int cont_1 = 0, cont_2 = 0, cont_3 = 0, i;

   cout << "Informe um texto qualquer: ";
   getline(cin, teste);

   cout << "Texto informado: " << teste << endl;

   for(i = 0; i < teste.size(); i++)
   {
       if(isalpha(teste[i]))
       {
           cont_1++;
       }
       else if(isdigit(teste[i]))
       {
           cont_2++;
       }
       else
       {
           cont_3++;
       }
   }

   cout << "Total de letras do texto: " << cont_1 << endl;
   cout << "Total de números do texto: " << cont_2 << endl;
   cout << "Total de caracteres especiais do texto: " << cont_3 << endl;




}
