#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N = 0, d = 0;
    string s;
    getline(cin, s);

    for (int i = 0; i < s.size(); i++)
        N += toupper(s[i]);

    for (int i = 1; i <= N; i++)
        if (!(N % i))
            d++;

    cout << d;
}
