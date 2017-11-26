#include <bits/stdc++.h>
using namespace std;
#define MOD 987654321
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N;
    cin >> N;

    int p = N + 1;
    for (int i = 0; i < N - 1; i++)
        p = (p * 2) % MOD;

    cout << p;
}
