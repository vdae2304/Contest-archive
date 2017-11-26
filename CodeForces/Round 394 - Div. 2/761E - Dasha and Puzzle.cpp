#include <bits/stdc++.h>
using namespace std;
#define MAXN 31

int N;
int mov[2][4] = {{-1, 0, 0, 1}, {0, -1, 1, 0}};
long long X[MAXN], Y[MAXN];
vector<int> graph[MAXN];

void BuildTree(int node, int parent, int dir, long long dist) {
    if (graph[node].size() > 4) {
        cout << "NO\n";
        exit(0);
    }

    for (int i = 0, j = 0; i < graph[node].size(); i++)
        if (graph[node][i] != parent) {
            if (dir == 3 - j)
                j = (j + 1) % 4;

            X[graph[node][i]] = X[node] + dist * mov[0][j];
            Y[graph[node][i]] = Y[node] + dist * mov[1][j];
            BuildTree(graph[node][i], node, j, dist / 2);

            j = (j + 1) % 4;
        }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    BuildTree(1, 1, -1, 1ll << MAXN);

    cout << "YES\n";
    for (int i = 1; i <= N; i++)
        cout << X[i] << " " << Y[i] << "\n";
}
