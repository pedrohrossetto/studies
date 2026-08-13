#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    char* A = (char*) malloc(10 * sizeof(char));
    char* B = (char*) malloc(10 * sizeof(char));

    cout << "Digite 10 caracteres para o vetor A: ";
    for (int i = 0; i < 10; i++) {
        cin >> *(A + i);
    }

    cout << "Digite 10 caracteres para o vetor B: ";
    for (int i = 0; i < 10; i++) {
        cin >> *(B + i);
    }

    cout << "\nAntes da troca:\n";
    cout << "A: ";
    for (int i = 0; i < 10; i++) cout << *(A + i);
    cout << "\nB: ";
    for (int i = 0; i < 10; i++) cout << *(B + i);

    for (int i = 0; i < 10; i++) {
        char temp = *(A + i);
        *(A + i) = *(B + (9 - i));
        *(B + (9 - i)) = temp;
    }

    cout << "\n\nDepois da troca:\n";
    cout << "A: ";
    for (int i = 0; i < 10; i++) cout << *(A + i);
    cout << "\nB: ";
    for (int i = 0; i < 10; i++) cout << *(B + i);
    cout << endl;

    free(A);
    free(B);
    return 0;
}