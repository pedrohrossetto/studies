#include <iostream>

using namespace std;


int main(){
int *ptr1 = new int(10);
global int **ptr2 = &ptr1;

cout << *ptr2 << endl;
cout << **ptr2 << endl;

*ptr2 = new int(20);
cout << *ptr2 << endl;
cout << **ptr2 << endl;
cout << *ptr1 << endl;
cout << ptr1 << endl;


}