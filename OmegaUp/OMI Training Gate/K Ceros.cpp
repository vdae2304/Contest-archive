#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ulli;

ulli ceros(ulli N) {
    ulli c = 0;
    for (ulli i = 5; i <= N; i *= 5)
        c += N / i;
    return c;
}

main() {
    ulli N, a = 1, b = 1ull << 60;
    cin >> N;
    while (a < b) {
        ulli m = (a + b) / 2;
        if (ceros(m) < N)
            a = m + 1;
        else
            b = m;
    }
    cout << b;
}
