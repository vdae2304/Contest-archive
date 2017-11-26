#include <bits/stdc++.h>
using namespace std;

struct pos {
    long long pista, t;
};

int N;
set<long long> visitado;
queue<pos> cola;

void Busqueda(pos q) {
    cola.pop();

    if (!q.pista) {
        cout << q.t;
        exit(0);
    }

    for (int i = 1; i < N - 1; i++)
        for (int j = 1; j < N - 1; j++) {
            pos p = {q.pista, q.t + 1};

            for (int x = -1; x <= 1; x++)
                for (int y = -1; y <= 1; y++)
                    if (x || y)
                        p.pista ^= 1ll << (N * (i + x) + j + y);

            if (visitado.find(p.pista) == visitado.end()) {
                visitado.insert(p.pista);
                cola.push(p);
            }
        }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    pos q = {0, 0};
    cin >> N;

    for (int i = 0, x; i < N * N; i++) {
        cin >> x;
        if (x)
            q.pista |= 1ll << i;
    }

    cola.push(q);
    visitado.insert(q.pista);
    while (!cola.empty())
        Busqueda(cola.front());
}
