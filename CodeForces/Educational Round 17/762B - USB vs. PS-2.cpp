#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int A, B, C, M;
    cin >> A >> B >> C >> M;

    vector<int> v[2];
    while (M--) {
        int price; string port;
        cin >> price >> port;
        v[port != "USB"].push_back(price);
    }
    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());

    long long computers = 0, cost = 0;
    for (int i = 0; i < A && i < v[0].size(); i++, computers++)
        cost += v[0][i];
    for (int i = 0; i < B && i < v[1].size(); i++, computers++)
        cost += v[1][i];
    for (int i = A, j = B; C && (i < v[0].size() || j < v[1].size()); C--, computers++) {
        if (j >= v[1].size() || (i < v[0].size() && v[0][i] < v[1][j]))
            cost += v[0][i++];
        else
            cost += v[1][j++];
    }

    cout << computers << " " << cost << "\n";
}
