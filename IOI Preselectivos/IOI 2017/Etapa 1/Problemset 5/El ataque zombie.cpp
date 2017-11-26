#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000

struct pos {
    int i, j, t;
};

int N, M, answer;
int dist[MAXN][MAXN];
bool visitado[MAXN][MAXN];
char Mapa[MAXN][MAXN];

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    queue<pos> cola;
    cin >> N >> M;

    int Pi, Pj;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> Mapa[i][j];
            if (Mapa[i][j] == 'S')
                cola.push(pos {i, j, 0});
            else if (Mapa[i][j] == 'P')
                Pi = i, Pj = j;
        }

    while (!cola.empty()) {
        pos q = cola.front();
        cola.pop();

        if (q.i < 0 || q.i >= N || q.j < 0 || q.j >= M)
            continue;
        if (visitado[q.i][q.j] || Mapa[q.i][q.j] == '#')
            continue;
        visitado[q.i][q.j] = true;

        dist[q.i][q.j] = q.t;
        cola.push(pos {q.i - 1, q.j, q.t + 1});
        cola.push(pos {q.i, q.j - 1, q.t + 1});
        cola.push(pos {q.i, q.j + 1, q.t + 1});
        cola.push(pos {q.i + 1, q.j, q.t + 1});
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if ('0' < Mapa[i][j] && Mapa[i][j] <= '9' && dist[i][j] && dist[i][j] <= dist[Pi][Pj])
                answer += Mapa[i][j] - '0';

    cout << answer;
}
