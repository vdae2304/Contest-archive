#include <bits/stdc++.h>
using namespace std;

int DP[188][151][51];

int calcular(int N, int A, int B, int C) {
    if (!N)
        return 0;
    if (!DP[N][B][C]) {
        int S = INFINITY;

        if (C >= 1 && A >= 3)
            S = min(S, calcular(N - 1, A - 3, B + 1, C - 1) + 4);
        if (C >= 1)
            S = min(S, calcular(N - 1, A + 2, B, C - 1) + 1);
        if (B >= 2)
            S = min(S, calcular(N - 1, A + 2, B - 2, C) + 2);
        if (B >= 1 && A >= 3)
            S = min(S, calcular(N - 1, A - 3, B - 1, C) + 4);
        if (A >= 8)
            S = min(S, calcular(N - 1, A - 8, B, C) + 8);

        DP[N][B][C] = S;
    }
    return DP[N][B][C];
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N, A, B, C;
    cin >> N >> A >> B >> C;

    if (8 * N <= A + 5 * B + 10 * C)
        cout << calcular(N, A, B, C);
    else
        cout << "-1";
}
