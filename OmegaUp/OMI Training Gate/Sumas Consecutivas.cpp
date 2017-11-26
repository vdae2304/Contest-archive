#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N, K;
    cin >> N >> K;

    int Pascal[N][N], v[N];
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        Pascal[i][0] = Pascal[i][i] = 1;
        for (int j = 1; j < i; j++)
            Pascal[i][j] = Pascal[i - 1][j - 1] + Pascal[i - 1][j];
    }
    sort(v, v + N);

    while (true) {
        int S = 0;
        for (int i = 0; i < N; i++)
            S += Pascal[N - 1][i] * v[i];

        if (S == K) {
            for (int i = 0; i < N; i++)
                cout << v[i] << " ";
            return 0;
        }
        next_permutation(v, v + N);
    }
}
