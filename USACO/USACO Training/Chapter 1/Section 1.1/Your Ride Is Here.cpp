/*
ID: vdae_231
PROG: ride
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("ride.in");
    ofstream cout("ride.out");
    string s[2];
    cin >> s[0] >> s[1];

    int c[2] = {1, 1};
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < s[i].size(); j++)
            c[i] = (c[i] * (s[i][j] - 'A' + 1)) % 47;

    if (c[0] == c[1])
        cout << "GO\n";
    else
        cout << "STAY\n";
}
