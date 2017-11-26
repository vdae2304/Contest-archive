/*
ID: vdae_231
PROG: fact4
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("fact4.in");
    ofstream cout("fact4.out");
    int N, ans = 1, p = 0;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int m = i;
        for (; !(m % 2); p++)
            m /= 2;
        for (; !(m % 5); p--)
            m /= 5;
        ans = (ans * m) % 10;
    }

    for (int i = 0; i < p; i++)
        ans = (2 * ans) % 10;
    cout << ans << "\n";
}
