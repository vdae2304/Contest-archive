#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, char> tic;

bool compare(pii a, pii b) {
    return pii(abs(a.first), abs(a.second)) < pii(abs(b.first), abs(b.second));
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N;
    cin >> N;

    pii v[N];
    for (int i = 0; i < N; i++)
        cin >> v[i].first >> v[i].second;
    sort(v, v + N, compare);

    vector<tic> op;
    for (int i = 0; i < N; i++) {
        if (v[i].first != 0)
            op.push_back(tic(1, abs(v[i].first), v[i].first > 0 ? 'R' : 'L'));
        if (v[i].second != 0)
            op.push_back(tic(1, abs(v[i].second), v[i].second > 0 ? 'U' : 'D'));
        op.push_back(tic(2, 0, 0));
        if (v[i].first != 0)
            op.push_back(tic(1, abs(v[i].first), v[i].first > 0 ? 'L' : 'R'));
        if (v[i].second != 0)
            op.push_back(tic(1, abs(v[i].second), v[i].second > 0 ? 'D' : 'U'));
        op.push_back(tic(3, 0, 0));
    }

    cout << op.size();
    for (tic x : op) {
        cout << "\n" << get<0>(x);
        if (get<0>(x) == 1)
            cout << " " << get<1>(x) << " " << get<2>(x);
    }
}
