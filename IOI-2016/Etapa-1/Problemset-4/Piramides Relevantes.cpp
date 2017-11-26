#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N;
    cin >> N;

    stack<int> p, q;
    int h[N], r[N], d[N];
    for (int i = 0; i < N; i++) {
        cin >> h[i] >> r[i];
        d[i] = r[i];

        while (!p.empty() && h[p.top()] < h[i]) {
            d[i] = max(d[i], d[p.top()]);
            p.pop();
        }
        if (!p.empty())
            d[i] = max(d[i], r[p.top()]);

        p.push(i);
   }

   for (int i = N - 1; i >= 0; i--) {
        while (!q.empty() && h[q.top()] < h[i]) {
            d[i] = max(d[i], d[q.top()]);
            q.pop();
        }
        if (!q.empty())
            d[i] = max(d[i], r[q.top()]);

        q.push(i);
    }

    for (int i = 0; i < N; i++)
        cout << d[i] << " ";
}
