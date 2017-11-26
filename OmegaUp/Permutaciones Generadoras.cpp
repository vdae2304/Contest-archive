#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000
typedef pair<int, int> pii;

int N, R;
int izq[MAXN], der[MAXN];
int pascal[MAXN][MAXN];

int combinacion(int n, int k) {
    if (!k || k == n)
        return 1;
    else if (!pascal[n][k])
        pascal[n][k] = (combinacion(n - 1, k - 1) + combinacion(n - 1, k)) % 997;
    return pascal[n][k];
}

pii resolver(int nodo) {
    if (nodo == -1)
        return pii(0, 1);
    else {
        pii a = resolver(izq[nodo]), b = resolver(der[nodo]);
        return pii(a.first + b.first + 1, (a.second * b.second * combinacion(a.first + b.first, a.first)) % 997);
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> R;
    for (int i = 1; i <= N; i++)
        cin >> izq[i] >> der[i];
    cout << resolver(R).second;
}
