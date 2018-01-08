#include <bits/stdc++.h>
using namespace std;
#define MAXN 32
int N, L, lowBit = MAXN;
long long ans, aux[MAXN], C[MAXN], DP[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> L;

    for (int i = 0; i < MAXN; i++) {
        if (i < N)
            cin >> C[i];
        DP[i] = LLONG_MAX;
        for (int j = 0; j <= i && j < N; j++)
            DP[i] = min(DP[i], (1ll << (i - j)) * C[j]);
    }

    for (int i = 0; i < MAXN; i++) {
        if (i)
            aux[i] = aux[i - 1];
        if (L & (1ll << i)) {
            aux[i] += DP[i];
            lowBit = min(lowBit, i);
        }
    }

    ans = aux[MAXN - 1];
    for (int i = MAXN - 1; i > lowBit; i--)
        if (!(L & (1ll << i))) {
            ans = min(ans, aux[MAXN - 1] - aux[i] + DP[i]);
        }

    cout  << ans << "\n";
    return 0;
}
