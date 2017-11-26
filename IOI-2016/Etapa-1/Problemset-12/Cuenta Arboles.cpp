#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000

int N;
long long DP[1000];

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;

    DP[0] = DP[1] = 1;
    for (int i = 2; i <= N; i++)
        for (int j = 0; j < i; j++)
            DP[i] = (DP[i] + DP[j] * DP[i - j - 1]) % MOD;

    cout << DP[N];
}
