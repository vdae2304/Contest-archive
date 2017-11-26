#include <bits/stdc++.h>
using namespace std;

struct pos {
    char i;
    int k;
};

bool operator < (pos a, pos b) {
    return a.k > b.k;
}

int N;
char meta;
string ruta[255];
bool visitado[255][1001];

priority_queue<pos> cola;
void Busqueda(pos q) {
    cola.pop();

    if (q.i == meta) {
        cout << q.k;
        exit(0);
    }

    for (int i = 0; i < ruta[q.i].size(); i++) {
        int x = 1;
        if (isupper(q.i))
            for (int j = 1; ; j++)
                if (j == (q.k + j + 19) / 20) {
                    x = j;
                    break;
                }

        pos p = {ruta[q.i][i], q.k + x};
        if (!visitado[p.i][p.k]) {
            visitado[p.i][p.k] = true;
            cola.push(p);
        }
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    pos q;
    cin >> N;

    for (int i = 0; i < N; i++) {
        char a, b;
        cin >> a >> b;
        ruta[a].push_back(b);
        ruta[b].push_back(a);
    }
    cin >> q.k >> meta >> q.i;

    cola.push(q);
    visitado[q.i][q.k] = true;
    while (!cola.empty())
        Busqueda(cola.top());
}
