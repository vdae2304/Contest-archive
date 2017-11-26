#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N, ans = 0;
    cin >> N;

    int v[N];
    for (int i = 0; i < N; i++)
        cin >> v[i];
    sort(v, v + N);

    for (int i = N - 1; i >= 0; i--) {
        if (v[i] > ans)
            ans++;
        else
            break;
    }

    cout << ans << "\n";
}
