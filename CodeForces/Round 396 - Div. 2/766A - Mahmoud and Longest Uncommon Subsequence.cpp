#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    string a, b;
    cin >> a >> b;
    if (a.size() != b.size() || a != b)
        cout << max(a.size(), b.size()) << "\n";
    else
        cout << "-1\n";
}
