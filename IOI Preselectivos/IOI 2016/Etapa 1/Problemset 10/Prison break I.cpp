#include <bits/stdc++.h>
using namespace std;

struct pos {
    int pi, pj, qi, qj, t;
};

int N, M, K;
char Mapa[100][100];
bool visitado[100][100][100][100];

bool valido(pos &q) {
    if (q.pi < 0 || q.pi >= N || q.pj < 0 || q.pj >= M || Mapa[q.pi][q.pj] == '#')
        return false;
    if (q.qi < 0 || q.qi >= N || q.qj < 0 || q.qj >= M || Mapa[q.qi][q.qj] == '#')
        return false;
    if (abs(q.pi - q.qi) + abs(q.pj - q.qj) > K || visitado[q.pi][q.pj][q.qi][q.qj])
        return false;
    visitado[q.pi][q.pj][q.qi][q.qj] = true;
    return true;
}

queue<pos> cola;
int mov[2][4] = {{-1, 0, 0, 1}, {0, -1, 1, 0}};

void Busqueda(pos q) {
    cola.pop();

    if (Mapa[q.pi][q.pj] == 'x' && Mapa[q.qi][q.qj] == 'x') {
        cout << q.t;
        exit(0);
    }

    for (int i = 0; i < 4; i++) {
        pos p = pos {q.pi + mov[0][i], q.pj + mov[1][i], q.qi, q.qj, q.t + 1};
        if (valido(p))
            cola.push(p);
    }
    for (int i = 0; i < 4; i++) {
        pos p = pos {q.pi, q.pj, q.qi + mov[0][i], q.qj + mov[1][i], q.t + 1};
        if (valido(p))
            cola.push(p);
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    pos q; q.t = 0;
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> Mapa[i][j];
            if (Mapa[i][j] == 'p')
                q.pi = i, q.pj = j;
            else if (Mapa[i][j] == 'q')
                q.qi = i, q.qj = j;
        }

    cola.push(q);
    visitado[q.pi][q.pj][q.qi][q.qj] = true;
    while (!cola.empty())
        Busqueda(cola.front());
    cout << "-1";
}
