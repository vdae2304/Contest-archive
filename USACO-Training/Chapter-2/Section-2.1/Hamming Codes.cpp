/*
ID: vdae_231
PROG: hamming
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("hamming.in");
    ofstream cout("hamming.out");
    int N, B, D, i = 0;
    cin >> N >> B >> D;

    vector<int> sol;
    while (sol.size() < N) {
        bool isSolution = true;
        for (int j = 0; j < sol.size(); j++)
            if (__builtin_popcount(sol[j] ^ i) < D) {
                isSolution = false;
                break;
            }
        if (isSolution)
            sol.push_back(i);
        i++;
    }

    for (i = 0; i < N; i++) {
        if (i % 10)
            cout << " ";
        else if (i)
            cout << "\n";
        cout << sol[i];
    }
    cout << "\n";
}
