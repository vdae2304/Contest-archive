#include <bits/stdc++.h>
using namespace std;

struct pos {
    int i, j, b[3];
    string s;
};

int N, M;
char Mapa[17][17];
bool visitado[17][17][18][18][18];

bool valido(pos &q) {
    if (q.i < 1 || q.i > N || q.j < 1 || q.j > M || Mapa[q.i][q.j] == '#')
        return false;
    if (q.b[0] == -1 || q.b[0] == 16 || q.b[1] == -1 || q.b[1] == 16 || q.b[2] == -1 || q.b[2] == 16)
        return false;
    if (visitado[q.i][q.j][q.b[0]][q.b[1]][q.b[2]])
        return false;
    visitado[q.i][q.j][q.b[0]][q.b[1]][q.b[2]] = true;
    return true;
}

queue<pos> cola;
int mov[2][4] = {{-1, 0, 0, 1}, {0, -1, 1, 0}};
string sig = "NOES";

void Busqueda(pos q) {
    cola.pop();

    if (Mapa[q.i][q.j] == 'a') {
        for (int i = 0; i < 3; i++)
            if (q.b[i] != 17)
                q.b[i]++;
    }
    else if (Mapa[q.i][q.j] == 'd') {
        for (int i = 0; i < 3; i++)
            if (q.b[i] != 17)
                q.b[i]--;
    }
    else if (Mapa[q.i][q.j] <= 3)
        q.b[Mapa[q.i][q.j]] = 17;

    if (q.b[0] == 17 && q.b[1] == 17 && q.b[2] == 17) {
        cout << q.s.size() << "\n" << q.s;
        exit(0);
    }

    for (int i = 0; i < 4; i++) {
        pos p = q;
        p.i += mov[0][i]; p.j += mov[1][i]; p.s.push_back(sig[i]);
        if (valido(p))
            cola.push(p);
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    pos q;
    q.b[0] = q.b[1] = q.b[2] = 17;
    cin >> N >> M;

    for (int i = 1, c = 0; i <= N; i++)
        for (int j = 1; j <= M; j++) {
            cin >> Mapa[i][j];
            if (isdigit(Mapa[i][j])) {
                q.b[c] = Mapa[i][j] - '0';
                Mapa[i][j] = c++;
            }
        }
    cin >> q.i >> q.j;

    cola.push(q);
    visitado[q.i][q.j][q.b[0]][q.b[1]][q.b[2]] = true;
    while (!cola.empty())
        Busqueda(cola.front());
}
