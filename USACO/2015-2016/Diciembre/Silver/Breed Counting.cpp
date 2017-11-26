#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("bcount.in");
    ofstream cout("bcount.out");
    int N, Q, a, b;
    cin >> N >> Q;

    int T[4][N + 1];
    T[1][0] = T[2][0] = T[3][0] = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> a;
        for (int j = 1; j <= 3; ++j)
            T[j][i] = T[j][i - 1];
        T[a][i]++;
    }

    for (int i = 0; i < Q; ++i) {
        cin >> a >> b;
        cout << T[1][b] - T[1][a - 1] << " " << T[2][b] - T[2][a - 1] << " " << T[3][b] - T[3][a - 1] << endl;
    }
}
