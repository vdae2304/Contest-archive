#include <bits/stdc++.h>
using namespace std;

long long N, M, K;

long long PillowsRequired(long long FrodoOwns) {
    long long S = 0;
    if (FrodoOwns >= K)
        S += K * FrodoOwns - (K * (K - 1)) / 2;
    else
        S += K - FrodoOwns + (FrodoOwns * (FrodoOwns + 1)) / 2;
    if (FrodoOwns > N - K)
        S += (N - K) * FrodoOwns - ((N - K) * (N - K + 1)) / 2;
    else
        S += N - K - FrodoOwns + 1 + (FrodoOwns * (FrodoOwns - 1)) / 2;
    return S;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> M >> K;

    long long a = 0, b = 1e9 + 1;
    while (a < b) {
        long long m = (a + b) / 2, c = PillowsRequired(m);
        if (c <= M)
            a = m + 1;
        else
            b = m;
    }

    cout << a - 1 << "\n";
}
