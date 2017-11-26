/*
ID: vdae_231
PROG: numtri
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int N, P[1000][1000], DP[1000][1000];

int solve(int i, int j) {
    if (DP[i][j] == -1) {
        DP[i][j] = P[i][j];
        if (i < N - 1)
            DP[i][j] += max(solve(i + 1, j), solve(i + 1, j + 1));
    }
    return DP[i][j];
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("numtri.in");
    ofstream cout("numtri.out");
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
            cin >> P[i][j];

    memset(DP, -1, sizeof(DP));
    cout << solve(0, 0) << "\n";
}
