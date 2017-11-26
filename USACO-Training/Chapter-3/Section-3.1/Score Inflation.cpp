/*
ID: vdae_231
PROG: inflate
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int M, N;
int P[10000], T[10000];
int DP[10001];

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("inflate.in");
    ofstream cout("inflate.out");
    cin >> M >> N;

    for (int i = 0; i < N; i++)
        cin >> P[i] >> T[i];

    for (int i = 0; i <= M; i++)
        for (int j = 0; j < N; j++)
            if (i >= T[j])
                DP[i] = max(DP[i], DP[i - T[j]] + P[j]);

    cout << DP[M] << "\n";
}
