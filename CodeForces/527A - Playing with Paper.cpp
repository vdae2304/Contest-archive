#include <bits/stdc++.h>
using namespace std;

long long Solve(long long a, long long b) {
    return b ? a / b + Solve(b, a % b) : 0;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    long long a, b;
    cin >> a >> b;
    cout << Solve(a, b) << "\n";
}
