#include <bits/stdc++.h>
using namespace std;

struct pos {
    int x, y, t;
};

int M, N, K;
int Xi, Yi, Xf, Yf;
int mov[2][10];
bool visitado[1001][1001];

int Busqueda() {
    queue<pos> c;
    visitado[Xi][Yi] = true;
    c.push(pos {Xi, Yi, 0});

    while (!c.empty()) {
        pos p = c.front();
        c.pop();

        if (p.x == Xf && p.y == Yf)
            return p.t;

        for (int i = 0; i < K; i++) {
            pos q = {p.x + mov[0][i], p.y + mov[1][i], p.t + 1};
            if (0 < q.x && q.x <= M && 0 < q.y && q.y <= N && !visitado[q.x][q.y]) {
                c.push(q);
                visitado[q.x][q.y] = true;
            }
        }
    }

    return -1;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> M >> N >> K >> Xi >> Yi >> Xf >> Yf;

    for (int i = 0; i < K; i++)
        cin >> mov[0][i] >> mov[1][i];

    cout << Busqueda();
}
