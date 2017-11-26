#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000

int N, Q, a, b;
int v[MAXN], ST[20 * MAXN];
int freq[2 * MAXN], ini[2 * MAXN];

void Crear(int i, int j, int nodo) {
    if (i == j)
        ST[nodo] = freq[v[i]];
    else {
        int m = (i + j) / 2, izq = 2 * nodo + 1, der = 2 * nodo + 2;
        Crear(i, m, izq);
        Crear(m + 1, j, der);
        ST[nodo] = max(ST[izq], ST[der]);
    }
}

int Pregunta(int i, int j, int nodo) {
    if (j < a || b < i)
        return -1;
    if (a <= i && j <= b)
        return ST[nodo];
    int m = (i + j) / 2;
    return max(Pregunta(i, m, 2 * nodo + 1), Pregunta(m + 1, j, 2 * nodo + 2));
}

main() {
    scanf("%d %d", &N, &Q);

    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
        v[i] += MAXN;

        freq[v[i]]++;
        if (freq[v[i]] == 1)
            ini[v[i]] = i;
    }
    Crear(0, N - 1, 0);

    while (Q--) {
        scanf("%d %d", &a, &b);
        if (v[--a] == v[--b])
            printf("%d\n", b - a + 1);
        else {
            int ans = max(freq[v[a]] - a + ini[v[a]], b - ini[v[b]] + 1);
            a = ini[v[a]] + freq[v[a]];
            b = ini[v[b]] - 1;
            if (a <= b)
                ans = max(ans, Pregunta(0, N - 1, 0));
            printf("%d\n", ans);
        }
    }
}
