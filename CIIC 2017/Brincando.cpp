#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000
#define sz 150000
int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int K, D, DP[sz];
    cin >> K >> D;

    DP[0] = DP[1] = 1;
    for (int i = 2; i <= K; i++)
        DP[i % sz] = (2 * DP[(i - 1) % sz]) % MOD;

    for (int i = K + 1; i <= D; i++)
        DP[i % sz] = (2 * DP[(i - 1) % sz] - DP[(i - K - 1) % sz] + MOD) % MOD;

    cout << DP[D % sz];
}
