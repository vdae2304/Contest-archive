#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N, X, val = 0;
    cin >> N >> X;
    while (N--) {
        int P1, P2, P3;
        cin >> P1 >> P2;
        if (abs(P1 - P2) <= X)
            val += max(P1, P2);
        else {
            cin >> P3;
            val += P3;
        }
    }
    cout << val << "\n";
}
