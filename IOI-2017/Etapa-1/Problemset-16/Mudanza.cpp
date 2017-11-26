#include <bits/stdc++.h>
using namespace std;
#define MAXN 10001
typedef pair<int, int> pii;

int N, M, K;
int store[5];
bool isStore[MAXN];

vector<pii> graph[MAXN];
long long minDist[5][MAXN];

void Dijkstra(int u) {
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(make_pair(0, store[u]));
    
    while (!pq.empty()) {
        pii v = pq.top();
        pq.pop();
        
        if (minDist[u][v.second] > v.first) {
            minDist[u][v.second] = v.first;
            for (int i = 0; i < graph[v.second].size(); i++) {
                pii w = make_pair(v.first + graph[v.second][i].first, graph[v.second][i].second);
                if (w.first < minDist[u][w.second])
                    pq.push(w);
            }
        }
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> M >> K;

    for (int i = 0; i < K; i++) {
        cin >> store[i];
        isStore[store[i]] = true;
    }

    for (int i = 0; i < M; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        graph[u].push_back(make_pair(d, v));
        graph[v].push_back(make_pair(d, u));
    }

    for (int i = 0; i < K; i++) {
        for (int j = 1; j <= N; j++)
            minDist[i][j] = INFINITY;
        Dijkstra(i);
    }

    int order[K], ans = INFINITY;
    for (int i = 0; i < K; i++)
        order[i] = i;

    do {
        for (int i = 1; i <= N; i++)
            if (!isStore[i]) {
                int total = minDist[order[0]][i] + minDist[order[K - 1]][i];
                for (int j = 1; j < K; j++)
                    total += minDist[order[j]][store[order[j - 1]]];
                ans = min(ans, total);
            }
    }
    while (next_permutation(order, order + K));

    cout << ans;
}
