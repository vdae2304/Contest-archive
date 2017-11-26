#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ulli;
main() {
    ulli N, S = 0;
    cin >> N;

    ulli a = 0, b = 1, c = 2;
    for (ulli i = 1; i <= log2(N); i++) {
        S += ((N / 2 - a) / c) * b;
        S += min((N / 2 - a) % c, b);
        a += b; b *= 2; c *= 2;
    }

    cout << S;
}
