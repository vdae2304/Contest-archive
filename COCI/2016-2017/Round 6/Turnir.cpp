#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N;
    cin >> N;

    pair<int, int> v[1 << N];
    for (int i = 0; i < (1 << N); i++) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v, v + (1 << N));

    int ans[1 << N];
    for (int i = 0, j; i < (1 << N); i = j) {
        for (j = i + 1; j < (1 << N) && v[i].first == v[j].first; j++);
        for (int k = i; k < j; k++)
            ans[v[k].second] = N + 1 - log2(j + 1);
    }

    for (int i = 0; i < (1 << N); i++)
        cout << ans[i] << " ";
}
