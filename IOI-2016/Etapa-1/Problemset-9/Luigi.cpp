#include <bits/stdc++.h>
using namespace std;

struct pos {
    int Mi, Mj, Li, Lj, t;
};

int N;
char Mapa[50][50];
bool visitado[50][50][50][50];

bool valido(pos &q) {
    if (visitado[q.Mi][q.Mj][q.Li][q.Lj])
        return false;
    if (Mapa[q.Mi][q.Mj] == '#' || Mapa[q.Li][q.Lj] == '#')
        return false;
    if (Mapa[q.Mi][q.Mj] == '*' && Mapa[q.Li][q.Lj] != 'B')
        return false;
    if (Mapa[q.Li][q.Lj] == '*' && Mapa[q.Mi][q.Mj] != 'B')
        return false;
    visitado[q.Mi][q.Mj][q.Li][q.Lj] = true;
    return true;
}

queue<pos> cola;
int mov[2][4] = {{-1, 0, 0, 1}, {0, -1, 1, 0}};

void Busqueda(pos q) {
    cola.pop();

    if (Mapa[q.Mi][q.Mj] == 'S' && Mapa[q.Li][q.Lj] == 'S') {
        cout << q.t;
        exit(0);
    }

    for (int i = 0; i < 4; i++) {
        pos p = pos {q.Mi + mov[0][i], q.Mj + mov[1][i], q.Li, q.Lj, q.t + 1};
        if (valido(p))
            cola.push(p);
    }
    for (int i = 0; i < 4; i++) {
        pos p = pos {q.Mi, q.Mj, q.Li + mov[0][i], q.Lj + mov[1][i], q.t + 1};
        if (valido(p))
            cola.push(p);
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    pos q; q.t = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            cin >> Mapa[i][j];
            if (Mapa[i][j] == 'M')
                q.Mi = i, q.Mj = j;
            else if (Mapa[i][j] == 'L')
                q.Li = i, q.Lj = j;
        }

    cola.push(q);
    visitado[q.Mi][q.Mj][q.Li][q.Lj] = true;
    while (!cola.empty())
        Busqueda(cola.front());
}
