#include<iostream>
#include<string>
#include <sstream>
#include <fstream>

using namespace std;

struct Veiculo
{
    string placa;
    int ano;
    string marca;
    string modelo;
};

int main()
{
    setlocale(LC_ALL, "portuguese");
    stringstream strBuffer;
    string op, linha;


    ifstream arq ("entrada-exemplo3.txt");

    if (!arq.is_open())
    {
        cout << "Erro: não foi possível abrir o arquivo texto.\n";
        return 0;
    }

    while(!arq.eof())
    {
        linha = ""; //IMPORTANTE, sempre inicializar a string
        getline(arq, linha);
        if(linha.size()==0)
            break;

        strBuffer = stringstream(linha);
        int contPlavra=1;
        string palavra;
        Veiculo v;
        while(getline(strBuffer, palavra , '#')) //le cada palavra da linha separada pelo delimitador #
        {
            if(contPlavra==1) //primeira palavra da linha
                v.placa = palavra;
            else if(contPlavra==2) //segunda palavra da linha
                v.ano = stoi(palavra);
            else if(contPlavra==3) //terceira palavra da linha
                v.marca = palavra;
            else if(contPlavra==4) //quarta palavra da linha
                v.modelo = palavra;
            contPlavra++;
        }
        cout << "Veículo lido: " << v.placa << ", " << v.ano << ", " << v.marca << ", " << v.modelo << endl;
    }

    return 0;
}
