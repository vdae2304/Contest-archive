#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000001

int N, ST[4 * MAXN];
long long K, fact[MAXN];

void Factorial() {
    fact[0] = 1;
    for (int i = 1; i <= 20; i++)
        fact[i] = fact[i - 1] * i;
    for (int i = 21; i < MAXN; i++)
        fact[i] = fact[20];
}

int Crear(int i, int j, int nodo) {
    int m = (i + j) / 2, izq = 2 * nodo + 1, der = 2 * nodo + 2;
    return ST[nodo] = (i == j) ? 1 : Crear(i, m, izq) + Crear(m + 1, j, der);
}

int NumEnPosicion(int x, int i, int j, int nodo) {
    int m = (i + j) / 2, izq = 2 * nodo + 1, der = 2 * nodo + 2;
    ST[nodo]--;
    if (i == j)
        return i + 1;
    else if (x <= ST[izq])
        return NumEnPosicion(x, i, m, izq);
    else
        return NumEnPosicion(x - ST[izq], m + 1, j, der);
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> K;

    Factorial();
    Crear(0, N - 1, 0);

    for (int i = 1; i <= N; i++) {
        int j = (K + fact[N - i] - 1) / fact[N - i];
        cout << NumEnPosicion(j, 0, N - 1, 0) << " ";
        K -= (j - 1) * fact[N - i];
    }
}
