#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> pll;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N;
    cin >> N;

    pll v[N];
    for (int i = 0; i < N; i++)
        cin >> v[i].first >> v[i].second;
    sort(v, v + N);

    stack<int> p;
    long long area = 0;
    for (int i = 0; i < N; i++) {
        while (!p.empty() && v[i].second >= v[p.top()].second) {
            int j = p.top();
            p.pop();
            area -= (v[j].first - (p.empty() ? 0 : v[p.top()].first)) * v[j].second;
        }
        area += (v[i].first - (p.empty() ? 0 : v[p.top()].first)) * v[i].second;;
        p.push(i);
    }

    cout << area << "\n";
}
