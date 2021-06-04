#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000

int ST[4 * MAXN], l, r;

int Collatz(long long n) {
    int ciclo = 1;
    while (n != 1) {
        n = n % 2 ? 3 * n + 1 : n / 2;
        ciclo++;
    }
    return ciclo;
}

void Crear(int i, int j, int nodo) {
    if (i == j)
        ST[nodo] = Collatz(i);
    else {
        int m = (i + j) / 2, izq = 2 * nodo + 1, der = 2 * nodo + 2;
        Crear(i, m, izq);
        Crear(m + 1, j, der);
        ST[nodo] = max(ST[izq], ST[der]);
    }
}

int Consulta(int i, int j, int nodo) {
    if (r < i || j < l)
        return 0;
    else if (l <= i && j <= r)
        return ST[nodo];
    else {
        int m = (i + j) / 2, izq = 2 * nodo + 1, der = 2 * nodo + 2;
        return max(Consulta(i, m, izq), Consulta(m + 1, j, der));
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    Crear(1, MAXN - 1, 0);
    while (cin >> l >> r) {
        cout << l << " " << r << " ";
        if (l > r)
            swap(l, r);
        cout << Consulta(1, MAXN - 1, 0) << "\n";
    }
}
