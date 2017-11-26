#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N;
    cin >> N;
    string s, ans;
    stack<int> p;

    while (cin >> s) {
        if (!p.empty() && p.top() == 1)
            ans.push_back(',');
        if (s == "pair") {
            ans.append("pair<");
            p.push(2);
        }
        else  if (p.empty()) {
            if (N && !(cin >> s))
                cout << "int";
            else
                cout << "Error occurred";
            return 0;
        }
        else {
            ans.append("int");
            while (!p.empty() && p.top() == 1) {
                ans.append(">");
                p.pop();
            }
            if (!p.empty())
                p.top()--;
        }
        N = 0;
    }

    if (!p.empty())
        cout << "Error occurred";
    else
        cout << ans;
}
