#include <iostream>

using namespace std;

struct Node {
    int destino;
    int peso;
    Node* prox;

    Node(int dest, int p = 1){
        destino = dest;
        peso = p;
        prox = nullptr;
    }
};

struct Graph {
    int vertices;
    Node** adj;

    Graph(int vert){
        vertices = vert;
        adj = new Node*[vertices];
        for (int i = 0; i < vertices; i++){
        adj[i] = nullptr;
        }
    }


    ~Graph(){
        for (int i= 0; i < vertices; i++){
            Node* atual = adj[i];
            while (atual != nullptr){
                Node* temp = atual;
                atual = atual->prox;
                delete temp;
            }
        }
        delete[] adj;
    }

    void adicionarAresta(int v_origem, int v_destino, int peso = 1, bool direcionado = false){
        Node* novoNo = new Node(v_destino,peso);
        novoNo->prox = adj[v_origem];
        adj[v_origem] = novoNo;

        if (!direcionado){
            Node* novoNoVolta = new Node(v_origem,peso);
            novoNoVolta->prox = adj[v_destino];
            adj[v_destino] = novoNoVolta;
        }
    }


    void imprimir() {
        for (int i = 0; i < vertices; i++){
            cout << "Vertice " << i << ":";
            Node* atual = adj[i];
            while (atual != nullptr){
                cout << "  -> " << atual->destino;
                atual = atual->prox;
            }
            cout << " -> NULL\n";
        }
    }
};
