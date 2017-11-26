#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000
typedef pair<int, int> pii;

int N, M, c[MAXN], w[MAXN];
long long total, coins[MAXN], notes[MAXN];
set<pii> v;

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> c[i];
    for (int i = 0; i < N; i++)
        cin >> w[i];

    for (int i = 0; i < N; i++) {
        if (c[i] % 100) {
            M -= c[i] % 100;
            notes[i] = c[i] / 100;
            coins[i] = c[i] % 100;
            v.insert(pii(w[i] * (100 - (c[i] % 100)), i));

            if (M < 0) {
                M += 100;
                total += v.begin() -> first;
                notes[v.begin() -> second]++;
                coins[v.begin() -> second] = 0;
                v.erase(v.begin());
            }
        }
        else
            notes[i] = c[i] / 100;
    }

    cout << total << "\n";
    for (int i = 0; i < N; i++)
        cout << notes[i] << " " << coins[i] << "\n";
}
