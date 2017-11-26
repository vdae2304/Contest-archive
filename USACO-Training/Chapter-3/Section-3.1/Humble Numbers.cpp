/*
ID: vdae_231
PROG: humble
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int K, N;
int prime[100], pindex[100];
int humble[100001];

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("humble.in");
    ofstream cout("humble.out");
    cin >> K >> N;

    for (int i = 0; i < K; i++)
        cin >> prime[i];

    humble[0] = 1;
    for (int i = 1; i <= N; i++) {
        int nxt = INFINITY;
        for (int j = 0; j < K; j++) {
            while (prime[j] * humble[pindex[j]] <= humble[i - 1])
                pindex[j]++;
            nxt = min(nxt, prime[j] * humble[pindex[j]]);
        }
        humble[i] = nxt;
    }

    cout << humble[N] << "\n";
}
