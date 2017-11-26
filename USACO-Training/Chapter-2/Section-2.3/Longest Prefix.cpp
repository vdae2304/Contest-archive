/*
ID: vdae_231
PROG: prefix
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

string sequence, s;
vector<string> v;
bool isPart[2000000];

bool isSubsequence(int i, int j) {
    if (i + v[j].size() > sequence.size() || isPart[i + v[j].size()])
        return false;
    for (int k = 0; k < v[j].size(); k++)
        if (sequence[i + k] != v[j][k])
            return false;
    return true;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("prefix.in");
    ofstream cout("prefix.out");

    cin >> s;
    while (s != ".") {
        v.push_back(s);
        cin >> s;
    }

    while (cin >> s)
        sequence += s;

    isPart[0] = true;
    for (int i = 0; i < sequence.size(); i++)
        if (isPart[i])
            for (int j = 0; j < v.size(); j++)
                if (isSubsequence(i, j))
                    isPart[i + v[j].size()] = true;

    for (int i = sequence.size(); i >= 0; i--)
        if (isPart[i]) {
            cout << i << "\n";
            return 0;
        }
}
