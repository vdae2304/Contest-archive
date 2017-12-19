#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000
int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N, x;
    bitset<MAXN> DP;

    DP[0] = true;
    for (int i = 1; i < MAXN; i++)
        if ((i >= 3 && DP[i - 3]) || (i >= 7 && DP[i - 7]))
            DP[i] = true;

    cin >> N;
    while (N--) {
        cin >> x;
        if (DP[x])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}