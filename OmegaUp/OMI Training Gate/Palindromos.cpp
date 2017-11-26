#include <bits/stdc++.h>
using namespace std;

string palindromo(string s) {
    for (int i = 0; i < s.size() / 2; i++)
        if (s[i] != s[s.size() - i - 1])
            return "NP\n";
    return "P\n";
}

main() {
    int N;
    cin >> N;

    while (N--) {
        string s;
        cin >> s;
        cout << palindromo(s);
    }
}
