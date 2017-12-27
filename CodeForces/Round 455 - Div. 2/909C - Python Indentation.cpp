#include <bits/stdc++.h>
using namespace std;
#define MOD 1'000'000'007
#define MAXN 5'010

//Ways to organize first i lines, line i with
//identation j (j starts in 1)
int N, ans, DP[MAXN][MAXN];
char s[MAXN];

int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;

    DP[0][1] = 1;
    for (int i = 1; i <= N; i++) {
        int aux = 0;
        cin >> s[i];

        for (int j = MAXN - 1; j > 0; j--) {
            aux = (aux + DP[i - 1][j]) % MOD;
            //Previous line had less identation as it was a for
            if (s[i - 1] == 'f')
                DP[i][j] = DP[i - 1][j - 1];
            //Previous line had equal or more identation
            else
                DP[i][j] = aux;
        }
    }

    for (int i = 1; i < MAXN; i++)
        ans = (ans + DP[N][i]) % MOD;
    cout << ans << "\n";

    return 0;
}
