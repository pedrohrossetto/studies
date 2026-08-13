#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

main()
{
   setlocale(LC_ALL,"portuguese");

   char nome[100];
   int i;

   cout << "Informe o nome: ";
   //cin << nome;
   gets(nome);

   cout << "Nome informado ~~: " << nome << endl;

   cout << "Total de caracteres do nome: " << strlen(nome) << endl;

   for(i = 0; i < strlen(nome); i++)
   {
       cout << nome[i] << ", ";
   }


}
