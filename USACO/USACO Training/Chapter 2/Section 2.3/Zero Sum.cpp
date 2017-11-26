/*
ID: vdae_231
PROG: zerosum
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int N;

bool iszero(string s) {
    int sum = 0, j = 0, op = 1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+' || s[i] == '-') {
            sum += op * j;
            j = 0;
            op = (s[i] == '+') ? 1 : -1;
        }
        else if (s[i] != ' ')
            j = 10 * j + s[i] - '0';
    }
    return sum + op * j == 0;
}

void solve(string s, char i, ofstream &cout) {
    if (i++ >= N + '0') {
        if (iszero(s))
            cout << s << "\n";
    }
    else {
        solve(s + ' ' + i, i, cout);
        solve(s + '+' + i, i, cout);
        solve(s + '-' + i, i, cout);
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("zerosum.in");
    ofstream cout("zerosum.out");
    cin >> N;
    solve("1", '1', cout);
}
