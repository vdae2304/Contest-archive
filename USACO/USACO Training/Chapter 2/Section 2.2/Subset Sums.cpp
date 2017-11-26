/*
ID: vdae_231
PROG: subset
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int N;
unsigned int DP[400];

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("subset.in");
    ofstream cout("subset.out");
    cin >> N;

    if (N * (N + 1) % 4)
        cout << "0\n";
    else {
        DP[0] = 1;
        int S = N * (N + 1) / 4;
        for (int i = 1; i <= N; i++)
            for (int j = S; j >= i; j--)
                DP[j] += DP[j - i];

        cout << DP[S] / 2 << "\n";
    }
}
