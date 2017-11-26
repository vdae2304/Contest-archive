/*
ID: vdae_231
PROG: runround
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int N;
bool used[10];

bool is_round(string s) {
    int j = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[j] == 'X')
            return false;
        else {
            char aux = s[j];
            s[j] = 'X';
            j = (j + aux - '0') % s.size();
        }
    }
    return !j;
}

void findRound(string s, int d, ofstream &cout) {
    if (d-- < 0)
        return;
    if (atoi(s.c_str()) > N && is_round(s)) {
        cout << s << "\n";
        cout.close();
        exit(0);
    }
    for (int i = 1; i <= 9; i++)
        if (!used[i]) {
            used[i] = true;
            findRound(s + char('0' + i), d, cout);
            used[i] = false;
        }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("runround.in");
    ofstream cout("runround.out");
    cin >> N;
    for (int i = 1; i < 10; i++)
        findRound("", i, cout);
}
