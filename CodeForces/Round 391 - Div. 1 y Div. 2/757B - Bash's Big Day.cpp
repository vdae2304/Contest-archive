#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001

int N, strength[MAXN];
int DP[MAXN], ans = 1;

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> strength[i];
    sort(strength, strength + N);

    for (int i = 0; i < N; i++)
        for (int j = 1; j * j <= strength[i]; j++)
            if (!(strength[i] % j)) {
                DP[j]++;
                if (j * j != strength[i])
                    DP[strength[i] / j]++;
            }

    for (int i = 2; i < MAXN; i++)
        ans = max(ans, DP[i]);
    cout << ans << "\n";
}
