#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

main(){

    setlocale(LC_ALL, "portuguese");

    string teste;
    int cont_1 = 0, cont_2 = 0, i;

    cout << "Informe um texto qualquer: ";
    getline(cin, teste);

    cout << "Texto Informado: " << teste << endl;

    for (i = 0; i < teste.size(); i++){
        if(isalpha(teste[i])){
            cont_1++;
        } else{
            cont_2++;
        }
    }
    cout << "Total de letras do texto: " << cont_1 << endl;
    cout << "Total de outros caracteres: " << cont_2 << endl;

}
