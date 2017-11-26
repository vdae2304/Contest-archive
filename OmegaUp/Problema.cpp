#include <bits/stdc++.h>
using namespace std;

int N, S;
int v[1000];
bool DP[1001][10001];

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> v[i];
        S += v[i];
    }

    DP[0][0] = true;
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= S / 2; j++)
            if (DP[i][j]) {
                DP[i + 1][j] = true;
                if (j + v[i] <= S / 2)
                    DP[i + 1][j + v[i]] = true;
            }

    for (int i = S / 2; i >= 0; i--)
        if (DP[N][i]) {
            cout << S - 2 * i;
            return 0;
        }
}
