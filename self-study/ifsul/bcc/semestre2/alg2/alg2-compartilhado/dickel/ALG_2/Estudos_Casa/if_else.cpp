#include <iostream>

using namespace std;

int main() {
    int x;

    for(x=0; x<6; x++){
        if (x == 1) cout << "x é igual a 1" << endl;
        else if (x == 2) cout << "x é igual a 2" << endl;
        else if (x == 3) cout << "x é igual a 3" << endl;
        else if (x == 4) cout << "x é igual a 4" << endl;
        else if (x == 5) cout << "x é igual a 5" << endl;
        else cout << "x não é nada entre 1 e 4" << endl;
    }
    return 0;
}