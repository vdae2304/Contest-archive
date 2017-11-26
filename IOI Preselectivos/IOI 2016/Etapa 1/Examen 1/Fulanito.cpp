#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001

int N, Q;
long long v[MAXN];

int index(int a, int b, long long x) {
    if (a <= b) {
        int m = (a + b) / 2;
        if (v[m] <= x)
            return index(m + 1, b, x);
        else
            return index(a, m - 1, x);
    }
    return b;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> Q >> N;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        v[i + 1] = v[i] + x;
    }

    for (int i = 0; i < Q; i++) {
        long long G;
        cin >> G;
        int j = index(0, N, G);
        cout << j << " " << G - v[j] << "\n";
    }
}
