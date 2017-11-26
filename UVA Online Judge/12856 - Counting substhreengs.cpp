#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000001

string s;
long long DP[MAXN][3];

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    while (cin >> s) {
        long long ans = 0;
        memset(DP, 0, sizeof(DP));

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                DP[i + 1][(s[i] - '0') % 3] = 1;
                for (int j = 0; j < 3; j++)
                    DP[i + 1][(j + s[i] - '0') % 3] += DP[i][j];
                ans += DP[i + 1][0];
            }

        cout << ans << "\n";
    }
}
