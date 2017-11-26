#include <bits/stdc++.h>
using namespace std;

int N, v[248];
int DP[248][248], ans;

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("248.in");
    ofstream cout("248.out");
   
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> v[i];

    for (int len = 1; len <= N; len++)
        for (int i = 0; i + len <= N; i++) {
            int j = i + len - 1;
            if (i == j)
                DP[i][j] = v[i];
            else {
                for (int k = i; k < j; k++)
                    if (DP[i][k] == DP[k + 1][j] && DP[i][k])
                        DP[i][j] = max(DP[i][j], DP[i][k] + 1);
            }
            ans = max(ans, DP[i][j]);
        }

    cout << ans << "\n";
}
