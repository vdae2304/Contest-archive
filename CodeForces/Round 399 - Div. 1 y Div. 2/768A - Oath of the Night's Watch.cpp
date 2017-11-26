#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N;
    cin >> N;

    int v[N], ans = 0;
    for (int i = 0; i < N; i++)
        cin >> v[i];

    int a = *min_element(v, v + N), b = *max_element(v, v + N);
    for (int i = 0; i < N; i++)
        if (a < v[i] && v[i] < b)
            ans++;

    cout << ans;
}
