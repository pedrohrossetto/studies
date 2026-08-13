#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

main()
{
    setlocale(LC_ALL, "Portuguese");
    int x = 5, *px, **px2, ***px3;
    px = &x;
    px2 = &px;
    px3 = &px2;

    cout << "x: " << x << endl;
    cout << "px: " << px << endl;
    cout << "px: " << &px << endl;
    cout << "px: " << *px << endl << endl;

    cout << "px2: " << px2 << endl;
    cout << "px2: " << *px2 << endl;
    cout << "px2: " << **px2 << endl << endl;

    cout << "px3: " << px3 << endl;
    cout << "px3: " << *px3 << endl;
    cout << "px3: " << **px3 << endl;
    cout << "px3: " << ***px3 << endl;




}
