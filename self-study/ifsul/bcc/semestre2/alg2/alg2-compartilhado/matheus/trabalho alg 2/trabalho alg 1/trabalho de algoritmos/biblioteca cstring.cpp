#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
main(){

int x = 10;
cout.width(10);
cout.fill('*');
cout<<left<<setw(10)<<x<<"\n";


cout<<pow(3,2)<<"\n";

cout<< sqrt(4)<<"\n";

cout<<fabs(-8)<<"\n";

cout<<ceil(3.49)<<"\n";

cout<<round(3.49)<<"\n";

cout<<trunc(9.99)<<"\n";

char nome [50];
cout<<"informe nome: ";
//cin>>nome;
gets(nome);
cout<<"nome informado "<<nome<<endl;

cout <<"Digite seu nome: ";
gets(nome);
if((strcmp(nome,"Adilso"))==0)
cout<<"Nome correto\n";
else
cout<<"Erro\n";
getchar();

int j=0;
cout <<"seu nome tem:" << strlen(nome) <<" caracteres \n";
 for(int i=0; i<strlen(nome); i++){
    cout<< nome[i];
    if(i<strlen(nome)-1)
    cout<< ", ";
  }

  cout<<"\n\n\n";
  string teste("ADILSO Souza");
for(int x = 0; x <= teste.size();x++)
teste[x] = toupper(teste[x]);

cout << teste<<endl;

 string teste1("ADILSO Souza");
for(int x = 0; x <= teste1.size();x++)
teste1[x] = tolower(teste1[x]);

cout << teste1<<endl;

string teste2("ab12#@");
if(isalnum(teste2[3]))
cout << "Letra ou número";
else
cout << "Caracter especial";

  cout<<"\n\n\n";



  char teste3 [50];
  cout<<"digite algo "<<endl;
  cin>>teste3[x];

int cont_1=0, cont_2=0;
  for(int i=0;x<strlen(teste3); i++){
  if(isalpha(teste3[x])){
    cont_1++;
  }else{
    cont_2++;
  }
  }
  cout<<cont_1<<endl<<cont_2<<endl;
}



