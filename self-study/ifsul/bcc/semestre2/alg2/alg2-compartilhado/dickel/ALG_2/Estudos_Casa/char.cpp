/*
O "char" pode ser signed ou unsigned (válido ou não), contendo o conjunto de caracteres ASCII, também sendo utilizado para
números inteiros pequenos 
*/
#include <iostream>

using namespace std;

int main(){
    char letter;

    for(letter='A'; letter <= 'Z'; letter++){
        cout << letter;
    }
    return 0;
}