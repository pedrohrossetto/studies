#include <iostream>
#include <fstream>
#include <cstring>
#include <istream>
#include "../modules/filas_template.hpp"
#include "../modules/utils.hpp"
#include "../modules/text_files.hpp"


using namespace std;

struct Documento
{
    string nome;
    int paginas;

    Documento(){
        nome = "";
        paginas = 0;
    }
    Documento(string nome_p, int paginas_p){
        nome = nome_p;
        paginas = paginas_p;
    }
};


int main(void)
{
    Fila <Documento> N, P;
    string op;

    limpar_tela();
    // Abrir Arquivo
    ifstream entrada;
    string caminho = "C:\\Users\\20251pf.cc0009\\Documents\\GitHub\\college_repo\\ifsul\\bcc\\semestre3\\estrutura_dados_1\\lista6\\entrada.txt";
    if (!abrir_arquivo(entrada, caminho)) {
        // Encerra o programa se o arquivo for essencial
        cout << "Erro.";
        return 1;
    }
    string comando = "";
    char fila;
    int tamanho = 0;
    while(entrada >> comando)
    {
        if(comando.size()<=0)
            {
            cout << "Comando <= 0";
            continue;
            }

        if (comando == "MOSTRAR")
        {
            entrada >> fila;
            if (fila == 'P')
            {
              //  mostraF(&P);
            }
            else if (fila == 'N')
            {
               // mostraF(&N);
            }


        }
        else if (comando == "IMPRIMIRDOC")
        {
            if (!vaziaF(&P))
            {
                // mostraF(&P);
            }
            else
            {
                // mostraF(&N);
            }


        }
        else if (comando == "INICIALIZAR")
        {
            entrada >> tamanho;
            if (verificaInicializacaoF(&P))
            {
                destroiF(&P);
                cout << "Fila P Destruída.\n";
                inicializaF(&P, tamanho);
                cout << "Fila P inicializada.\n";
            }
            else
            {
                inicializaF(&P, tamanho);
                cout << "Fila N inicializada.\n";
            }

            if (verificaInicializacaoF(&N))
            {
                destroiF(&N);
                cout << "Fila N Destruída.\n";
                inicializaF(&N, tamanho);
                cout << "Fila N inicializada.\n";
            }
            else
            {
                inicializaF(&N, tamanho);
                cout << "Fila N inicializada.\n";
            }

        }
        else if (comando == "TOTALPAG")
        {
            /* code */
        }
        else if (comando ==  "ENFILEIRARDOC")
        {
            cout << endl << "------------------" << endl;
            cout << "Comando ENFILEIRAR";
            cout << endl << "------------------" << endl;
            string nome_pdf;
            int num_pags;
            Fila<Documento> *f = NULL;
            entrada >> nome_pdf >> num_pags >> fila;
            Documento doc = Documento(nome_pdf,num_pags);

            if (fila == 'P')
            {
                cout << "Fila P escolhida" << endl;
                f = &P;
            }
            else if (fila == 'N')
            {
                cout << "Fila N escolhida" << endl;
                f = &N;
            }

            enfileiraF<Documento>(f, doc);
            cout << "Documento " << doc.nome << " Enfileirado em " << fila << endl;

        }
        else if (comando ==  "CONSULTAR")
        {
            /* code */
        }

        comando = "";
    }
    cout << "\n\nPrograma finalizado.\n\n";
    return EXIT_SUCCESS;
}

