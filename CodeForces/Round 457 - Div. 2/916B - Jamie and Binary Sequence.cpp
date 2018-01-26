#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    long long N, K;
    cin >> N >> K;

    map<long long, int> E;
    for (int i = 0; i < 64; i++)
        if (N & (1ll << i)) {
            E[i] = 1;
            K--;
        }

    if (K < 0)
        cout << "NO\n";
    else {
        while (E.rbegin()->second <= K) {
            long long X = E.rbegin()->first;
            E[X - 1] += 2*E[X];
            K -= E[X];
            E.erase(X);
        }

        while (K--) {
            long long X = E.begin()->first;
            E[X - 1] += 2;
            E[X]--;
            if (!E[X])
                E.erase(X);
        }

        cout << "YES\n";
        for (auto it = E.rbegin(); it != E.rend(); it++)
            for (int i = 0; i < it->second; i++)
                cout << it->first << " ";
        cout << "\n";
    }
    return 0;
}
