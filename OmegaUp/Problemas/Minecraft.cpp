#include <bits/stdc++.h>
using namespace std;

struct pos {
    int i, j, t;
};

bool operator < (pos a, pos b) {
    return a.t > b.t;
}

int M, N;
int Si, Sj, Fi, Fj;
char Mapa[501][501];
priority_queue<pos> cola;

void Busqueda(pos q) {
    cola.pop();

    if (q.i < 1 || q.i > N || q.j < 1 || q.j > M || Mapa[q.i][q.j] == '#')
        return;

    q.t += Mapa[q.i][q.j];
    Mapa[q.i][q.j] = '#';

    if (q.i == Fi && q.j == Fj) {
        cout << q.t;
        exit(0);
    }

    cola.push(pos {q.i - 1, q.j, q.t});
    cola.push(pos {q.i, q.j - 1, q.t});
    cola.push(pos {q.i, q.j + 1, q.t});
    cola.push(pos {q.i + 1, q.j, q.t});
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> M;
    cin >> Si >> Sj >> Fi >> Fj;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) {
            cin >> Mapa[i][j];
            if (Mapa[i][j] == '.')
                Mapa[i][j] = 1;
            else if (isdigit(Mapa[i][j]))
                Mapa[i][j] -= '0' - 1;
        }

    cola.push(pos {Si, Sj, -1});
    while (!cola.empty())
        Busqueda(cola.top());
}
