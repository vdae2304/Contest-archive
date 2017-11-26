#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001

int N, M;
vector<unsigned short> graph[MAXN];

int id[MAXN], total;
vector<pair<int, int> > ans;

int Find_Bridges(int u, int parent) {
    id[u] = total++;
    int low = id[u];
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (!id[v]) {
            int low_v = Find_Bridges(v, u);
            low = min(low, low_v);
            if (low_v > id[u])
                ans.push_back(make_pair(min(u, v), max(u, v)));
        }
        else if (v != parent)
            low = min(low, id[v]);
    }
    return low;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> M;

    while (M--) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; i++)
        if (!id[i])
            Find_Bridges(i, 0);

    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].first << " " << ans[i].second << "\n";
}
