#include <iostream>

using namespace std;

int t;

#define pi 3.14;
#define curtir cout << "Curta o codigo" << endl;

//funcao void não tem saida
void inscrever(){
    cout << "Se inscreva no vestibular do IFSUL" << endl;
}

int somar(int &x, int &y){
    int t;
    t = 1;

    int soma;
    soma = x + y;
    x=30;
    return soma;
}

int main(){

    //int t;
    t = 0;

    inscrever();
    
    int a = 5, b = 4;
    int s;
    s = somar(a, b);
    cout << "Valor de a: " << a << endl;
    cout << "Soma do valor do s = " << s << endl;

    cout << "Valor de t: " << t << endl;

    //cout << pi;

    curtir;

    return 0;
}