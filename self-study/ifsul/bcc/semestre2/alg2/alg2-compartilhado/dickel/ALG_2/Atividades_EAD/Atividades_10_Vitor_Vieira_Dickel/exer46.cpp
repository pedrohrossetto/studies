#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void o(int*, int*);
void u(int*, int*, int*, int*, int*, int*);
void l(int**, int**, int**);

int main() {
    int* t5 = new int; *t5 = 5;
    int* t10 = new int; *t10 = 10;
    
    int* v1 = new int[*t5];
    int* v2 = new int[*t5];
    int* v3 = new int[*t10];

    int* s = new int; *s = 1; 
    srand(*s);
    delete s;

    int* i = new int;
    int* j = new int;
    int* num = new int;
    int* d = new int;

    for (*i = 0; *i < *t5; (*i)++) {
        do {
            *d = 0;
            *num = (rand() % 51) + 8;
            for (*j = 0; *j < *i; (*j)++) {
                if (v1[*j] == *num) {
                    *d = 1;
                    break;
                }
            }
        } while (*d == 1);
        v1[*i] = *num;
    }
    
    for (*i = 0; *i < *t5; (*i)++) {
        do {
            *d = 0;
            *num = (rand() % 51) + 8;
            for (*j = 0; *j < *i; (*j)++) {
                if (v2[*j] == *num) {
                    *d = 1;
                    break;
                }
            }
        } while (*d == 1);
        v2[*i] = *num;
    }
    
    delete j;
    delete d;
    delete num;

    o(v1, t5);
    o(v2, t5);

    u(v1, v2, v3, t5, t5, t10);

    cout << "Vet1 e Vet2:\n";
    cout << "Vet1: ";
    for (*i = 0; *i < *t5; (*i)++) {
        cout << v1[*i];
        if (*i < *t5 - 1) { cout << ", "; }
    }
    cout << endl;

    cout << "Vet2: ";
    for (*i = 0; *i < *t5; (*i)++) {
        cout << v2[*i];
        if (*i < *t5 - 1) { cout << ", "; }
    }
    cout << endl;

    cout << "\nVet3 (Ordenado):\n";
    cout << "Vet3: ";
    for (*i = 0; *i < *t10; (*i)++) {
        cout << v3[*i];
        if (*i < *t10 - 1) { cout << ", "; }
    }
    cout << endl;

    delete i;

    l(&v1, &v2, &v3);
    delete t5;
    delete t10;

    exit(0);
}

void o(int* v, int* t) {
    int* i = new int;
    int* j = new int;
    int* temp = new int;
    int* aux = new int;

    *aux = *t; (*aux)--; 

    for (*i = 0; *i < *aux; (*i)++) {
        for (*j = 0; *j < *aux - *i; (*j)++) {
            if (v[*j] > v[*j + 1]) {
                *temp = v[*j];
                v[*j] = v[*j + 1];
                v[*j + 1] = *temp;
            }
        }
    }
    delete i;
    delete j;
    delete temp;
    delete aux;
}

void u(int* v1, int* v2, int* v3, int* t1, int* t2, int* t3) {
    int* i = new int; *i = 0;
    int* j = new int; *j = 0;
    int* k = new int; *k = 0;
    
    while (*k < *t3) {
        if (*i < *t1 && (*j >= *t2 || v1[*i] <= v2[*j])) {
            v3[*k] = v1[*i];
            (*i)++;
        } else if (*j < *t2 && (*i >= *t1 || v2[*j] < v1[*i])) {
            v3[*k] = v2[*j];
            (*j)++;
        }
        (*k)++;
    }

    delete i;
    delete j;
    delete k;
}

void l(int** vv1, int** vv2, int** vv3) {
    delete[] *vv1;
    delete[] *vv2;
    delete[] *vv3;
    *vv1 = nullptr;
    *vv2 = nullptr;
    *vv3 = nullptr;
}