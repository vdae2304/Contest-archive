#include <bits/stdc++.h>
using namespace std;
#define MAXN 1001
#define MAXD 10001
typedef long double lld;

int K, Q, P;
lld DP[MAXN][MAXD];

lld Solve(int orbs, int days) {
    if (orbs > days || (!orbs && days))
        return 0;
    if (days == 1)
        return 1;
    if (DP[orbs][days] < 0)
        DP[orbs][days] = (Solve(orbs - 1, days - 1) * (K - orbs + 1)
                          + Solve(orbs, days - 1) * orbs) / K;
    return DP[orbs][days];
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> K >> Q;

    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXD; j++)
            DP[i][j] = -1;

    while (Q--) {
        cin >> P;
        int a = 1, b = MAXD - 1;
        while (a < b) {
            int m = (a + b) / 2;
            if (Solve(K, m) < P / 2000.0)
                a = m + 1;
            else
                b = m;
        }
        cout << a << "\n";
    }
}
