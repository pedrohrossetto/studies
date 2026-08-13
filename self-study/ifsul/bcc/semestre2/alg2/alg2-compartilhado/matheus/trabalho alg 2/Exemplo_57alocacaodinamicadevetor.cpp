#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;



main()
{
    setlocale(LC_ALL,"Portuguese");
    int *px = new int[5];
    int *pi = new int(0);
    int *aux = new int();

    srand(time(NULL));

    /*cout << "Endereço inicial do ponteiro: " << px << endl;
    for(int *pi = new int(0); *pi < 5; (*pi)++)
    {
        *(px + *pi) = rand() % 10;
    }
    cout << "Endereço final do ponteiro: " << px << endl;
    */

    aux = px;
    cout << "Endereço inicial do ponteiro: " << px << endl;
    for(*pi = 0; *pi < 5; (*pi)++)
    {
        *px = rand() % 10;
        px++;
    }
    cout << "Endereço final do ponteiro: " << px << endl;

    px = aux;

    cout << "\n\nEndereço inicial do ponteiro: " << px << endl;
    for(int *pi = new int(0); *pi < 5; (*pi)++)
    {
        cout << *(px + *pi) << ", ";
    }
    cout << "\nEndereço final do ponteiro: " << px << endl;



}

