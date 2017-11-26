#include <bits/stdc++.h>
using namespace std;

struct point {
    int i, j;
};

int N, Mapa[500][500];
short mov[2][4] = {{-1, 0, 0, 1}, {0, -1, 1, 0}};
bool visitado[500][500];

int calcula(int i, int j, int d) {
    int r = 0;
    visitado[i][j] = true;

    queue<point> c;
    c.push(point {i, j});

    while (!c.empty()) {
        ++r;
        for (int k = 0; k < 4; k++) {
            point q = {c.front().i + mov[0][k], c.front().j + mov[1][k]};

            if (q.i < 0 || q.i >= N || q.j < 0 || q.j >= N || visitado[q.i][q.j] || abs(Mapa[q.i][q.j] - Mapa[c.front().i][c.front().j]) > d)
                continue;

            visitado[q.i][q.j] = true;
            c.push(q);
        }
        c.pop();
    }

    return r;
}

int Busqueda(int a, int b) {
    while (a < b) {
        int m = (a + b) / 2, t = 0;
        memset(visitado, false, sizeof(visitado));

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (!visitado[i][j])
                    t = max(t, calcula(i, j, m));

        if (t >= N * N / 2)
            b = m;
        else
            a = m + 1;
    }
    return a;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;

    int mayor = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            cin >> Mapa[i][j];
            mayor = max(mayor, Mapa[i][j]);
        }

    cout << Busqueda(0, mayor);
}
