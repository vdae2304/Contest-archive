/*
ID: vdae_231
PROG: kimbits
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

long long N, L, I;
long long DP[32][32];

void SizeOfSet() {
    for (int i = 0; i < 32; i++)
        DP[0][i] = 1;
    for (int i = 1; i < 32; i++) {
        DP[i][0] = 1;
        for (int j = 1; j < 32; j++)
            DP[i][j] = DP[i - 1][j - 1] + DP[i - 1][j];
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("kimbits.in");
    ofstream cout("kimbits.out");
    cin >>  N >> L >> I;

    SizeOfSet();
    I--;

    for (int i = N - 1; i >= 0; i--) {
        if (DP[i][L] <= I) {
            cout << "1";
            I -= DP[i][L--];
        }
        else
            cout << "0";
    }
    cout << "\n";
}
