#include <iostream>
using namespace std;

#include "fila-dinamica-template.hpp"


//busca de pelo nome do cliente
bool fConcatenada(Fila<string> *f1,Fila<string> *f2, Fila<string> *conc)
{
    while(!vaziaF(f1))
    {
        enfileiraF(conc,desenfileiraF(f1));
    }
    while(!vaziaF(f2))
    {
        enfileiraF(conc,desenfileiraF(f2));
    }
    cout<<"fila concatenada:"<<endl;
    mostraF(conc);

}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    Fila<string> f1;
    Fila<string> f2;
    Fila<string> conc;
    string a =  "texto1";
    string b =  "texto2";
    string c =  "texto3";
    string d =  "texto4";
    string e =  "texto5";
    string f =  "texto6";

    cout << "\n#######STRING#######\n";
    enfileiraF(&f1, a);
    enfileiraF(&f1, b);
    enfileiraF(&f1, c);
    enfileiraF(&f2, d);
    enfileiraF(&f2, e);
    enfileiraF(&f2, f);
    cout<<"fila 1:"<<endl;
    mostraF(&f1);
    cout<<"fila 2:"<<endl;
    mostraF(&f2);
    fConcatenada(&f1,&f2,&conc);

    destroiF(&f1);
    destroiF(&f2);
    destroiF(&conc);



    return EXIT_SUCCESS;

}//final do main

