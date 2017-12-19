#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N, ans = 0;
    cin >> N;

    int v[N];
    for (int i = 0; i < N; i++)
        cin >> v[i];
    sort(v, v + N);

    for (int i = 0, j; i < N; i = j) {
        for (j = i; j < N && v[i] == v[j]; j++);
        ans = max(ans, j - i);
    }

    cout << ans << "\n";
    return 0;
}