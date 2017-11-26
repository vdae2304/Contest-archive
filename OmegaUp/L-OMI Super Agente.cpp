#include <bits/stdc++.h>
#define i first
#define j second
using namespace std;

int N, M;
char Mapa[2000][2000];
queue<pair<int, int> > cola;

int Busqueda() {
    int dist = -2;

    while (!cola.empty()) {
        int l = cola.size();
        dist++;

        for (int i = 0; i < l; i++) {
            pair<int, int> q = cola.front();
            cola.pop();

            if (q.i < 0 || q.i >= N || q.j < 0 || q.j >= M || Mapa[q.i][q.j] == '#')
                continue;
            Mapa[q.i][q.j] = '#';

            cola.push(make_pair(q.i - 1, q.j));
            cola.push(make_pair(q.i, q.j - 1));
            cola.push(make_pair(q.i, q.j + 1));
            cola.push(make_pair(q.i + 1, q.j));
        }
    }

    return dist;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> Mapa[i][j];
            if (Mapa[i][j] == 'G')
                cola.push(make_pair(i, j));
        }

    cout << Busqueda();
}
