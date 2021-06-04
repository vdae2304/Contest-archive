#include <bits/stdc++.h>
using namespace std;

struct pos {
    int x, y, e;
};

bool operator < (pos a, pos b) {
    return a.e > b.e;
}

int N, M, K;
char mapa[1000][1000];
bool visitado[1000][1000];
int dX[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
    dY[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int Busqueda(int Xi, int Yi, int Xf, int Yf) {
    priority_queue<pos> pq;
    pq.push(pos {Xi, Yi, 0});
    memset(visitado, false, sizeof(visitado));

    while (pq.top().x != Xf || pq.top().y != Yf) {
        pos p = pq.top();
        pq.pop();

        if (p.x < 0 || p.x >= N || p.y < 0 || p.y >= M || visitado[p.x][p.y])
            continue;
        visitado[p.x][p.y] = true;

        for (int i = 0; i < 8; i++)
            pq.push(pos {p.x + dX[i], p.y + dY[i], p.e + (mapa[p.x][p.y] - '0' != i)});
    }

    return pq.top().e;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> mapa[i][j];

    cin >> K;
    while (K--) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        cout << Busqueda(a - 1, b - 1, x - 1, y - 1) << "\n";
    }
}
