#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    string l;
    int cont[255] = {};

    getline(cin, l);
    for (int i = 0; i < l.size(); i++)
        cont[l[i]]++;

    cout << min(cont['B'], min(cont['u'] / 2, min(cont['l'], min(cont['b'], min(cont['a'] / 2, min(cont['s'], cont['r'])))))) << "\n";
}
