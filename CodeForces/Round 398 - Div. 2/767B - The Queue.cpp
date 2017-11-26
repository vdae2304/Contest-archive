#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N;
    long long ts, tf, t;
    cin >> ts >> tf >> t >> N;

    long long v[N + 2];
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
        if (v[i] > tf) {
            N = i - 1;
            break;
        }
    }

    long long last, ans, ans_t = INFINITY;
    v[0] = last = ts - t;
    v[N + 1] = tf - t + 1;

    for (int i = 0; i <= N; i++) {
        last = max(last, v[i]) + t;
        if (last > tf - t)
            break;
        if (v[i + 1] == v[i])
            continue;
        if (last - v[i + 1] < ans_t) {
            ans_t = last - v[i + 1];
            ans = v[i + 1] - 1;
        }
    }

    cout << ans;
}
