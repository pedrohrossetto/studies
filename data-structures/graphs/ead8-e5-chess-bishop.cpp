// Exercicio 6 - Grafo do bispo (diagonais) e grafo da torre (vertical/horizontal)
// Vertices: casas (linha, coluna). Arestas: casas alcancaveis em um movimento.
// Usa apenas <iostream> para entrada e saida (sem STL).
#include <iostream>
using namespace std;

const int MAX = 20;
const int MAXV = MAX * MAX;
const int MAXGRAU = 4 * MAX;     // limite seguro de vizinhos por casa

int t;
int adj[MAXV][MAXGRAU];
int grau[MAXV];

int idVertice(int l, int c) { return (l - 1) * t + (c - 1); }

// Monta o grafo de uma peca que desliza nas 4 direcoes dadas ate a borda
void montarGrafo(const int dl[4], const int dc[4]) {
    for (int l = 1; l <= t; l++)
        for (int c = 1; c <= t; c++) {
            int v = idVertice(l, c);
            grau[v] = 0;
            for (int k = 0; k < 4; k++) {
                int nl = l + dl[k], nc = c + dc[k];
                while (nl >= 1 && nl <= t && nc >= 1 && nc <= t) {
                    adj[v][grau[v]++] = idVertice(nl, nc);
                    nl += dl[k];
                    nc += dc[k];
                }
            }
        }
}

bool ehVizinho(int v, int w) {
    for (int i = 0; i < grau[v]; i++)
        if (adj[v][i] == w) return true;
    return false;
}

void exibir(const char* nome, char simbolo, int l, int c) {
    int v = idVertice(l, c);
    cout << "\n" << nome << " em (" << l << "," << c << ") - grau " << grau[v] << "\nAdjacentes: ";
    for (int i = 0; i < grau[v]; i++) {
        int w = adj[v][i];
        cout << "(" << w / t + 1 << "," << w % t + 1 << ")";
        if (i < grau[v] - 1) cout << ", ";
    }
    cout << "\n\n    ";
    for (int j = 1; j <= t; j++) { if (j < 10) cout << ' '; cout << j << ' '; }
    cout << '\n';
    for (int i = 1; i <= t; i++) {
        if (i < 10) cout << ' ';
        cout << i << "  ";
        for (int j = 1; j <= t; j++) {
            int w = idVertice(i, j);
            char s = (w == v) ? simbolo : (ehVizinho(v, w) ? 'X' : '.');
            cout << ' ' << s << ' ';
        }
        cout << '\n';
    }
}

int main() {
    cout << "Tamanho do tabuleiro (t, ate " << MAX << "): ";
    cin >> t;
    if (t < 1 || t > MAX) { cout << "Tamanho invalido.\n"; return 1; }

    int l, c;
    cout << "Posicao da peca (linha coluna): ";
    cin >> l >> c;
    if (l < 1 || l > t || c < 1 || c > t) { cout << "Posicao fora do tabuleiro.\n"; return 1; }

    int diagL[4] = {-1, -1, 1, 1}, diagC[4] = {-1, 1, -1, 1};   // bispo
    int retaL[4] = {-1, 1, 0, 0},  retaC[4] = {0, 0, -1, 1};    // torre

    montarGrafo(diagL, diagC);
    exibir("BISPO", 'B', l, c);

    montarGrafo(retaL, retaC);
    exibir("TORRE", 'T', l, c);
    return 0;
}
