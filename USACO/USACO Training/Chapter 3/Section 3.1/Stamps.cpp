/*
ID: vdae_231
PROG: stamps
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int N, K;
int stamps[50];
int minStamps[2000000];

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("stamps.in");
    ofstream cout("stamps.out");
    cin >> K >> N;

    for (int i = 0; i < N; i++)
        cin >> stamps[i];

    int i;
    for (i = 1; minStamps[i - 1] != K + 1; i++) {
        minStamps[i] = K + 1;
        for (int j = 0; j < N; j++)
            if (i >= stamps[j] && minStamps[i - stamps[j]] < K)
                minStamps[i] = min(minStamps[i], minStamps[i - stamps[j]] + 1);
    }

    cout << i - 2 << "\n";
}
