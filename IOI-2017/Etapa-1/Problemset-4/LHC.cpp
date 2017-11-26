#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N;
    double t = INFINITY;
    cin >> N;

    int x[N], v[N];
    stack<int> p, q;
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> v[i];
        if (v[i] > 0)
            p.push(i);
        else
            while (!p.empty()) {
                t = min(t, double(x[i] - x[p.top()]) / (v[p.top()] - v[i]));
                if (-v[i] <= v[p.top()])
                    break;
                p.pop();
            }
    }

    for (int i = N - 1; i >= 0; i--) {
        if (v[i] < 0)
            q.push(i);
        else
            while (!q.empty()) {
                t = min(t, double(x[i] - x[q.top()]) / (v[q.top()] - v[i]));
                if (-v[i] <= v[q.top()])
                    break;
                q.pop();
            }
    }

    if (t == INFINITY)
        cout << "-1";
    else
        cout << setprecision(6) << fixed << t;
}
