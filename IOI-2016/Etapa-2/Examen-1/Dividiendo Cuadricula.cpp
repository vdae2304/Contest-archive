#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int M, N, x, y;
    cin >> M;
    while (M--) {
        cin >> N >> x >> y;
        if ((x == N / 2 || x == N / 2 + 1) && (y == N / 2 || y == N / 2 + 1))
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}
