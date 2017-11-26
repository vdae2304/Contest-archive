#include <bits/stdc++.h>
using namespace std;

struct pos {
    int i, j, t;
};

int N, M, Ai, Aj, Bi, Bj;
bool Mapa[50][50];

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> Mapa[i][j];

    cin >> Ai >> Aj >> Bi >> Bj;

    queue<pos> cola;
    cola.push(pos {Ai, Aj, 1});

    while (cola.front().i != Bi || cola.front().j != Bj) {
        pos q = cola.front();
        cola.pop();

        if (q.i < 0 || q.i >= N || q.j < 0 || q.j >= M || Mapa[q.i][q.j])
            continue;
        Mapa[q.i][q.j] = 1;

        cola.push(pos {q.i - 1, q.j, q.t + 1});
        cola.push(pos {q.i, q.j - 1, q.t + 1});
        cola.push(pos {q.i, q.j + 1, q.t + 1});
        cola.push(pos {q.i + 1, q.j, q.t + 1});
    }

    cout << cola.front().t;
}
