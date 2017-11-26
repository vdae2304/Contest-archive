#include <bits/stdc++.h>
using namespace std;
#define MAXN 700

int N, K, v[MAXN], B[MAXN];
int DP[MAXN][MAXN];

int Resolver(int a, int b) {
    if (a >= b)
        return 0;
    if (DP[a][b] == -1) {
        if (B[b] - B[a] == K)
            DP[a][b] = v[a] + Resolver(a + 1, b - 1) + v[b];
        for (int i = a; i < b; i++)
            DP[a][b] = max(DP[a][b], Resolver(a, i) + Resolver(i + 1, b));
    }
    return DP[a][b];
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> K;

    for (int i = 0; i < N; i++)
        cin >> v[i];

    for (int i = 0; i < N; i++)
        cin >> B[i];

    memset(DP, -1, sizeof DP);
    cout << Resolver(0, N - 1);
}
