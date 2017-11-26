#include <bits/stdc++.h>
using namespace std;
#define MAXN 100002
typedef multimap<int, int>::iterator it;

int N, dist[MAXN];
pair<int, int> v[MAXN];
multimap<int, int> w[2];

void BFS() {
    queue<pair<int, int> > q;
    q.push(make_pair(0, 1));
    dist[0] = 1;

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        pair<it, it> aux[2] = {w[0].equal_range(v[p.first].first), w[1].equal_range(v[p.first].second)};
        for (int i = 0; i < 2; i++)
            for (it j = aux[i].first; j != aux[i].second; ) {
                if (!dist[j -> second]) {
                    q.push(make_pair(j -> second, p.second + 1));
                    dist[j -> second] = p.second + 1;
                }
                w[i].erase(j++);
            }
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("lasers.in");
    ofstream cout("lasers.out");
    cin >> N;

    for (int i = 0; i < N + 2; i++) {
        cin >> v[i].first >> v[i].second;
        w[0].insert(make_pair(v[i].first, i));
        w[1].insert(make_pair(v[i].second, i));
    }

    BFS();
    cout << max(dist[1] - 2, -1);
}
