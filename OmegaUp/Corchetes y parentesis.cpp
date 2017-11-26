#include <bits/stdc++.h>
using namespace std;

string valido(string s) {
    stack<char> p;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '{')
            p.push(s[i]);
        else if (s[i] == ')' || s[i] == '}') {
            if (s[i] == ')' && !p.empty() && p.top() == '(')
                p.pop();
            else if (s[i] == '}' && !p.empty() && p.top() == '{')
                p.pop();
            else
                return "NO";
        }
    }
    return p.empty() ? "SI" : "NO";
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    string s;
    getline(cin, s);
    cout << valido(s);
}
