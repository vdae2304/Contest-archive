/*
ID: vdae_231
PROG: nocows
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
#define MOD 9901

int N, K;
int DP[201][101];
int tree[201][101];

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("nocows.in");
    ofstream cout("nocows.out");
    cin >> N >> K;

    DP[1][1] = 1;
    for (int j = 2; j <= K; j++)
        for (int i = 1; i <= N; i += 2) {
            for (int k = 1; k <= i - k - 1; k += 2) {
                int c = (k == i - k - 1) ? 1 : 2;
                DP[i][j] += c * (tree[k][j - 2] * DP[i - k - 1][j - 1]
                                + DP[k][j - 1] * tree[i - k - 1][j - 2]
                                + DP[k][j - 1] * DP[i - k - 1][j - 1]);
                DP[i][j] %= MOD;
            }

            tree[i][j - 1] = (tree[i][j - 2] + DP[i][j - 1]) % MOD;
        }

    cout << DP[N][K] << "\n";
}
