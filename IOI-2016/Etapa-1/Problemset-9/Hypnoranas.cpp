#include <bits/stdc++.h>
using namespace std;

struct pos {
    int Ki, Kj, Gi, Gj, Kt, Gt, t;
};

int N, M;
int Si, Sj;
char Mapa[20][20];
bool visitado[20][20][20][20][6][6];

bool valido(int i, int j) {
    return 0 <= i && i < N && 0 <= j && j < M && Mapa[i][j] != '#';
}

queue<pos> cola;
int mov[2][4] = {{-1, 0, 0, 1}, {0, -1, 1, 0}};

void Busqueda(pos q) {
    cola.pop();

    if (q.Ki == Si && q.Kj == Sj && q.Gi == Si && q.Gj == Sj) {
        cout << q.t;
        exit(0);
    }

    for (int i = 0; i < 4; i++) {
        int x = q.Ki, y = q.Kj;
        if (!q.Kt)
            x += mov[0][i], y += mov[1][i];

        if (valido(x, y))
            for (int j = 0; j < 4; j++) {
                int a = q.Gi, b = q.Gj;
                if (!q.Gt)
                    a += mov[0][j], b += mov[1][j];

                if (valido(a, b)) {
                    int t1 = q.Kt ? q.Kt - 1 : Mapa[x][y];
                    int t2 = q.Gt ? q.Gt - 1 : Mapa[a][b];

                    if (!visitado[x][y][a][b][t1][t2]) {
                        cola.push(pos {x, y, a, b, t1, t2, q.t + 1});
                        visitado[x][y][a][b][t1][t2] = true;
                    }
                }
            }
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    pos q;
    q.Kt = q.Gt = q.t = 0;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> Mapa[i][j];
            if (Mapa[i][j] == 'K') {
                q.Ki = i, q.Kj = j;
                Mapa[i][j] = 0;
            }
            else if (Mapa[i][j] == 'G') {
                q.Gi = i, q.Gj = j;
                Mapa[i][j] = 0;
            }
            else if (Mapa[i][j] == 'S') {
                Si = i, Sj = j;
                Mapa[i][j] = 0;
            }
            else if (Mapa[i][j] == '.')
                Mapa[i][j] = 0;
            else if (Mapa[i][j] != '#')
                Mapa[i][j] -= '0';
        }

    cola.push(q);
    visitado[q.Ki][q.Kj][q.Gi][q.Gj][q.Kt][q.Gt] = true;
    while (!cola.empty())
        Busqueda(cola.front());

    cout << "-1";
}
