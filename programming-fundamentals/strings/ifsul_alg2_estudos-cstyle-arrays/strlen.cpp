#include <iostream>

using namespace std;

int strlen(char* ptr) {
    int len = 0;
    while (*ptr != '\0'){
        len++;
        ptr++;
    }
    return len;
}

int main (){

    char input[1024];
    cout << "Enter a string: ";
    cin.getline(input, sizeof(input));
    int len = strlen(input);
    cout << "You entered: " << input << '\n';
    cout << "Length: " << len << '\n';
    return 0;
}