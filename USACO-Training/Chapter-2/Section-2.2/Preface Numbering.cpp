/*
ID: vdae_231
PROG: preface
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int N, used[256];
string c = "IVXLCDM";
string cifra[4][10] = {{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
                       {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                       {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                       {"", "M", "MM", "MMM"}};

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("preface.in");
    ofstream cout("preface.out");
    cin >> N;

    for (int i = 1; i <= N; i++) {
        string s;
        for (int j = 3, k = 1000; j >= 0; j--, k /= 10)
            s += cifra[j][(i % (10 * k)) / k];
        for (int j = 0; j < s.size(); j++)
            used[s[j]]++;
    }

    for (int i = 0; i < c.size(); i++)
        if (used[c[i]])
            cout << c[i] << " " << used[c[i]] << "\n";
}
