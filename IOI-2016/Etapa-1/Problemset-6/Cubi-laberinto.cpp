#include <bits/stdc++.h>
using namespace std;

struct pos {
    int x, y, z, t;
};

int N, K;
int Sx, Sy, Sz;
bool visitado[100][100][100];
string mov[100][100][100];

queue<pos> cola;
void Busqueda(pos q) {
    cola.pop();

    if (q.x < 0 || q.x >= N || q.y < 0 || q.y >= N || q.z < 0 || q.z >= N || visitado[q.x][q.y][q.z])
        return;
    visitado[q.x][q.y][q.z] = true;

    if (q.x == Sx && q.y == Sy && q.z == Sz) {
        cout << q.t / 2.0;
        exit(0);
    }

    for (int i = 0; i < mov[q.x][q.y][q.z].size(); i++)
        switch (mov[q.x][q.y][q.z][i]) {
            case 'N': cola.push(pos {q.x, q.y + 1, q.z, q.t + 1}); break;
            case 'O': cola.push(pos {q.x - 1, q.y, q.z, q.t + 1}); break;
            case 'S': cola.push(pos {q.x, q.y - 1, q.z, q.t + 1}); break;
            case 'E': cola.push(pos {q.x + 1, q.y, q.z, q.t + 1}); break;
            case 'U': cola.push(pos {q.x, q.y, q.z + 1, q.t + 1}); break;
            case 'D': cola.push(pos {q.x, q.y, q.z - 1, q.t + 1});
        }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> K;
    cin >> Sx >> Sy >> Sz;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                cin >> mov[i][j][k];

    cola.push(pos {0, 0, 0, 0});
    while (!cola.empty() && cola.front().t <= 2 * K)
        Busqueda(cola.front());

    cout << "Impossibru";
}
