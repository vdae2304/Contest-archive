#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("speeding.in");
    ofstream cout("speeding.out");
    int N, M, d, v;
    cin >> N >> M;

    int a = 1, Limite[101], Bessie[101];
    for (int i = 0; i < N; ++i) {
        cin >> d >> v;
        for (int i = a; i < a + d; ++i)
            Limite[i] = v;
        a += d;
    }

    a = 1;
    for (int i = 0; i < M; ++i) {
        cin >> d >> v;
        for (int i = a; i < a + d; ++i)
            Bessie[i] = v;
        a += d;
    }

    a = 0;
    for (int i = 1; i <= 100; ++i)
        a = max(a, Bessie[i] - Limite[i]);

    cout << a;
}
