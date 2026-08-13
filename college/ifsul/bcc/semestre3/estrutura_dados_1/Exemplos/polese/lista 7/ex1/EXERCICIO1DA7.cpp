#include <iostream>
using namespace std;

#include "fila-dinamica-template.hpp"
#include "pilha-dinamica-template.hpp"

int main(void)
{
    int x, cont= 0;
    Fila<string> f1;
    Pilha<string> p1;
    Pilha<string> aux;


    do
    {
        cout << "\n|----------------------------menu----------------------------|\n";
        cout << "\n1-Incluir na fila\n";
        cout << "\n2-Remover da fila\n";
        cout << "\n3-Mostrar fila\n";
        cout << "\n4-Inverter fila\n";
        cin >> x;
        if (x == 1)
        {
            string y;
            cout << "\nDigite que valor enfileirar:\n";
            cin>>y;
            if(enfileiraF(&f1, y)==true)
            {
                cout<<"valor enfileirado com sucesso!"<<endl;
            };
            x = 0;
            cont++;
        }
        else if (x == 2)
        {
            int y;
            cout<<"o valor "<<desenfileiraF(&f1)<<" foi desinfileirado!"<<endl;
            x = 0;
            cont--;
        }
        else if (x == 3)
        {
            mostraF(&f1, "tipo int");
            x = 0;

        }
        else if (x == 4)
        {
            Fila<int> p1;
            cout<<"fila antes: "<<endl;
            mostraF(&f1, "f1");
////////////////////////////////////////////////////////////////////////////////
            char frase;
            while(!vaziaF(&f1))
            {
                empilhaP(&aux,desenfileiraF(&f1));
            }
            while(!vaziaP(&aux))
            {
               enfileiraF(&f1,desempilhaP(&aux));
            }
            cout<<"fila depois: "<<endl;
            mostraF(&f1, "f1");
            x = 0;

        }
    }
    while (x < 1 || x > 5);

    destroiF(&f1);
    return EXIT_SUCCESS;

} // final do main
