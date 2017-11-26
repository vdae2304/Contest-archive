#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001
#define MOD 1000000007

struct nodo {
    int freq[26];
};

int N, Q, op, l, r, t;
string s;

nodo ST[4 * MAXN], nulo;
int Lazy[4 * MAXN], pot[MAXN];

nodo Une(nodo a, nodo b) {
    for (int i = 0; i < 26; i++)
        a.freq[i] += b.freq[i];
    return a;
}

void Crear(int i, int j, int actual) {
    if (i == j)
        ST[actual].freq[s[i] - 'a'] = 1;
    else {
        int m = (i + j) / 2, izq = 2 * actual + 1, der = 2 * actual + 2;
        Crear(i, m, izq);
        Crear(m + 1, j, der);
        ST[actual] = Une(ST[izq], ST[der]);
    }
}

void Propaga(int len, int actual, int c) {
    nodo aux = ST[actual];
    for (int i = 0; i < 26; i++)
        ST[actual].freq[(i + c) % 26] = aux.freq[i];

    if (len) {
        Lazy[2 * actual + 1] = (Lazy[2 * actual + 1] + c) % 26;
        Lazy[2 * actual + 2] = (Lazy[2 * actual + 2] + c) % 26;
    }
    Lazy[actual] = 0;
}

void Actualiza(int i, int j, int actual) {
    int m = (i + j) / 2, izq = 2 * actual + 1, der = 2 * actual + 2;
    if (Lazy[actual])
        Propaga(j - i, actual, Lazy[actual]);

    if (r < i || j < l)
        return;
    else if (l <= i && j <= r)
        Propaga(j - i, actual, t % 26);
    else {
        Actualiza(i, m, izq);
        Actualiza(m + 1, j, der);
        ST[actual] = Une(ST[izq], ST[der]);
    }
}

nodo Pregunta(int i, int j, int actual) {
    int m = (i + j) / 2, izq = 2 * actual + 1, der = 2 * actual + 2;
    if (Lazy[actual])
        Propaga(j - i, actual, Lazy[actual]);

    if (r < i || j < l)
        return nulo;
    else if (l <= i && j <= r)
        return ST[actual];
    else
        return Une(Pregunta(i, m, izq), Pregunta(m + 1, j, der));
}

int Cuenta(nodo a) {
    long long total = 1, no_cero = 1;
    for (int i = 0; i < 26; i++)
        if (a.freq[i]) {
            no_cero++;
            total = (total * pot[a.freq[i] - 1]) % MOD;
        }
    return (total * no_cero - 1) % MOD;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> Q >> s;
    Crear(0, N - 1, 0);

    pot[0] = 1;
    for (int i = 1; i <= N; i++)
        pot[i] = (2 * pot[i - 1]) % MOD;

    while (Q--) {
        cin >> op >> l >> r;
        if (op == 1) {
            cin >> t;
            Actualiza(0, N - 1, 0);
        }
        else
            cout << Cuenta(Pregunta(0, N - 1, 0)) << "\n";
    }
}
