#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    string s;
    cin >> s;

    bool on[30] = {1};
    for (int i = 0; i < s.size(); i++) {
        if (!on[s[i] - 'a' + 1] && !on[s[i] - 'a']) {
            cout << "NO\n";
            return 0;
        }
        on[s[i] - 'a' + 1] = true;
    }

    cout << "YES\n";
}
