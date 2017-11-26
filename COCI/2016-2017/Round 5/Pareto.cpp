#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N;
    cin >> N;

    long long v[N], S = 0;
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        S += v[i];
    }
    sort(v, v + N);

    double A = 0, B = 0, C = 0;
    for (int i = N - 1; i >= 0; i--) {
        C += v[i];
        double NA = (100.0 * (N - i)) / N, NB = (100.0 * C) / S;
        if (NB - NA >= B - A)
            A = NA, B = NB;
    }

    cout << A << "\n" << B << "\n";
}
