/*
ID: vdae_231
PROG: game1
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N, v[100];
pii DP[100][100], null;

pii Solve(int a, int b, bool turn) {
    if (a > b)
        return null;
    else if (DP[a][b] == null) {
        pii A = Solve(a + 1, b, !turn), B = Solve(a, b - 1, !turn);
        if (turn) {
            A.first += v[a];
            B.first += v[b];
            DP[a][b] = (A.first > B.first) ? A : B;
        }
        else {
            A.second += v[a];
            B.second += v[b];
            DP[a][b] = (A.second > B.second) ? A : B;
        }
    }
    return DP[a][b];
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("game1.in");
    ofstream cout("game1.out");
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> v[i];

    pii ans = Solve(0, N - 1, 1);
    cout << ans.first << " " << ans.second << "\n";
}
