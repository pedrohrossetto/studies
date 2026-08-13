#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

#include "filacircular_lista5_ex2.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Fila p1;
    Fila n1;
    bool resultado;
    string OP, OP1, OP2;
    int tam;

    ifstream arq("arq.txt");

    while(!arq.eof())
    {
        stringstream strBuffer;
        string linha = "";
        getline (arq, linha);
        strBuffer = stringstream(linha);
        strBuffer >> OP;

        if (OP == "INICIALIZAR")
        {
            strBuffer >> tam;
            inicializaF(&p1, tam);
            inicializaF(&n1, tam);
            cout<<"A fila P e N foram inicializadas com o tamanho " << tam <<endl;

        }
        else if (OP == "MOSTRAR")
        {
            strBuffer >> OP1;
            string nome_fila;
            if (OP1 == "P")
            {
                nome_fila = "P";
                MostraTudo(&p1,nome_fila);
            }
            else if (OP1 == "N")
            {
                nome_fila = "N";
                MostraTudo(&n1, nome_fila);
            }


        }
        else if (OP == "IMPRIMIRDOC")
        {
            if (!vaziaF(&p1))
            {
                ImprimirDoc(&p1);
            }
            else if (!vaziaF(&n1))
            {
                ImprimirDoc(&n1);
            }
            else
                cout<< "Não há documentos para imprimir"<<endl;
        }

        else  if (OP == "ENFILEIRARDOC")
        {
            string nome;
            strBuffer >> nome;
            cout<<nome<<endl;
            int qtd_pg;
            strBuffer>> qtd_pg;
            cout<<qtd_pg<<endl;
            string OP3;
            strBuffer >> OP3  ;

            if (OP3 == "P")
            {
                Enfileirar(&p1,nome,qtd_pg);
            }
            else if (OP3 == "N")
            {
                Enfileirar(&n1,nome,qtd_pg);
            }


        }
        else  if (OP == "TOTALPAG")
        {
            int soma = TotalPag(&n1) + TotalPag(&p1);
            cout<< soma<<" página(s)"<<endl;
        }

        /*   else  if (OP == "CONSULTAR")
           {
               string nome = OP1;
               if (OP2 == P)
               {
                   espiaF(&p1,nome);
               }
               else if (OP2 == P)
               {
                   espiaF(&p1,nome);
               }
        }*/


    }
} // final do main
