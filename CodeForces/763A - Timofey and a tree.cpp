#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001

int N, color[MAXN];
vector<int> tree[MAXN];

bool checkRoot(int node, int parent, int ccolor) {
    for (int i = 0; i < tree[node].size(); i++)
        if (tree[node][i] != parent && !checkRoot(tree[node][i], node, ccolor))
            return false;
    return color[node] == ccolor;
}

int DFS(int node, int parent) {
    bool valid = true;
    for (int i = 0; i < tree[node].size(); i++)
        if (tree[node][i] != parent && DFS(tree[node][i], node) != color[node])
            valid = false;

    if (valid)
        return color[node];
    else {
        if (checkRoot(parent, node, color[parent]))
            cout << "YES\n" << node << "\n";
        else
            cout << "NO\n";
        exit(0);
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;

    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    for (int i = 1; i <= N; i++)
        cin >> color[i];

    DFS(1, 0);
    cout << "YES\n1\n";
}
