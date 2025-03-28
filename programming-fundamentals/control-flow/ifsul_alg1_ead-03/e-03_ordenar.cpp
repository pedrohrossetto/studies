#include <iostream>
using namespace std;
int main() {
    float a,b,c;
    int menu;
    cout << "Digite o primeiro número: ";
    cin >> a;
    cout << "Digite o segundo número: ";
    cin >> b;
    cout << "Digite o terceiro número: ";
    cin >> c;
    cout << "Escolha uma opção: \n1 - Ordem crescente: \n2 - Ordem decrescente: \n3 - O maior número ao meio: ";
    cin >> menu;

    switch(menu){
        case 1:
        if (a < b && a < c )
            if (b < c)
                cout << a << " - " << b << " - " << c << endl;
            else
                cout << a << " - " << c << " - " << b << endl;
        else if (b < a && b < c)
            if (a < c)
                cout << b << " - " << a << " - " << c << endl;
                else
                    cout << b << " - " << c << " - " << a << endl;
        else
            if (a < b)
                cout << c << " - " << a << " - " << b << endl;
            else
                cout << c << " - " << b << " - " << a << endl;
                return 0;
        case 2:
        if (a > b && a > c )
            if (b > c)
            cout << a << " - " << b << " - " << c << endl;
                else 
                    cout << a << " - " << c << " - " << b << endl;
        else if (b > a && b > c)
            if (a > c)
                cout << b << " - " << a << " - " << c << endl;
                else
                    cout << b << " - " << c << " - " << a << endl;
        else
            if (a > b)
                cout << c << " - " << a << " - " << b << endl;
                else
                    cout << c << " - " << b << " - " << a << endl;
        return 0;
        case 3:
        if( a > b && a > c)
        cout << b << " - " << c << " - " << a << endl;
        if( b > a && b > c)
        cout << a << " - " << b << " - " << c << endl;
        else cout << a << " - " << c << " - " << b << endl;
        return 0;
    }
}
