#include <bits/stdc++.h>
using namespace std;

int N, M;
int DP[50][2][2][2];
string v[50];

bool issymb(char c) {
    return c == '#' || c == '*' || c == '&';
}

int Solve(int i, bool dig, bool low, bool symb) {
    if (i >= N)
        return dig && low && symb ? 0 : 1000000;
    else if (DP[i][dig][low][symb] == -1) {
        DP[i][dig][low][symb] = INFINITY;
        for (int j = 0; j < M; j++)
            DP[i][dig][low][symb] = min(DP[i][dig][low][symb], min(j, M - j) +
                                Solve(i + 1, dig || isdigit(v[i][j]), low || islower(v[i][j]), symb || issymb(v[i][j])));
    }
    return DP[i][dig][low][symb];
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> v[i];

    memset(DP, -1, sizeof(DP));
    cout << Solve(0, false, false, false) << "\n";
}
