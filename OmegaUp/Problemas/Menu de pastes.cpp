#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N, M, P;
    cin >> N >> M >> P;

    while (P--) {
        long long p, i, j;
        cin >> p;

        j = p % N;
        if (!j)
            j = N;
        i = (p - j) / N + 1;

        cout << (long long) M * (N - j) + i << " ";
    }
}
