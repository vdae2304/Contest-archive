#include <bits/stdc++.h>
using namespace std;
#define MAXN 40001

int N[2], dist[2][2][MAXN], u, v;
long long dm[2][2], T[2][MAXN], S[MAXN];
vector<int> tree[2][MAXN];

int BFS(int nt, int m, int node) {
    queue<int> q;
    q.push(node);
    dist[nt][m][node] = 0;

    while (!q.empty()) {
        node = q.front();
        q.pop();

        for (int i = 0; i < tree[nt][node].size(); i++)
            if (dist[nt][m][tree[nt][node][i]] == -1) {
                dist[nt][m][tree[nt][node][i]] = dist[nt][m][node] + 1;
                q.push(tree[nt][node][i]);
            }
    }

    return node;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cout << setprecision(3) << fixed;
    while (cin >> N[0] >> N[1]) {
        double ans = 0;
        memset(dist, -1, sizeof(dist));

        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= N[i]; j++)
                tree[i][j].clear();

            for (int j = 0; j < N[i] - 1; j++) {
                cin >> u >> v;
                tree[i][u].push_back(v);
                tree[i][v].push_back(u);
            }
        }

        for (int i = 0; i < 2; i++) {
            dm[i][0] = BFS(i, 0, 1);
            memset(dist[i][0], -1, sizeof(dist[i][0]));
            dm[i][1] = BFS(i, 0, dm[i][0]);
            BFS(i, 1, dm[i][1]);
        }
        long long dM = max(dist[0][0][dm[0][1]], dist[1][0][dm[1][1]]);

        for (int i = 0; i < 2; i++)
            for (int j = 1; j <= N[i]; j++)
                T[i][j - 1] = max(dist[i][0][j], dist[i][1][j]);
        sort(T[1], T[1] + N[1]);

        S[N[1]] = 0;
        for (int i = N[1] - 1; i >= 0; i--)
            S[i] = S[i + 1] + T[1][i];

        for (int i = 0; i < N[0]; i++) {
            int k = distance(T[1], upper_bound(T[1], T[1] + N[1], dM - T[0][i] - 1));
            ans += dM * k + S[k] + (N[1] - k) * (T[0][i] + 1);
        }
        cout << ans / (N[0] * N[1]) << "\n";
    }
}
