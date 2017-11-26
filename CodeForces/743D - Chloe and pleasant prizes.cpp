#include <bits/stdc++.h>
using namespace std;
#define MAXN 200001

int N, v[MAXN];
vector<int> tree[MAXN];
long long Sum[MAXN], MaxCut[MAXN], ans = LLONG_MIN;

void DFS(int node, int parent) {
    long long Cut[3] = {LLONG_MIN, LLONG_MIN, LLONG_MIN};
    MaxCut[node] = LLONG_MIN;

    for (int i = 0; i < tree[node].size(); i++)
        if (tree[node][i] != parent) {
            DFS(tree[node][i], node);

            Sum[node] += Sum[tree[node][i]];
            MaxCut[node] = max(MaxCut[node], MaxCut[tree[node][i]]);

            Cut[0] = MaxCut[tree[node][i]];
            sort(Cut, Cut + 3);
        }

    Sum[node] += v[node];
    MaxCut[node] = max(MaxCut[node], Sum[node]);

    if (Cut[1] != LLONG_MIN && Cut[2] != LLONG_MIN)
        ans = max(ans, Cut[1] + Cut[2]);
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> v[i];

    for (int i = 1, u, v; i < N; i++) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    DFS(1, 0);
    if (ans == LLONG_MIN)
        cout << "Impossible\n";
    else
        cout << ans << "\n";
}
