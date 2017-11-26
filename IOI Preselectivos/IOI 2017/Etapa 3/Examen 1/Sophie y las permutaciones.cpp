#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    long long N, K, fibo[51];
    cin >> N >> K;

    fibo[1] = fibo[0] = 1;
    for (int i = 2; i <= N; i++)
        fibo[i] = fibo[i - 1] + fibo[i - 2];

    for (int i = 1; i <= N; ) {
        if (K <= fibo[N - i]) {
            cout << i << " ";
            i++;
        }
        else {
            cout << i + 1 << " " << i << " ";
            K -= fibo[N - i];
            i += 2;
        }
    }
}
