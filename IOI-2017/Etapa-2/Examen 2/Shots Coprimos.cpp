#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N, g[100];
pii DP[100][1 << 12], nulo;
int fact[40], primos[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

int Resolver(int i, int mask) {
    if (i == N)
        return 0;
    else if (DP[i][mask] == nulo) {
        DP[i][mask].first = INFINITY;
        for (int x = 1; x < 40; x++)
            if (!(mask & fact[x]))
                DP[i][mask] = min(DP[i][mask], pii(Resolver(i + 1, mask | fact[x]) + abs(x - g[i]), x));
    }
    return DP[i][mask].first;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    for (int i = 2; i < 40; i++)
        for (int j = 0; j < 12; j++)
            if (!(i % primos[j]))
                fact[i] |= (1 << j);

    cin >> N;
    while (N) {
        memset(DP, 0, sizeof(DP));
        for (int i = 0; i < N; i++)
            cin >> g[i];
        Resolver(0, 0);

        for (int i = 0, mask = 0; i < N; mask |= fact[DP[i][mask].second], i++)
            cout << DP[i][mask].second << " ";
        cout << "\n";
        cin >> N;
    }
}
