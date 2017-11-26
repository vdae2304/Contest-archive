#include <bits/stdc++.h>
using namespace std;
#define MOD 10000000007

int N;
long long C, DP[301][301][300];

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            cin >> C;
            if (i == 1 && j == 1)
                DP[i][j][C % N] = 1;
            else
                for (int k = 0; k < N; k++)
                    DP[i][j][(k + C) % N] = (DP[i - 1][j][k] + DP[i][j - 1][k]) % MOD;            
        }

    cout << DP[N][N][0];
}
