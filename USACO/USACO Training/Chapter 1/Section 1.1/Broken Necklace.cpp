/*
ID: vdae_231
PROG: beads
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("beads.in");
    ofstream cout("beads.out");
    int N, answer = 0;
    string s;

    cin >> N >> s;
    s += s;

    for (int i = 0; i < N; i++) {
        char c = s[i];
        int r = 0, j;

        if (c == 'w') {
            for (j = i; j < 2 * N && s[j] == c; j++);
            c = s[j];
        }

        for (j = i; r < N && (s[j] == 'w' || s[j] == c); j++, r++);
        for (; r < N && s[j] != c; j++, r++);
        answer = max(answer, r);
    }

    cout << answer << "\n";
}
