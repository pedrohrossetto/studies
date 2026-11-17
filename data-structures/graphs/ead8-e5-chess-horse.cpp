// Exercicio 5 - Grafo do cavalo em um tabuleiro t x t
// Vertices: casas (linha, coluna). Arestas: saltos validos do cavalo.
// Usa apenas <iostream> para entrada e saida (sem STL).
#include <iostream>
using namespace std;

const int MAX = 20;              // tamanho maximo do tabuleiro
const int MAXV = MAX * MAX;      // numero maximo de vertices

int t;
int adj[MAXV][8];                // lista de adjacencia (cavalo tem no maximo 8 vizinhos)
int grau[MAXV];

int idVertice(int l, int c) { return (l - 1) * t + (c - 1); }

void montarGrafo() {
    int dl[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dc[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
    for (int l = 1; l <= t; l++)
        for (int c = 1; c <= t; c++) {
            int v = idVertice(l, c);
            grau[v] = 0;
            for (int k = 0; k < 8; k++) {
                int nl = l + dl[k], nc = c + dc[k];
                if (nl >= 1 && nl <= t && nc >= 1 && nc <= t)
                    adj[v][grau[v]++] = idVertice(nl, nc);
            }
        }
}

bool ehVizinho(int v, int w) {
    for (int i = 0; i < grau[v]; i++)
        if (adj[v][i] == w) return true;
    return false;
}

int main() {
    cout << "Tamanho do tabuleiro (t, ate " << MAX << "): ";
    cin >> t;
    if (t < 1 || t > MAX) { cout << "Tamanho invalido.\n"; return 1; }

    int l, c;
    cout << "Posicao do cavalo (linha coluna): ";
    cin >> l >> c;
    if (l < 1 || l > t || c < 1 || c > t) { cout << "Posicao fora do tabuleiro.\n"; return 1; }

    montarGrafo();
    int v = idVertice(l, c);

    cout << "\nVertice (" << l << "," << c << ") - grau " << grau[v] << "\nAdjacentes: ";
    for (int i = 0; i < grau[v]; i++) {
        int w = adj[v][i];
        cout << "(" << w / t + 1 << "," << w % t + 1 << ")";
        if (i < grau[v] - 1) cout << ", ";
    }
    cout << "\n\n";

    // Tabuleiro: C = cavalo, X = movimento possivel, . = casa livre
    cout << "    ";
    for (int j = 1; j <= t; j++) { if (j < 10) cout << ' '; cout << j << ' '; }
    cout << '\n';
    for (int i = 1; i <= t; i++) {
        if (i < 10) cout << ' ';
        cout << i << "  ";
        for (int j = 1; j <= t; j++) {
            int w = idVertice(i, j);
            char s = (w == v) ? 'C' : (ehVizinho(v, w) ? 'X' : '.');
            cout << ' ' << s << ' ';
        }
        cout << '\n';
    }
    return 0;
}
