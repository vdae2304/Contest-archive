#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
#define maxn 200'000

lld n, a[maxn], dp[maxn];

/*Return if i is a winner position*/
bool solve(lld i) {
    if (dp[i] == -1) {
        dp[i] = false;
        for (lld x = a[i]; x <= n; x += a[i])
            if ((i + x < n && a[i + x] > a[i] && !solve(i + x))
                || (i - x >= 0 && a[i - x] > a[i] && ! solve(i - x))) {
                dp[i] = true;
                break;
            }
    }
    return dp[i];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> n;
    for (lld i = 0; i < n; i++)
        cin >> a[i];

    memset(dp, -1, sizeof dp);
    for (lld i = 0; i < n; i++) {
        if (solve(i))
            cout << "A";
        else
            cout << "B";
    }
    return 0;
}
