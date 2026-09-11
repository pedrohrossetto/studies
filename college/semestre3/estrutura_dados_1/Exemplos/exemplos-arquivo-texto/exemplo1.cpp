#include<iostream>
#include<string>
#include <sstream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "portuguese");
    stringstream strBuffer;
    string linha = "operacao 5 5.2 100 texto";
    string op, texto;
    int n1, n3;
    float n2;


    //as inforações serão extraidas a cada espaço em branco
    //a conversao para o tipo de dado destino é automática
    strBuffer = stringstream(linha);
    strBuffer >> op;    //primeiro dado -> "operacao"
    strBuffer >> n1;    //segundo dado -> 5
    strBuffer >> n2;    //terceiro dado -> 5.2
    strBuffer >> n3;    //quarto dado -> 100
    strBuffer >> texto; //quinto dado -> "texto"

    cout << "op: "<< op << endl;
    cout << "n1: "<< n1 << endl;
    cout << "n2: "<< n2 << endl;
    cout << "n3: "<< n3 << endl;
    cout << "texto: "<< texto << endl;

    return 0;
}
