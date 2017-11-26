#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    long long N, mod, p = 1;
    cin >> N >> mod;

    string M;
    cin >> M;
    for (int i = 0; i < M.size(); i++) {
        p = (p * p) % mod;
        if (M[i] == '1')
            p = (p * N) % mod;
    }

    cout << p;
}
