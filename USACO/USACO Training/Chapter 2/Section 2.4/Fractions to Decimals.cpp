/*
ID: vdae_231
PROG: fracdec
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int a, b;
int used[100000];

string convert(int n) {
    string s;
    do {
        s.push_back(n % 10 + '0');
        n /= 10;
    }
    while (n);
    reverse(s.begin(), s.end());
    return s;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("fracdec.in");
    ofstream cout("fracdec.out");
    cin >> a >> b;

    if (!(a % b))
        cout << a / b << ".0\n";
    else {
        string s = convert(a / b) + ".";
        a %= b;
        used[a] = s.size();

        for (int i = s.size() + 1; a; i++) {
            a *= 10;
            s.push_back(a / b + '0');
            a %= b;

            if (used[a]) {
                s.insert(s.begin() + used[a], '(');
                s.push_back(')');
                break;
            }
            used[a] = i;
        }

        for (int i = 0; i < s.size(); i++) {
            if (i && !(i % 76))
                cout << "\n";
            cout << s[i];
        }
        cout << "\n";
    }
}
