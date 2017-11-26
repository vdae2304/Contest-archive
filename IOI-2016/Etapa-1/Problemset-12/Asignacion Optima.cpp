#include <bits/stdc++.h>
using namespace std;

int N, v[22][22];
int DP[1 << 22];

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> v[i][j];

    for (int usado = (1 << N) - 2; usado >= 0; usado--) {
        int r = INT_MIN, i = __builtin_popcount(usado);

        for (int j = 0; j < N; j++)
            if (!(usado & (1 << j)))
                r = max(r, DP[usado | (1 << j)] + v[i][j]);

        DP[usado] = r;
    }

    cout << DP[0];
}
