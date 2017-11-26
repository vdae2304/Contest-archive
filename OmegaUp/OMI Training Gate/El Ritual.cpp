#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int M, N, K;
    cin >> M >> N >> K;

    queue<int> R[M + 1];
    while (K--) {
        int a, b; char c;
        cin >> c >> a;
        if (c == 'F') {
            cin >> b;
            R[b].push(a);
        }
        else
            while (!R[a].empty()) {
                cout << R[a].front() << " ";
                R[a].pop();
            }
    }
}
