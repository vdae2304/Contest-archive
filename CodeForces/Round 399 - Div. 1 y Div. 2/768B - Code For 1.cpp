#include <bits/stdc++.h>
using namespace std;

long long N, l, r;

int Solve(long long n, long long i, long long j) {
    if (j < l || r < i)
        return 0;
    if (i == j)
        return n;
    long long m = (i + j) / 2;
    return Solve(n / 2, i, m - 1) + Solve(n % 2, m, m) + Solve(n / 2, m + 1, j);
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> l >> r;
    cout << Solve(N, 1, (1ll << ((int)log2(N) + 1)) - 1) << "\n";
}
