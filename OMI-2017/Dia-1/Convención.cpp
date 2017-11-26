#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N, M, u, v, ans = 1;
    cin >> N >> M;

    vector<int> edge[N];
    while (M--) {
        cin >> u >> v;
        if (u < v)
            swap(u, v);
        edge[u].push_back(v);
    }

    for (int ini = 0, i = 1, j; i < N; i++) {
        sort(edge[i].begin(), edge[i].end());
        for (j = 0; j < edge[i].size() && edge[i][j] < ini; j++);

        if (edge[i].size() - j == i - ini)
            ans = max(ans, i - ini + 1);
        else {
            ini = i;
            for (j = edge[i].size() - 1; j >= 0; j--)
                if (edge[i][j] == ini - 1)
                    ini--;
        }
    }

    cout << ans;
}
