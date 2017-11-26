#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N, K;
    cin >> N >> K;

    pair<int, int> v[N], aux;
    for (int i = 0; i < N; i++)
        cin >> v[i].first >> v[i].second;
    sort(v, v + N);

    while (K--) {
        cin >> aux.first >> aux.second;
        cout << !binary_search(v, v + N, aux) << "\n";
    }
}
