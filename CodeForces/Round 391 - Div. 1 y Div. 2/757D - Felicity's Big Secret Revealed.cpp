#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int N, ans;
string v;
int DP[76][1 << 20];

int Solve(int i, int bitmask) {
    if (DP[i][bitmask] == -1) {
        DP[i][bitmask] = bitmask && !(bitmask & (bitmask + 1));
        for (int j = i + 1, m = 0; j <= N && m <= 20; j++) {
            m = 2 * m + (v[j - 1] == '1');
            if (0 < m && m <= 20)
                DP[i][bitmask] = (DP[i][bitmask] + Solve(j, bitmask | (1 << (m - 1)))) % MOD;
        }
    }
    return DP[i][bitmask];
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> v;

    memset(DP, -1, sizeof(DP));
    for (int i = 0; i < N; i++)
        ans = (ans + Solve(i, 0)) % MOD;

    cout << ans << "\n";
}
