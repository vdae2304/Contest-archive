#include <bits/stdc++.h>
using namespace std;

int N, v[1001];
int izq[1001], der[1001];

void preorden(int nodo) {
    if (!nodo)
        return;
    cout << v[nodo] << " ";
    preorden(izq[nodo]);
    preorden(der[nodo]);
}

void insertar(int prev, int nodo) {
    if (v[nodo] < v[prev]) {
        if (izq[prev])
            insertar(izq[prev], nodo);
        else
            izq[prev] = nodo;
    }
    else {
        if (der[prev])
            insertar(der[prev], nodo);
        else
            der[prev] = nodo;
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> v[i];

    for (int i = N - 1; i; i--)
        insertar(N, i);

    preorden(N);
}
