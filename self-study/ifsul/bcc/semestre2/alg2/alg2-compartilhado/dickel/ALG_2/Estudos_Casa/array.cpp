// Matrizes 
#include <iostream>

using namespace std;

int main(){
    int matriz [3] [3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    int somaP = 0, somaS = 0;

    for (int i = 0; i < 3; i++){
        somaP += matriz[i][i];
        somaS += matriz[i][3-1 - i];
    }
    cout << somaP << endl;
    cout << somaS << endl;

    return 0;
}