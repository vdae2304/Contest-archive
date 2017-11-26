#include <bits/stdc++.h>
using namespace std;
main() {
    int N;
    cin >> N;

    vector<int> p(1, 1);
    while (N--) {
        int u = 0;
        for (int i = 0; i < p.size(); i++) {
            p[i] = 2 * p[i] + u;
            u = p[i] / 10;
            p[i] %= 10;
        }
        if (u)
            p.push_back(u);
    }

    for (int i = p.size() - 1; i >= 0; i--)
        cout << p[i];
}
