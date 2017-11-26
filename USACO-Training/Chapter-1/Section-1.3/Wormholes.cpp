/*
ID: vdae_231
PROG: wormhole
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int N, X[13], Y[13];
int partner[13], nxt[13];

bool is_cycle() {
    for (int i = 1; i <= N; i++) {
        int pos = i;
        for (int j = 1; j <= N; j++)
            pos = nxt[partner[pos]];
        if (pos)
            return true;
    }
    return false;
}

int solve() {
    int S = 0, i;
    for (i = 1; i <= N && partner[i]; i++);

    if (i > N)
        return is_cycle();

    for (int j = i + 1; j <= N; j++)
        if (!partner[j]) {
            partner[i] = j;
            partner[j] = i;
            S += solve();
            partner[i] = partner[j] = 0;
        }
    return S;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("wormhole.in");
    ofstream cout("wormhole.out");
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> X[i] >> Y[i];

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if ((X[i] < X[j] && Y[i] == Y[j]) && (!nxt[i] || X[j] < X[nxt[i]]))
                nxt[i] = j;

    cout << solve() << "\n";
}
