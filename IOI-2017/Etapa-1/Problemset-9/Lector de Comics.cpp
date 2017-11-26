#include <bits/stdc++.h>
using namespace std;

struct pos {
    int i, j, k, t;
};

int F, C, N, M;
char Mapa[201][201];
int Comic[201][201];
bool visitado[201][201][202];

bool valido(pos q) {
    return 0 < q.i && q.i <= F && 0 < q.j && q.j <= C && Mapa[q.i][q.j] == '_' && !visitado[q.i][q.j][q.k];
}

queue<pos> cola;
int mov[2][4] = {{-1, 0, 0, 1}, {0, -1, 1, 0}};

void Busqueda(pos q) {
    cola.pop();

    if (q.k == N + 1) {
        cout << q.t;
        exit(0);
    }

    for (int i = 0; i < 4; i++) {
        pos p = {q.i + mov[0][i], q.j + mov[1][i], q.k, q.t + 1};
        if (valido(p)) {
            visitado[p.i][p.j][p.k] = true;
            if (Comic[q.i][q.j] == p.k || Comic[p.i][p.j] == p.k)
                visitado[p.i][p.j][++p.k] = true;
            cola.push(p);
        }
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    pos q = {0, 0, 1, 0};
    cin >> F >> C >> N >> M;
    cin >> q.i >> q.j;

    for (int i = 1; i <= F; i++)
        for (int j = 1; j <= C; j++)
            cin >> Mapa[i][j];

    for (int i = 0; i < M; i++) {
        int f, c, k;
        cin >> f >> c >> k;
        Comic[f][c] = k;
    }

    cola.push(q);
    visitado[q.i][q.j][q.k] = true;
    while (!cola.empty())
        Busqueda(cola.front());
}
