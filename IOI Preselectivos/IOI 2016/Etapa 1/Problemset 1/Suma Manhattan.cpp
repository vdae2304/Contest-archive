#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int N, P[2][500000];

int calcular(int *p) {
    long long suma = 0;
    sort(p, p + N);

    for (int i = 0; i < N; ++i)
        suma = (suma + (long long) p[i] * (2 * i + 1 - N)) % MOD;
    return suma;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;

    for (int i = 0 ; i < N; ++i)
        cin >> P[0][i] >> P[1][i];

    cout << (calcular(P[0]) + calcular(P[1])) % MOD;
}
