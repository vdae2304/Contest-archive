/*
ID: vdae_231
PROG: money
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int V, N;
int coins[25];
long long DP[10001];

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("money.in");
    ofstream cout("money.out");
    cin >> V >> N;

    for (int i = 0; i < V; i++)
        cin >> coins[i];

    DP[0] = 1;
    for (int i = 0; i < V; i++)
        for (int j = coins[i]; j <= N; j++)
            DP[j] += DP[j - coins[i]];

    cout << DP[N] << "\n";
}
