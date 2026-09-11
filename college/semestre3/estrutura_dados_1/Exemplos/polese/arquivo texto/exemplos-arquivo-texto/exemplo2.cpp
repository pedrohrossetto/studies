#include<iostream>
#include<string>
#include <sstream>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "portuguese");
    stringstream strBuffer;
    string op, linha;


    ifstream arq ("entrada.txt");

    if (!arq.is_open())
    {
        cout << "Erro: não foi possível abrir o arquivo texto.\n";
        return 0;
    }

    while(!arq.eof())
    {
        linha = ""; //IMPORTANTE, sempre inicializar a string
        getline(arq, linha);
        strBuffer = stringstream(linha);
        strBuffer >> op;

        if(op == "OPERACAO_1")
        {
            string nomePilha;
            int valor;
            strBuffer >> nomePilha; //segundo dado da linha
            strBuffer >> valor; //terceiro dado da linha
            if(nomePilha == "PILHA_1")
                cout << "O valor " << valor << " foi inserido na pilha 1!\n";
            else if(nomePilha == "PILHA_2")
                cout << "O valor " << valor << " foi inserido na pilha 2!\n";
        }
        else if(op == "OPERACAO_2")
        {
            int n, v, soma=0;
            strBuffer >> n;//segundo dado da linha
            for (int i=0; i<n; i++) //le os proximos dados da linha
            {
                strBuffer >> v;
                soma += v;
            }
            cout << "Soma dos " << n << " valores : " << soma << endl;
        }
        else if(op == "OPERACAO_3")
        {
            string nomeFila;
            float valor;
            strBuffer >> nomeFila; //segundo dado da linha
            strBuffer >> valor; //terceiro dado da linha
            if(nomeFila == "FILA_1")
                cout << "O valor " << valor << " foi inserido na fila 1!\n";
        }

    }

    return 0;
}
