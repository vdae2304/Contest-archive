#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
unsigned int N, DP[2][1000000];

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;

    DP[0][0] = 1;
    for (int i = 1; i < N; i++) {
        DP[0][i] = (DP[0][i - 1] + DP[1][i - 1]) % MOD;
        DP[1][i] = DP[0][i - 1];
    }

    cout << (DP[0][N - 1] + 2 * DP[1][N - 1]) % MOD;
}
