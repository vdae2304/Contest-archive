#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    string s;
    getline(cin, s);

    list<char> l;
    list<char>::iterator j = l.end();
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '[')
            j = l.begin();
        else if (s[i] == ']')
            j = l.end();
        else
            l.insert(j, s[i]);
    }

    for (j = l.begin(); j != l.end(); j++)
        cout << *j;
}
