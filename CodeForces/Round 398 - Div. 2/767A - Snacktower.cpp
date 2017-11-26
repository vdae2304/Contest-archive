#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N;
    cin >> N;

    int v[N];
    for (int i = 0; i < N; i++)
        cin >> v[i];

    set<int> p;
    for (int i = 0, j = N; i < N; i++) {
        p.insert(v[i]);
        while (p.count(j)) {
            p.erase(j);
            cout << j-- << " ";
        }
        cout << "\n";
    }
}
