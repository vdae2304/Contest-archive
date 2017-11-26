#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define MAXN 500000

int N, Q;
int v[MAXN], l, r;
vector<pii> ST[4 * MAXN];

void Union(vector<pii> &a, vector<pii> &b, vector<pii> &c) {
    for (int i = 0, j = 0; i < a.size() || j < b.size(); ) {
        if (i < a.size() && j < b.size() && a[i].first == b[j].first) {
            c.push_back(pii(a[i].first, a[i].second + b[j].second));
            i++;
            j++;
        }
        else if (i < a.size() && (j >= b.size() || a[i].first < b[j].first))
            c.push_back(a[i++]);
        else
            c.push_back(b[j++]);
    }
}

void Crear(int i, int j, int nodo) {
    if (i == j)
        ST[nodo].push_back(pii(v[i], 1));
    else {
        int m = (i + j) / 2, izq = 2 * nodo + 1, der = 2 * nodo + 2;
        Crear(i, m, izq);
        Crear(m + 1, j, der);
        Union(ST[izq], ST[der], ST[nodo]);
    }
}

vector<pii> Pregunta(int i, int j, int nodo) {
    int m = (i + j) / 2, izq = 2 * nodo + 1, der = 2 * nodo + 2;
    if (r < i || j < l)
        return vector<pii>();
    else if (l <= i && j <= r)
        return ST[nodo];
    else {
        vector<pii> a = Pregunta(i, m, izq), b = Pregunta(m + 1, j, der), c;
        Union(a, b, c);
        return c;
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> Q;

    for (int i = 0; i < N; i++)
        cin >> v[i];
    Crear(0, N - 1, 0);

    while (Q--) {
        cin >> l >> r;

        int ans = 0;
        l--; r--;
        vector<pii> aux = Pregunta(0, N - 1, 0);

        for (int i = 0; i < aux.size(); i++) 
            if (aux[i].second == 2)
                ans++;        

        cout << ans << "\n";
    }
}
