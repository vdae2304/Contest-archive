#include <bits/stdc++.h>
using namespace std;
#define MAXN 50010
#define MOD 100

int N, M, Q, l, r;
int A, S, DP[MAXN][MOD];

int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> M >> Q;

    for (int i = 1; i <= N; i++) {
        cin >> A;
        S = (S + A) % M;
        copy(DP[i], DP[i] + M, DP[i + 1]);
        DP[i + 1][S]++;
    }

    while (Q--) {
        int ans = 0;
        cin >> l >> r;
        for (int i = 0; i < M; i++) {
            int mod = DP[r + 1][i] - DP[l - 1][i];
            ans += (mod * (mod - 1)) / 2 + (!i && l == 1 ? mod : 0);
        }
        cout << ans << "\n";
    }
}
