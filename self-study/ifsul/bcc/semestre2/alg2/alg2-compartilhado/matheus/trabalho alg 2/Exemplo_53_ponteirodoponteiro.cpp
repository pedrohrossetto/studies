#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;
void leitura(int **px2);
void calcula(int ***px3);

main()
{
    setlocale(LC_ALL, "Portuguese");
    int x, *px;
    px = &x;
    cout << "\nEndereço do ponteiro px: " << px << endl;
    leitura(&px);

    cout << endl << x << endl;
}

void leitura(int **px2)
{
    cout << "Informe um valor: ";
    cin >> **px2;
    fflush(stdin);
    calcula(&px2);
}

void calcula(int ***px3)
{
    ***px3 += 8;
    if(***px3 % 2 == 0)
        cout << "\nO resultado " << ***px3 << " é par;";
    else
        cout << "\nO resultado " << ***px3 << " é ímpar;";

    cout << "\nEndereço do ponteiro original px: " << **px3 << endl;
}
