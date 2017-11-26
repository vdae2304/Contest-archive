#include <bits/stdc++.h>
using namespace std;
#define MAXN 2000000
typedef pair<int, int> pii;

int N, Q;
int op, l, r, h;
pii Lazy[4 * MAXN], nulo = pii(INT_MAX, 0);

void Combina(int nodo, pii cambio) {
    Lazy[nodo] = pii(max(min(Lazy[nodo].first, cambio.first), cambio.second),
                     min(max(Lazy[nodo].second, cambio.second), cambio.first));
}

void Actualizar(int i, int j, int nodo) {
    if (r < i || j < l)
        return;
    else if (l <= i && j <= r) {
        if (op == 1)
            Lazy[nodo] = pii(max(Lazy[nodo].first, h), max(Lazy[nodo].second, h));
        else
            Lazy[nodo] = pii(min(Lazy[nodo].first, h), min(Lazy[nodo].second, h));
    }
    else {
        int m = (i + j) / 2, izq = 2 * nodo + 1, der = 2 * nodo + 2;
        Combina(izq, Lazy[nodo]);
        Combina(der, Lazy[nodo]);

        Lazy[nodo] = nulo;
        Actualizar(i, m, izq);
        Actualizar(m + 1, j, der);
    }
}

void Consulta(int i, int j, int nodo) {
    if (i == j)
        cout << min(Lazy[nodo].first, Lazy[nodo].second) << " ";
    else {
        int m = (i + j) / 2, izq = 2 * nodo + 1, der = 2 * nodo + 2;
        Combina(izq, Lazy[nodo]);
        Combina(der, Lazy[nodo]);

        Consulta(i, m, izq);
        Consulta(m + 1, j, der);
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> Q;

    while (Q--) {
        cin >> op >> l >> r >> h;
        Actualizar(0, N - 1, 0);
    }

    Consulta(0, N - 1, 0);
}
