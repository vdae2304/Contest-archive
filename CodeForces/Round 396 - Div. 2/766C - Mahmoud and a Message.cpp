#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000
#define MOD 1000000007

struct res {
    int total, max_l, min_s;
};

int N, v[26];
string s;
res DP[MAXN];

bool checar(int l, int usado) {
    for (int i = 0; i < 26; i++)
        if (usado & (1 << i) && l > v[i])
            return false;
    return true;
}

res Resolver(int i) {
    if (i == N)
        return res {1, 0, 0};
    else if (!DP[i].total) {
        int usado = 0;
        DP[i] = res{0, 0, MAXN};
        for (int j = i; j < N; j++) {
            usado |= 1 << (s[j] - 'a');
            if (checar(j - i + 1, usado)) {
                DP[i].total = (DP[i].total + Resolver(j + 1).total) % MOD;
                DP[i].max_l = max(DP[i].max_l, max(Resolver(j + 1).max_l, j - i + 1));
                DP[i].min_s = min(DP[i].min_s, Resolver(j + 1).min_s + 1);
            }
            else
                break;
        }
    }
    return DP[i];
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> s;
    for (int i = 0; i < 26; i++)
        cin >> v[i];
    cout << Resolver(0).total << " " << Resolver(0).max_l << " " << Resolver(0).min_s;
}
