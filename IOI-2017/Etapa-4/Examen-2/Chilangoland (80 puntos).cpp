#include <bits/stdc++.h>
using namespace std;
#define MAXN 5001
typedef pair<int, int> pii;

int N, M;
vector<int> tree[MAXN];
int dist[MAXN][MAXN];

void BFS(int u) {
    queue<pii> pq;
    pq.push(pii(0, u));

    while (!pq.empty()) {
        pii p = pq.front();
        pq.pop();

        if (dist[u][p.second] == -1) {
            dist[u][p.second] = p.first;
            for (int v : tree[p.second])
                pq.push(pii(p.first + 1, v));
        }
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int u, v;
    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    memset(dist, -1, sizeof dist);
    for (int i = 1; i <= N; i++)
        BFS(i);

    cin >> M;
    while (M--) {
        int ans = 0;
        cin >> u >> v;
        for (int i = 1; i <= N; i++)
            ans = max(ans, min(dist[i][u], dist[i][v]));
        cout << ans << "\n";
    }
}
