//Executar o código com "Ctrl + Shift + P" e logo após pressionar "F5"

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <ctime>

using namespace std;

//protótipo das funções
int leitura (char texto[]);
int soma(int a, int b);

main(){
    int i, j;
    i = leitura ("Informe o valor de 1: ");
    j = leitura ("Informe o valor de 2: ");
    cout << "Soma de " << i << " + " << j << " = " << soma(i,j) << endl;
}

int leitura (char texto[]){
    int temp;
    cout << texto;
    cin >> temp;
    return temp;
}

int soma(int a, int b){
    return a + b;
}