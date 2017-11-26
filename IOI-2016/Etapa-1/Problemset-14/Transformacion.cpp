#include <bits/stdc++.h>
using namespace std;

long long N, M, MOD;
long long l, r, u, v;

long long suma(long long n, long long i, long long j, long long mod, long long r, long long max_r) {
    if (v < r || max_r < u)
        return 0;
    if (n == 1)
        return r;

    long long m = (n + 1) / 2;
    long long a = max_r, b = max_r;

    if (max_r % (2 * mod) != r)
        a -= mod;
    else
        b -= mod;

    if (i <= m && j <= m)
        return suma(m, i, j, 2 * mod, r, a);
    else if (m < i && m < j)
        return suma(n - m, i - m, j - m, 2 * mod, r + mod, b);
    else
        return (suma(m, i, m, 2 * mod, r, a) + suma(n - m, 1, j - m, 2 * mod, r + mod, b)) % MOD;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> M >> MOD;
    while (M--) {
        cin >> l >> r >> u >> v;
        cout << suma(N, l, r, 1, 1, N) << "\n";
    }
}
