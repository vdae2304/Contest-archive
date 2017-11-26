#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long long N, ans = 1;
bool no_primo[10000001];

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;
    for (long long i = 2, p; i * i <= N; i++)
        if (!no_primo[i]) {
            for (long long j = 2 * i; j * j <= N; j += i)
                no_primo[j] = true;
            for (p = i; p <= N / (i * i); p *= i);
            ans = (ans * (p % MOD)) % MOD;
        }
    cout << ans;
}
