#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    string s;
    getline(cin, s);

    for (int i = 0, j; i < s.size(); i++)
        if (s[i] == ')') {
            for (j = i; s[j] != '('; j--);
            s[j] = s[i] = -1;
            reverse(s.begin() + j + 1, s.begin() + i);
        }

    for (int i = 0; i < s.size(); i++)
        if (s[i] != -1)
            cout << s[i];
}
