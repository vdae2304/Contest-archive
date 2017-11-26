/*
ID: vdae_231
PROG: barn1
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("barn1.in");
    ofstream cout("barn1.out");
    int M, S, C;
    cin >> M >> S >> C;

    int stalls[C], noCows[C];
    for (int i = 0; i < C; i++)
        cin >> stalls[i];
    sort(stalls, stalls + C);

    for (int i = 0; i < C - 1; i++)
        noCows[i] = stalls[i + 1] - stalls[i] - 1;
    sort(noCows, noCows + C - 1);

    int cont = 0;
    for (int i = C - 2; i >= 0 && i >= C - M; i--)
        cont += noCows[i];

    cout << stalls[C - 1] - stalls[0] + 1 - cont << "\n";
}
