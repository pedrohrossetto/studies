#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int i, r;

    r = rand();

    for (i = 0; i < 20000; i++)

    r = rand();

    cout << "/n Numero aleatorio: " << r << endl;
    return 0;
}