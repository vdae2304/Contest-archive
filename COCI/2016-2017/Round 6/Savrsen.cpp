#include <bits/stdc++.h>
using namespace std;
#define MAXN 10000001

int A, B, Sieve[MAXN];
long long ans;

long long sum_divisors(int n) {
    long long sum = 1;
    while (n != 1) {
        long long p = Sieve[n], q = p;
        while (Sieve[n] == p) {
            n /= p;
            q *= p;
        }
        sum *= (q - 1) / (p - 1);
    }
    return sum;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    for (long long i = 2; i < MAXN; i++)
        if (!Sieve[i]) {
            Sieve[i] = i;
            for (long long j = i * i; j < MAXN; j += i)
                if (!Sieve[j])
                    Sieve[j] = i;
        }

    cin >> A >> B;
    for (int i = A; i <= B; i++)
        ans += abs(2 * i - sum_divisors(i));

    cout << ans << "\n";
}
