#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ulli;
#define MOD 1000000000000000009

ulli multmod(ulli a, ulli b) {
    ulli answer = 0;
    while (a) {
        if (a % 2)
            answer = (answer + b) % MOD;
        a /= 2;
        b = (b * 2) % MOD;
    }
    return answer;
}

ulli G(ulli x) {
    if (x % 2)
        return multmod(x, (x + 1) / 2);
    return multmod(x + 1, x / 2);
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ulli N, Q, K;
    cin >> N >> Q >> K;

    ulli C[Q];
    for (ulli i = 0, L, D; i < Q; i++) {
        cin >> L >> D;
        C[i] = (G(D) - G(L - 1) + MOD) % MOD;
    }
    sort(C, C + Q);

    ulli V[K];
    for (ulli i = 0; i < K; i++)
        cin >> V[i];
    sort(V, V + K);

    ulli X = 0, Y = 0, Z = 0;
    for (ulli i = 0, j = 0, k; i < Q; i++) {
        for (; j < K && C[i] > V[j]; j++);
        for (k = j; k < K && C[i] == V[k]; k++);
        X += j;
        Y += k - j;
        Z += K - k;
    }

    cout << "Chavos :) x " << X << "\nTablas :| x " << Y << "\nReyes :( x " << Z;
}
