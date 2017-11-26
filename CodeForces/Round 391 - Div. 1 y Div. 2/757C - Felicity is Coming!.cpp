#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N, M;
    cin >> N >> M;

    vector<int> pokemon[M];
    for (int i = 0; i < N; i++) {
        int G, Gi;
        cin >> G;

        while (G--) {
            cin >> Gi;
            pokemon[Gi - 1].push_back(i);
        }
    }
    sort(pokemon, pokemon + M);

    long long ans = 1, fact[M + 1];
    fact[0] = 1;
    for (int i = 1; i <= M; i++)
        fact[i] = (fact[i - 1] * i) % MOD;

    for (int i = 0, j; i < M; ) {
        for (j = i + 1; j < M && pokemon[i] == pokemon[j]; j++);
        ans = (ans * fact[j - i]) % MOD;
        i = j;
    }

    cout << ans << "\n";
}
