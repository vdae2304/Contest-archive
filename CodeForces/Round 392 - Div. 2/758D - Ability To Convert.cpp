#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    long long N, ans = 0;
    string K;
    cin >> N >> K;

    long long p = 1, d = 1, u = 0;
    for (int i = K.size() - 1; i >= 0; i--) {
        u += d * (K[i] - '0');
        while (u >= N || d >= N) {
            ans += p * (u % d);
            p *= N;
            do {
                u /= 10;
                d /= 10;
            }
            while (u % d);
        }
        d *= 10;
    }
    ans += u * p;

    cout << ans << "\n";
}
