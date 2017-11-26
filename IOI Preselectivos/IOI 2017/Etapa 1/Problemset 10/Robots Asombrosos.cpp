#include <bits/stdc++.h>
using namespace std;

struct pos {
    int x[2], y[2];
    string s;
};

int N[2], M[2], G[2];
char Mapa[2][22][22];
pair<int, int> guardia[2][10][12];

queue<pos> cola;
bool visitado[22][22][22][22][12];
int mov[2][4] = {{-1, 0, 0, 1}, {0, -1, 1, 0}};
string dir = "NOES";

void iniciarGuardia(int i, int j, int x, int y, int steps, char c) {
    int d;
    for (d = 0; dir[d] != c; d++);
    guardia[i][j][0] = make_pair(x, y);
    for (int t = 1, op = 1; t < 12; op *= -1)
        for (int k = 0; k < steps; k++) {
            guardia[i][j][t] = make_pair(guardia[i][j][t - 1].first + op * mov[0][d], guardia[i][j][t - 1].second + op * mov[1][d]);
            t++;
        }
}

bool dentro(pos &q, int i) {
    return Mapa[i][q.x[i]][q.y[i]];
}

bool valido(pos &q, pos &p) {
    for (int i = 0; i < 2; i++) {
        pair<int, int> a = make_pair(q.x[i], q.y[i]), b = make_pair(p.x[i], p.y[i]);
        for (int j = 0; j < G[i]; j++)
            if (guardia[i][j][p.s.size() % 12] == b || (guardia[i][j][p.s.size() % 12] == a && guardia[i][j][q.s.size() % 12] == b))
                return false;
    }
    return true;
}

pos Mover(pos q, int j) {
    q.s.push_back(dir[j]);
    for (int i = 0; i < 2; i++)
        if (dentro(q, i) && Mapa[i][q.x[i] + mov[0][j]][q.y[i] + mov[1][j]] != '#')
            q.x[i] += mov[0][j], q.y[i] += mov[1][j];
    return q;
}

void Busqueda(pos q) {
    cola.pop();

    if (!dentro(q, 0) && !dentro(q, 1)) {
        cout << q.s.size() << "\n";
        for (int i = 0; i < q.s.size(); i++)
            cout << q.s[i] << "\n";
        exit(0);
    }

    for (int i = 0; i < 4; i++) {
        pos p = Mover(q, i);
        if (valido(q, p) && !visitado[p.x[0]][p.y[0]][p.x[1]][p.y[1]][p.s.size() % 12]) {
            visitado[p.x[0]][p.y[0]][p.x[1]][p.y[1]][p.s.size() % 12] = true;
            cola.push(p);
        }
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int x, y, steps; char l;
    pos q;

    for (int k = 0; k < 2; k++) {
        cin >> N[k] >> M[k];

        for (int i = 1; i <= N[k]; i++)
            for (int j = 1; j <= M[k]; j++) {
                cin >> Mapa[k][i][j];
                if (Mapa[k][i][j] == 'X')
                    q.x[k] = i, q.y[k] = j;
            }

        cin >> G[k];
        for (int i = 0; i < G[k]; i++) {
            cin >> x >> y >> steps >> l;
            iniciarGuardia(k, i, x, y, steps - 1, l);
        }
    }

    cola.push(q);
    visitado[q.x[0]][q.y[0]][q.x[1]][q.y[1]][0] = true;
    while (!cola.empty())
        Busqueda(cola.front());

    cout << "-1\n";
}
