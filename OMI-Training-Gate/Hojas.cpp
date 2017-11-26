#include <bits/stdc++.h>
using namespace std;
main() {
    int N, B, D;
    cin >> N >> B >> D;

    int S = 0, d = 1;
    for (int i = 1; i <= N; i *= B) {
        if (i * B <= N)
            S += d * i * (B - 1);
        else
            S += d * (N - i + 1);
        d++;
    }

    cout << (S + D - 1) / D;
}
