#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, int> pll;
map<pll, pll> DP;

pll calcular(long long n, long long u) {
    if (n < 10)
        return make_pair(1, max(u - n, 0ll));
    else if (DP.find(make_pair(n, u)) == DP.end()) {
        long long p;
        for (p = 1; p <= n / 10; p *= 10);
        pll a = calcular(n % p, max(u, n / p));
        pll b = calcular(n - (n % p) - a.second, u);
        DP[make_pair(n, u)] = make_pair(a.first + b.first, b.second);
    }
    return DP[make_pair(n, u)];
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    long long n;
    cin >> n;
    cout << (n ? calcular(n, 0).first : 0);
}
