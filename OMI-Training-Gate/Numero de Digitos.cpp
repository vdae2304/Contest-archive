#include <bits/stdc++.h>
using namespace std;
main() {
    int N, d = 1, c = 0;
    cin >> N;
    for (int i = 1; i <= N; i *= 10) {
        if (10 * i <= N)
            c += 9 * d * i;
        else
            c += d * (N - i + 1);
        d++;
    }
    cout << c;
}
