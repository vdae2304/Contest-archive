#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000
typedef pair<int, int> pii;

int N, v[MAXN];
bool inTree[MAXN];

long long Prim() {
    long long cost = 0;
    priority_queue<pii> pq;
    pq.push(pii(0, 0));

    while (!pq.empty()) {
        pii p = pq.top();
        pq.pop();

        if (!inTree[p.second]) {
            inTree[p.second] = true;
            cost -= p.first;

            for (int i = 0; i < N; i++)
                if (!inTree[i])
                    pq.push(pii(-min(v[p.second] % v[i], v[i] % v[p.second]), i));
        }
    }
    return cost;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> v[i];

    cout << Prim() << "\n";
}
