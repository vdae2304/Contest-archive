/*
ID: vdae_231
PROG: rockers
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int N, T, M, v[20];
int DP[21][21][21];

int Solve(int song, int disk, int minute) {
    if (song == N || disk == M)
        return 0;
    else if (DP[song][disk][minute] == -1) {
        DP[song][disk][minute] = max(Solve(song, disk + 1, 0), Solve(song + 1, disk, minute));
        if (minute + v[song] <= T)
            DP[song][disk][minute] = max(DP[song][disk][minute], Solve(song + 1, disk, minute + v[song]) + 1);
    }
    return DP[song][disk][minute];
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("rockers.in");
    ofstream cout("rockers.out");
    cin >> N >> T >> M;
    for (int i = 0; i < N; i++)
        cin >> v[i];
    memset(DP, -1, sizeof(DP));
    cout << Solve(0, 0, 0) << "\n";
}
