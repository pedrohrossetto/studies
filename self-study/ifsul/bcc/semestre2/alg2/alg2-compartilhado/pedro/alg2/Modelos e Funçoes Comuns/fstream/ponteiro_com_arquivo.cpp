/*
    Autor: Pedro H.C Rossetto (Adaptado)
    Data: 10/11/2025
    Descrição: Controle de venda de ingressos (Adaptado para Ponteiros e Alocação Dinâmica)
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <cstdlib> // Necessário para alocação dinâmica se usasse malloc/free, mas usaremos new/delete do C++

using namespace std;


main(){
setlocale(LC_ALL,"Portuguese");
int *px = new int[10];
int *cont = new int(0);

ifstream ler("exemplo.txt");

if (ler.is_open()){
while (!ler.eof())
{
    ler >> *px;
}   

}
}