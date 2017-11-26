#include <bits/stdc++.h>
using namespace std;

struct pos {
    int i, j, t;
};

int N;
char Mapa[50][50];
bool visitado[50][50][50];

queue<pos> cola;
int mov[2][4] = {{-1, 0, 0, 1}, {0, -1, 1, 0}};

void Busqueda(pos q) {
    cola.pop();

    if (q.i < 0 || q.i >= N || q.j < 0 || q.j >= N || Mapa[q.i][q.j] == '#')
        return;
    if (visitado[q.i][q.j][q.t % N] || (isdigit(Mapa[q.i][q.j]) && !(q.t % (Mapa[q.i][q.j] - '0'))))
        return;
    visitado[q.i][q.j][q.t % N] = true;

    if (q.i == N - 1 && q.j == N - 1) {
        cout << q.t;
        exit(0);
    }

    cola.push(pos {q.i, q.j, q.t + 1});
    for (int i = 0; i < 4; i++)
        cola.push(pos {q.i + mov[0][i], q.j + mov[1][i], q.t + 1});
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> Mapa[i][j];

    cola.push(pos {0, 0, 1});
    while (!cola.empty())
        Busqueda(cola.front());

    cout << "-1";
}
