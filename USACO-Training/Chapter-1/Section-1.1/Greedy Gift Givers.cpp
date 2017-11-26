/*
ID: vdae_231
PROG: gift1
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("gift1.in");
    ofstream cout("gift1.out");
    int NP, total[10] = {};
    string names[10], giver, recipient;
    cin >> NP;

    for (int i = 0; i < NP; i++)
        cin >> names[i];

    int money, NG, i, j;
    while (cin >> giver >> money >> NG) {
        if (NG)
            money /= NG;
        for (i = 0; names[i] != giver; i++);
        total[i] -= money * NG;

        while (NG--) {
            cin >> recipient;
            for (j = 0; names[j] != recipient; j++);
            total[j] += money;
        }
    }

    for (int i = 0; i < NP; i++)
        cout << names[i] << " " << total[i] << "\n";
}
