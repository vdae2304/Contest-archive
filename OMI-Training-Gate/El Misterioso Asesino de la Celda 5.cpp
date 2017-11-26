#include <bits/stdc++.h>
using namespace std;

int L, A, N, cont;
bool cuarto[101][101];

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> L >> A >> N;

    for (int i = 0; i < N; i++) {
        int r, c;
        cin >> r >> c;
        cuarto[r][c] = true;
    }

    for (int i = 1; i < L; i++)
        for (int j = 1; j < A; j++)
            if (!cuarto[i][j] && !cuarto[i][j + 1] && !cuarto[i + 1][j] && !cuarto[i + 1][j + 1])
                cont++;

    cout << cont;
}
