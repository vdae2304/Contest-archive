#include <bits/stdc++.h>
using namespace std;
#define MAXN 10'000'010
typedef pair<int, int> pii;
int n, a, b;
pii DP[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> n >> a >> b;

    memset(DP, -1, sizeof DP);
    DP[0] = pii(0, 0);
    for (int i = 1; i <= n; i++) {
        if (i - a >= 0 && DP[i - a] != pii(-1, -1))
            DP[i] = pii(DP[i - a].first + 1, DP[i - a].second);
        if (i - b >= 0 && DP[i - b] != pii(-1, -1))
            DP[i] = pii(DP[i - b].first, DP[i - b].second + 1);
    }

    if (DP[n] != pii(-1, -1))
        cout << "YES\n" << DP[n].first << " " << DP[n].second << "\n";
    else
        cout << "NO\n";
    return 0;
}
