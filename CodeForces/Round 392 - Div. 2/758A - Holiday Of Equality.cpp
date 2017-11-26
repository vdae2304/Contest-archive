#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N, ans = 0;
    cin >> N;

    int v[N], max_x = 0;
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        max_x = max(max_x, v[i]);
    }

    for (int i = 0; i < N; i++)
        ans += max_x - v[i];
    cout << ans << "\n";
}
