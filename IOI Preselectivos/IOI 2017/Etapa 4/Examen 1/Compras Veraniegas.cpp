#include <bits/stdc++.h>
using namespace std;
#define MAXN 200000

int N, Q, l, r;
long long ST[4 * MAXN], v[MAXN], d;

void Build(int i, int j, int nodo) {
    if (i == j)
        ST[nodo] = v[i];
    else {
        int m = (i + j) / 2, izq = 2 * nodo + 1, der = 2 * nodo + 2;
        Build(i, m, izq);
        Build(m + 1, j, der);
        ST[nodo] = min(ST[izq], ST[der]);
    }
}

int Query(int i, int j, int nodo) {
    if (j < l || r < i || ST[nodo] > d)
        return -1;
    if (i == j)
        return i;
    int m = (i + j) / 2, izq = 2 * nodo + 1, der = 2 * nodo + 2;
    int tmp = Query(i, m, izq);
    return tmp != -1 ? tmp : Query(m + 1, j, der);
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> Q;

    for (int i = 0; i < N; i++)
        cin >> v[i];
    Build(0, N - 1, 0);

    while (Q--) {
        cin >> d >> l >> r;
        l--; r--;

        while (l != -1) {
            d %= v[l];
            l = Query(0, N - 1, 0);
        }

        cout << d << "\n";
    }
}
