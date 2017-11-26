#include <bits/stdc++.h>
#define i first
#define j second
using namespace std;

int N, M, K;
int Mapa[500][500];
bool visitado[500][500];
int mov[2][4] = {{-1, 0, 0, 1}, {0, -1, 1, 0}};

int Nebulosa(int i, int j) {
    int S = 0;
    visitado[i][j] = true;

    queue<pair<int, int> > cola;
    cola.push(make_pair(i, j));

    while (!cola.empty()) {
        pair<int, int> p = cola.front();
        cola.pop();
        S++;

        for (int k = 0; k < 4; k++) {
            pair<int, int> q = make_pair(p.i + mov[0][k], p.j + mov[1][k]);
            if (0 <= q.i && q.i < N && 0 <= q.j && q.j < M && !visitado[q.i][q.j] && Mapa[p.i][p.j] - Mapa[q.i][q.j] <= K) {
                cola.push(q);
                visitado[q.i][q.j] = true;
            }
        }
    }

    return S;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int Pi = 0, Pj = 0;
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> Mapa[i][j];
            if (Mapa[i][j] > Mapa[Pi][Pj])
                Pi = i, Pj = j;
        }

    cout << Nebulosa(Pi, Pj);
}
