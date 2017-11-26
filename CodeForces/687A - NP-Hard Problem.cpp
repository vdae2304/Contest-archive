#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001

int N, M, u, v;
int S[2], subset[MAXN];
vector<int> graph[MAXN];

void DFS(int node, int component) {
    subset[node] = component;
    S[component]++;
    for (int i = 0; i < graph[node].size(); i++) {
        if (subset[graph[node][i]] == -1)
            DFS(graph[node][i], !component);
        else if (subset[graph[node][i]] == component) {
            cout << "-1\n";
            exit(0);
        }
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> M;

    while (M--) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    memset(subset, -1, sizeof(subset));
    for (int i = 1; i <= N; i++)
        if (subset[i] == -1)
            DFS(i, 0);

    for (int i = 0; i < 2; i++) {
        cout << S[i] << "\n";
        for (int j = 1; j <= N; j++)
            if (subset[j] == i)
                cout << j << " ";
        cout << "\n";
    }
}
