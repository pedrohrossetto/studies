#include <iostream>

using namespace std;

struct No {
    int destino;
    int peso;
    No* prox;

    No(int dest, int p = 1){
        destino = dest;
        peso = p;
        prox = nullptr;
    }
};

struct Grafo {
    int vertices;
    No** adj;

    Grafo(int vert){
        vertices = vert;
        adj = new No*[vertices];
        for (int i = 0; i < vertices; i++){
        adj[i] = nullptr;
        }
    }


    ~Grafo(){
        for (int i= 0; i < vertices; i++){
            No* atual = adj[i];
            while (atual != nullptr){
                No* temp = atual;
                atual = atual->prox;
                delete temp;
            }
        }
        delete[] adj;
    }

    void adicionarAresta(int v_origem, int v_destino, int peso = 1, bool direcionado = false){
        No* novoNo = new No(v_destino,peso);
        novoNo->prox = adj[v_origem];
        adj[v_origem] = novoNo;

        if (!direcionado){
            No* novoNoVolta = new No(v_origem,peso);
            novoNoVolta->prox = adj[v_destino];
            adj[v_destino] = novoNoVolta;
        }
    }


    void imprimir() {
        for (int i = 0; i < vertices; i++){
            cout << "Vertice " << i << ":";
            No* atual = adj[i];
            while (atual != nullptr){
                cout << "  -> " << atual->destino;
                atual = atual->prox;
            }
            cout << " -> NULL\n";
        }
    }
};

int main(){
    Grafo g(4);

    g.adicionarAresta(0, 1);
    g.adicionarAresta(0, 2);
    g.adicionarAresta(1, 3);
    g.adicionarAresta(2, 3);

    g.imprimir();

    return 0;

}
