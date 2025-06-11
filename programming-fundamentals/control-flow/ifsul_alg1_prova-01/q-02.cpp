// Autor: Pedro H.C Rossetto
// Data: 24/04/2025
// Descrição: Código para desenhar oito com asteriscos
// PROVA 1, QUESTÃO 1

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
int largura, altura;


do
{
    cout << "\nInforme a altura da imagem: ";
    cin >> altura;
    if (altura > 21 || altura < 7)
    {
        cout << "\nValor fora do intervalo.\n";
    }
    if (altura % 2 == 0){
        cout << "\nValor da altura deve ser impar.\n";
    }
} while ((altura > 21 || altura < 7) || (altura % 2 == 0));

do
{
    cout << "\nInforme a largura da imagem: ";
    cin >> largura;

    if (largura > 18 || largura < 4)
    {
        cout << "\nValor fora do intervalo.\n";
    }
    if (largura % 2 != 0){
        cout << "\nValor da largura deve ser par.\n";
    }
    if (largura > altura){
        cout << "\nValor da Largura deve ser menor que a Altura.\n";
    }
} while (   (   (largura >= 19 || largura <= 3)    ||  ((largura % 2 != 0) || (largura > altura))  ) );

int meio;
meio = (altura / 2) + 1;

for (int linha = 1; linha <= altura; linha++) 
// itera cada linha, inicia na 1, verifica altura, incrementa 1
{
    for (int coluna = 1; coluna <= largura; coluna++)
    // ipara cada linha, itera cada coluna, inicia na 1, verifica largura, incrementa 1

    {
        if (    (linha == 1 || linha == altura)    ||   (linha == meio) ||   (coluna == 1 || coluna == largura)  )
        // valida a coluna e linha 1 para que sejam preenchidas,
        // verifica se a linha esta no meio, formando a barra central
        // verifica se a linha ou a coluna é igual ao valor definido em altura e largura, coluna formando o perimetro
        {
            cout << "*"; // se forem, preenche com o asterísco, retornando a forma do desenho
        }
        else
        {
            cout << " "; // se não forem, preenche com espaço, retornando a largura do desenho
        }
    }
    cout << endl;
}
cout << "Altura: "<<altura<< endl;
cout << "Largura: "<< largura<< endl;
}