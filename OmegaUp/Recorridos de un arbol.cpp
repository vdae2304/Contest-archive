#include <bits/stdc++.h>
using namespace std;
#define MAXN 501

int N, izq[MAXN], der[MAXN];
int in[MAXN], post[MAXN], indice;

void Construir(int nodo, int a, int b) {
    int m;
    for (m = a; m <= b && in[m] != nodo; m++);
    if (m + 1 <= b) {
        der[nodo] = post[indice--];
        Construir(der[nodo], m + 1, b);
    }
    if (a <= m - 1) {
        izq[nodo] = post[indice--];
        Construir(izq[nodo], a, m - 1);
    }
}

void pre_orden(int nodo) {
    if (nodo) {
        cout << nodo << " ";
        pre_orden(izq[nodo]);
        pre_orden(der[nodo]);
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> in[i];
    for (int i = 0; i < N; i++)
        cin >> post[i];

    indice = N - 1;
    Construir(post[indice--], 0, N - 1);
    pre_orden(post[N - 1]);
}
