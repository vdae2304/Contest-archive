#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001

int N, K, Q, A[25];
int DP[MAXN][17], P[MAXN], L[MAXN];
vector<int> tree[MAXN];

void DFS(int u) {
    for (int i = 0; i < tree[u].size(); i++)
        if (tree[u][i] != P[u]) {
            DP[tree[u][i]][0] = P[tree[u][i]] = u;
            L[tree[u][i]] = L[u] + 1;
            DFS(tree[u][i]);
        }
}

int getLCA(int u, int v) {
    if (L[u] > L[v])
        swap(u, v);

    for (int i = 16; i >= 0; i--)
        if (L[v] - L[u] >= 1 << i)
            v = DP[v][i];
    if (u == v)
        return u;

    for (int i = 16; i >= 0; i--)
        if (DP[u][i] && DP[u][i] != DP[v][i])
            u = DP[u][i], v = DP[v][i];
    return P[u];
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int u, v, t;
    cin >> N >> K >> Q;

    for (int i = 0; i < K; i++)
        cin >> A[i];

    for (int i = 0; i < N - 1; i++) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    DFS(1);
    for (int j = 1; j < 17; j++)
        for (int i = 1; i <= N; i++)
            DP[i][j] = DP[DP[i][j - 1]][j - 1];

    while (Q--) {
        cin >> u >> v >> t;

        int x = v, y = u;
        for (int i = 0; i < K; i++) {
            if (L[A[i]] - 2 * L[getLCA(u, A[i])] < L[x] - 2 * L[getLCA(u, x)])
                x = A[i];
            if (L[A[i]] - 2 * L[getLCA(v, A[i])] < L[y] - 2 * L[getLCA(v, y)])
                y = A[i];
        }

        cout << min(L[u] + L[x] - 2 * L[getLCA(u, x)] + t + L[y] + L[v] - 2 * L[getLCA(y, v)],
                    L[u] + L[v] - 2 * L[getLCA(u, v)]) << "\n";
    }
}
