#include <bits/stdc++.h>
using namespace std;
#define MAXN 200001
typedef pair<int, int> pii;

int N, last;
bool color[MAXN], visited[MAXN];
vector<int> tree[MAXN], T[MAXN];

//Join all the nodes with same color and create a new tree
int DFS(int node, int parent, bool current_color, int component) {
    if (current_color != color[node]) {
        component = ++last;
        current_color = !current_color;
    }

    for (int i = 0; i < tree[node].size(); i++)
        if (tree[node][i] != parent) {
            int aux = DFS(tree[node][i], node, current_color, component);
            if (aux != component) {
                T[component].push_back(aux);
                T[aux].push_back(component);
            }
        }
    return component;
}

//Return farthest node that can be visited and the distance
pii BFS(int node) {
    queue<pii> q;
    pii p;

    q.push(pii(node, 1));
    memset(visited, false, sizeof(visited));
    visited[node] = true;

    while (!q.empty()) {
        p = q.front();
        q.pop();
        for (int i = 0; i < T[p.first].size(); i++)
            if (!visited[T[p.first][i]]) {
                visited[T[p.first][i]] = true;
                q.push(pii(T[p.first][i], p.second + 1));
            }
    }

    return p;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> color[i];

    for (int i = 1, u, v; i < N; i++) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    DFS(1, 1, !color[1], 0);
    cout << BFS(BFS(1).first).second / 2 << "\n";
}
