/*
ID: vdae_231
PROG: fence9
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("fence9.in");
    ofstream cout("fence9.out");
    double N, M, P;
    cin >> N >> M >> P;
    int ans = 0;
    for (int i = 1; i < M; i++)
        ans += max(int(ceil(i * (N - P) / M) + P) - int(i * N / M) - 1, 0);
    cout << ans << "\n";
}
