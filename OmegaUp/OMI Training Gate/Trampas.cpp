#include <bits/stdc++.h>
using namespace std;

struct pos {
    int i, j, t;
};

bool operator < (pos a, pos b) {
    return a.t > b.t;
}

int N, M;
char Mapa[300][300];
priority_queue<pos> cola;

void Busqueda(pos q) {
    cola.pop();
    if (q.i < 0 || q.i >= N || q.j < 0 || q.j >= M || Mapa[q.i][q.j] == '#')
        return;

    if (Mapa[q.i][q.j] == 'S') {
        cout << q.t;
        exit(0);
    }
    if (Mapa[q.i][q.j] == 'x')
        q.t++;

    Mapa[q.i][q.j] = '#';
    cola.push(pos {q.i - 1, q.j, q.t});
    cola.push(pos {q.i, q.j - 1, q.t});
    cola.push(pos {q.i, q.j + 1, q.t});
    cola.push(pos {q.i + 1, q.j, q.t});
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int Xi, Yi;
    cin >> N >> M >> Xi >> Yi;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> Mapa[i][j];

    cola.push(pos {Xi - 1, Yi - 1, 0});
    while (!cola.empty())
        Busqueda(cola.top());
}
