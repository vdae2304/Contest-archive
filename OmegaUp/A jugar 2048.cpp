#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N, x;
    cin >> N;

    stack<int> p;
    while (N--) {
        cin >> x;
        while (!p.empty() && p.top() == x) {
            p.pop();
            x *= 2;
        }
        p.push(x);
    }

    cout << p.size();
    while (!p.empty()) {
        cout << "\n" << p.top();
        p.pop();
    }
}
