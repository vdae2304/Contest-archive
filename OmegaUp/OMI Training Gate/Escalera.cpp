#include <bits/stdc++.h>
using namespace std;
main() {
    int N, K;
    cin >> N >> K;

    long long formas[N + 1];
    for (int i = 1; i <= N; i++) {
        if (i <= K)
            formas[i] = 1;
        else
            formas[i] = 0;

        for (int j = 1; j <= min(K, i - 1); j++)
            formas[i] += formas[i - j];
    }

    cout << formas[N];
}
