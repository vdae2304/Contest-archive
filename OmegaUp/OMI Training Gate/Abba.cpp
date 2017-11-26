#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    string s;
    int cont = 0;
    cin >> s;
    for (int i = 0; i < s.size() / 2; i++)
        if (s[i] != s[s.size() - i - 1]) {
            char c = s[i];
            cont++;
            for (int j = i; j < s.size(); j++)
                if (s[j] == c)
                    s[j] = s[s.size() - i - 1];
        }
    cout << cont;
}
