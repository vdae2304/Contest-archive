/*
ID: vdae_231
PROG: butter
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N, P, C, ans = INFINITY;
int pasture[500], dist[801][801];
vector<pii> graph[801];

void Dijkstra(int node) {
    priority_queue<pii> pq;
    pq.push(pii(0, node));

    while (!pq.empty()) {
        pii p = pq.top();
        pq.pop();

        if (dist[node][p.second] == -1) {
            dist[node][p.second] = -p.first;
            for (int i = 0; i < graph[p.second].size(); i++)
                pq.push(pii(p.first - graph[p.second][i].first, graph[p.second][i].second));
        }
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("butter.in");
    ofstream cout("butter.out");
    cin >> N >> P >> C;

    for (int i = 0; i < N; i++)
        cin >> pasture[i];

    while (C--) {
        int u, v, d;
        cin >> u >> v >> d;
        graph[u].push_back(pii(d, v));
        graph[v].push_back(pii(d, u));
    }

    memset(dist, -1, sizeof(dist));
    for (int i = 1; i <= P; i++)
        Dijkstra(i);

    for (int i = 1; i <= P; i++) {
        int total = 0;
        for (int j = 0; j < N; j++)
            total += dist[i][pasture[j]];
        ans = min(ans, total);
    }

    cout << ans << "\n";
}
