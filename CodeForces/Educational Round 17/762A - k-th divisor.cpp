#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    long long N, K, d = 0;
    cin >> N >> K;

    for (long long i = 1; i * i <= N; i++)
        if (!(N % i))
            d += 2 - (i * i == N);

    if (K > d)
        cout << "-1\n";
    else {
        bool aux = K <= (d + 1) / 2;
        if (K > (d + 1) / 2)
            K = d + 1 - K;
        for (long long i = 1, d = 0; i * i <= N; i++) {
            d += !(N % i);
            if (d == K) {
                cout << (aux ? i : N / i) << "\n";
                return 0;
            }
        }
    }
}
