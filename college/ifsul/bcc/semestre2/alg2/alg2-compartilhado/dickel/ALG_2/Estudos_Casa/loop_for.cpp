#include <iostream>
#include <cmath>

using namespace std;    

int main(){
    int num;
    double raiz;

    for (num = 1; num < 100; num++){
        raiz = sqrt((double)num);
        cout << "A raiz quadrada de " << num << " = " << raiz << endl;
    }
    return 0;
}