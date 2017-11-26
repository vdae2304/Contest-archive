/*
ID: vdae_231
PROG: sort3
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("sort3.in");
    ofstream cout("sort3.out");
    int N;
    cin >> N;

    int v[N], len[4] = {}, cnt[4][4] = {};
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        len[v[i]]++;
    }

    for (int i = 0; i < len[1]; i++)
        cnt[1][v[i]]++;
    for (int i = len[1]; i < len[1] + len[2]; i++)
        cnt[2][v[i]]++;
    for (int i = len[1] + len[2]; i < N; i++)
        cnt[3][v[i]]++;

    cout << min(cnt[1][2], cnt[2][1]) + min(cnt[1][3], cnt[3][1]) + min(cnt[2][3], cnt[3][2])
            + 2 * (max(cnt[1][2], cnt[2][1]) - min(cnt[1][2], cnt[2][1])) << "\n";
}
