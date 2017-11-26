#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int P, R, S;
    cin >> P >> R;

    bitset<20001> palanca;
    for (int i = 0; i < P - 1; i++) {
        cin >> S;
        palanca[R] = true;
        while (S--) {
             do {
                R--;
                if (!R)
                    R = P;
            }
            while (palanca[R]);
        }
    }
    cout << R;
}
