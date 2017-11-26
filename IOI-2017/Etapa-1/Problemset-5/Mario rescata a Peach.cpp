#include <bits/stdc++.h>
using namespace std;

struct pos {
    int i, j, t;
};

bool operator < (pos a, pos b) {
    return a.t > b.t;
}

int N, M, K;
int Mi, Mj, Pi, Pj;
char Mapa[1000][1000];

priority_queue<pos> cola;
int mov[2][4] = {{-1, 0, 0, 1}, {0, -1, 1, 0}};
void Busqueda(pos q) {
    cola.pop();

    //We finish
    if (Mapa[q.i][q.j] == 'M') {
        cout << q.t;
        exit(0);
    }

    //Already visited
    if (Mapa[q.i][q.j] == 'V')
        return;

    //If we can teleport we do it
    if (Mapa[q.i][q.j] == 'E')
        cola.push(pos {Mi, Mj, q.t + K});

    Mapa[q.i][q.j] = 'V'; //We mark it as visited

    //If we can move we do it
    for (int i = 0; i < 4; i++) {
        pos p = pos {q.i + mov[0][i], q.j + mov[1][i], q.t};
        if (0 <= p.i && p.i < N && 0 <= p.j && p.j < M) {
            p.t += Mapa[p.i][p.j] == '#' ? 2 : 1;
            cola.push(p);
        }
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> Mapa[i][j];
            if (Mapa[i][j] == 'M')
                Mi = i, Mj = j;
            else if (Mapa[i][j] == 'P')
                Pi = i, Pj = j;
        }
    }

    //Do the search from the end to the beginning
    cola.push(pos {Pi, Pj, 0});
    while (!cola.empty())
        Busqueda(cola.top());
}
