#include <bits/stdc++.h>
using namespace std;

long long N, l, r, ans;
long long DP[10000001];

long long power(long long b, long long e) {
    if (!e)
        return 1;
    long long x = power(b, e / 2);
    if (x > r)
        return x;
    return x * x * (e % 2 ? b : 1);
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> l >> r;

    if (N == 1)
        ans = r - l + 1;
    else if (N == 2)
        ans = (r - l) * (r - l + 1);
    else {
        for (int i = 1; i <= r && DP[i - 1] <= r; i++)
            DP[i] = power(i, N - 1);

        for (int q = 1; q <= r && DP[q] <= r; q++)
            for (int a = DP[q]; a <= r; a += DP[q])
                for (int p = 1; p < q; p++)
                    ans += (l <= a * DP[p] / DP[q] && __gcd(p, q) == 1) ? 2 : 0;
    }

    cout << ans << "\n";
}
