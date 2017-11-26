#include <bits/stdc++.h>
using namespace std;
#define MAXN 10000001
#define MOD 1000000007

int N, DP[MAXN][4];

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;

    DP[0][0] = 1;
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                if (j != k)
                    DP[i][j] = (DP[i][j] + DP[i - 1][k]) % MOD;

    cout << DP[N][0] << "\n";
}
