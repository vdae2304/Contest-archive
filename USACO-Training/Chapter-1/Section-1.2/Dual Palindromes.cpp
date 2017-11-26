/*
ID: vdae_231
PROG: dualpal
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

string convert(int N, int b) {
    string result;
    while (N) {
        result.push_back(N % b);
        N /= b;
    }
    return result;
}

bool isPal(int N, int b) {
    string p = convert(N, b);
    for (int i = 0; i < p.size() / 2; i++)
        if (p[i] != p[p.size() - i - 1])
            return false;
    return true;
}

bool dualpal(int N) {
    int pal = 0;
    for (int i = 2; i <= 10; i++)
        if (isPal(N, i))
            pal++;
    return pal >= 2;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("dualpal.in");
    ofstream cout("dualpal.out");
    int N, S;
    cin >> N >> S;

    while (N)
        if (dualpal(++S)) {
            cout << S << "\n";
            N--;
        }
}
