#include <bits/stdc++.h>
using namespace std;

struct pos {
    int x;
    string s;
};

int N, M;
int Mapa[4][4];
bool visitado[1 << 16];

int indice(int i, int j) {
    return M * i + j;
}

void mover(int &x, int a, int b, int i, int j) {
    if (0 <= a && a < N && 0 <= b && b < M)
        x |= bool(x & (1 << indice(i, j))) << indice(a, b);
    x &= ~(1 << indice(i, j));
}

queue<pos> cola;
int mov[2][4] = {{-1, 0, 0, 1}, {0, -1, 1, 0}};
int pared[4] = {1, 8, 2, 4};
string dir = "NOES";

void Busqueda(pos q) {
    cola.pop();

    if (!q.x) {
        cout << q.s;
        exit(0);
    }

    for (int k = 0; k < 2; k++) {
        pos p = q;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (!(Mapa[i][j] & pared[k]))
                    mover(p.x, i + mov[0][k], j + mov[1][k], i, j);

        if (!visitado[p.x]) {
            visitado[p.x] = true;
            p.s.push_back(dir[k]);
            cola.push(p);
        }
    }

    for (int k = 2; k < 4; k++) {
        pos p = q;
        for (int i = N - 1; i >= 0; i--)
            for (int j = M - 1; j >= 0; j--)
                if (!(Mapa[i][j] & pared[k]))
                    mover(p.x, i + mov[0][k], j + mov[1][k], i, j);

        if (!visitado[p.x]) {
            visitado[p.x] = true;
            p.s.push_back(dir[k]);
            cola.push(p);
        }
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> Mapa[i][j];

    cola.push(pos {(1 << (N * M)) - 1, ""});
    visitado[cola.front().x] = true;

    while (!cola.empty())
        Busqueda(cola.front());
}
