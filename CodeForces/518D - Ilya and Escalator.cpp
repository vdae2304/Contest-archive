#include <bits/stdc++.h>
using namespace std;
#define MAXN 2001

int N, T;
double DP[MAXN][MAXN], P, ans;

double Solve(int i, int t) {
    if (i < 0 || i > t)
        return 0;
    if (!t)
        return 1;
    if (DP[i][t] < 0)
        DP[i][t] = Solve(i - 1, t - 1) * P + Solve(i, t - 1) * (i < N ? 1 - P : 1);
    return DP[i][t];
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> P >> T;

    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= T; j++)
            DP[i][j] = -1;

    for (int i = 0; i <= N && i <= T; i++)
        ans += i * Solve(i, T);
    cout << fixed << setprecision(6) << ans;
}
