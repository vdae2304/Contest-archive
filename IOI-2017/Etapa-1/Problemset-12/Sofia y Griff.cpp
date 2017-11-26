#include <bits/stdc++.h>
using namespace std;

int N, K, ans, x;
bool DP[501][501];

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> K;

    DP[0][0] = true;
    for (int i = 0; i < N; i++) {
        cin >> x;
        for (int j = K; j >= 0; j--)
            for (int k = K; k >= 0; k--)
                if (DP[j][k]) {
                    if (j + x <= K)
                        DP[j + x][k] = true;
                    if (k + x <= K)
                        DP[j][k + x] = true;
                }
    }

    for (int i = 0; i <= K; i++)
        if (DP[i][K - i])
            ans++;

    cout << ans << "\n";
    for (int i = 0; i <= K; i++)
        if (DP[i][K - i])
            cout << i << " ";
}
