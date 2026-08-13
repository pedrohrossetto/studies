#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void g(int*, int*);
void o(int*, int*);
void m(int*, int*, int*, int*);
void u(int*, int*, int*, int*, int*, int*);
void l(int**, int**, int**);

int main() {
    int* t5 = new int; *t5 = 5;
    int* t10 = new int; *t10 = 10;
    
    int* v1 = new int[*t5];
    int* v2 = new int[*t5];
    int* v3 = new int[*t10];

    srand(time(NULL));
    g(v1, t5);
    g(v2, t5);

    o(v1, t5);
    o(v2, t5);

    u(v1, v2, v3, t5, t5, t10);

    cout << "Vet1 e Vet2:\n";
    int* aux = new int; *aux = 1;
    m(v1, t5, v2, t5);
    
    cout << "\nVet3 (Ordenado):\n";
    m(v3, t10, nullptr, aux);
    delete aux;

    l(&v1, &v2, &v3);
    delete t5;
    delete t10;

    exit(0);
}

void g(int* v, int* t) {
    int* i = new int;
    int* num = new int;
    int* d = new int;
    
    for (*i = 0; *i < *t; (*i)++) {
        *d = 0;
        *num = (rand() % (58 - 8 + 1)) + 8;

        int* k = new int;
        for (*k = 0; *k < *i; (*k)++) {
            if (v[*k] == *num) {
                *d = 1;
                break;
            }
        }
        delete k;

        if (*d) {
            (*i)--;
        } else {
            v[*i] = *num;
        }
    }
    delete i;
    delete num;
    delete d;
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

void m(int* v1, int* t1, int* v2, int* t2) {
    int* i = new int;
    
    cout << "Vet1: ";
    for (*i = 0; *i < *t1; (*i)++) {
        cout << v1[*i];
        if (*i < *t1 - 1) {
            cout << ", ";
        }
    }
    cout << endl;

    if (v2 != nullptr) {
        cout << "Vet2: ";
        for (*i = 0; *i < *t2; (*i)++) {
            cout << v2[*i];
            if (*i < *t2 - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
    delete i;
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