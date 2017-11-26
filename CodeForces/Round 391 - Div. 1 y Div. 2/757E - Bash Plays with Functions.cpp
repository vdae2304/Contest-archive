#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000001
#define MOD 1000000007

int Q, R, N;
int DP[MAXN][21];
int Sieve[MAXN];

main() {
    for (long long i = 2; i < MAXN; i++)
        if (!Sieve[i]) {
            Sieve[i] = i;
            for (long long j = i * i; j < MAXN; j += i)
                if (!Sieve[j])
                    Sieve[j] = i;
        }

    for (int i = 1; i < 21; i++)
        DP[0][i] = 2;
    for (int i = 0; i < MAXN; i++)
        DP[i][0] = 1;
    for (int i = 1; i < MAXN; i++)
        for (int j = 1; j < 21; j++)
            DP[i][j] = (DP[i][j - 1] + DP[i - 1][j]) % MOD;

    scanf("%d", &Q);
    while (Q--) {
        long long ans = 1;
        scanf("%d%d", &R, &N);

        while (N != 1) {
            int p = Sieve[N], e = 0;
            while (Sieve[N] == p) {
                e++;
                N /= p;
            }
            ans = (ans * DP[R][e]) % MOD;
        }

        printf("%d\n", ans);
    }
}
