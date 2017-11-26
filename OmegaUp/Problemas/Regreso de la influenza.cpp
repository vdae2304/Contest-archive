#include <bits/stdc++.h>
#define i first
#define j second
using namespace std;

int N, M, K;
int mov[2][4] = {{-1, 0, 0, 1}, {0, -1, 1, 0}};
char Mapa[1000][1000];

bool Infectada(int i, int j) {
    bool infeccion = false;
    Mapa[i][j] = '.';

    queue<pair<int, int> > cola;
    cola.push(make_pair(i, j));

    while (!cola.empty()) {
        pair<int, int> p = cola.front();
        cola.pop();

        for (int k = 0; k < 4; k++) {
            pair<int, int> q = make_pair(p.i + mov[0][k], p.j + mov[1][k]);
            if (0 <=  q.i && q.i < N && 0 <= q.j && q.j < M && Mapa[q.i][q.j] != '.') {
                if (Mapa[q.i][q.j] == 'x')
                    infeccion = true;
                Mapa[q.i][q.j] = '.';
                cola.push(q);
            }
        }
    }

    return infeccion;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> Mapa[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (Mapa[i][j] == 'l' && !Infectada(i, j))
                K++;

    cout << max(K - 1, 0);
}
