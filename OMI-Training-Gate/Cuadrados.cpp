#include <bits/stdc++.h>
using namespace std;

int N;
bool C[1000][1000], DP[1000][1000];

int cuenta(int M) {
    int S = 0;
    for (int i = 0; i <= N - M; i++)
        for (int j = 0; j <= N - M; j++) {
            for (int k = 0; DP[i][j] && k < M; k++)
                if (C[i + k][j + M - 1] || C[i + M - 1][j + k])
                    DP[i][j] = false;
            if (DP[i][j])
                S++;
        }
    return S;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            cin >> C[i][j];
            DP[i][j] = !C[i][j];
        }

    for (int i = 1; i <= N; i++)
        cout << cuenta(i) << "\n";
}
