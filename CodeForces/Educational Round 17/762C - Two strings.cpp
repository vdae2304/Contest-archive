#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    string a, b;
    cin >> a >> b;

    vector<pii> v (1, pii(b.size(), a.size()));
    for (int i = b.size() - 1, j = a.size(); i >= 0; i--) {
        for (j--; j >= 0 && a[j] != b[i]; j--);
        if (j >= 0)
            v.push_back(pii(i, j));
        else
            break;
    }

    vector<pii> w (1, pii(-1, -1));
    for (int i = 0, j = -1; i < b.size(); i++) {
        for (j++; j < a.size() && a[j] != b[i]; j++);
        if (j < a.size())
            w.push_back(pii(i, j));
        else
            break;
    }

    int l = -1, r = b.size();
    for (int i = 0, j = v.size() - 1; i < w.size(); i++) {
        for (; v[j].first <= w[i].first || v[j].second <= w[i].second; j--);        
        if (v[j].first - w[i].first < r - l)
            l = w[i].first, r = v[j].first;
    }

    if (l == -1 && r == b.size())
        cout << "-";
    else {
        for (int i = 0; i <= l; i++)
            cout << b[i];
        for (int i = r; i < b.size(); i++)
            cout << b[i];
    }
}
