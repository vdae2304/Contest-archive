#include <bits/stdc++.h>
using namespace std;

long long mcm(long long a, long long b) {
    return (a * b) / __gcd(a, b);
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    long long M, N, A, D;
    cin >> M >> N >> A >> D;
    cout << mcm(mcm(M, A) / A, mcm(N, D) / D);
}
