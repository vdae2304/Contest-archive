#include <bits/stdc++.h>
using namespace std;
#define MAXN 101

int N, ans;
bool edge[MAXN][MAXN], vis[MAXN];

void DFS(int u) {
    vis[u] = true;
    for (int v = 1; v <= N; v++) {
        if (!vis[v]) {
            edge[u][v] = edge[v][u] = true;
            ans++;
            DFS(v);
        }
        else if (u != v && !edge[u][v]) {
            bool cycle = false;
            for (int i = 1; i <= N; i++)
                if (i != u && i != v && edge[u][i] && edge[i][v])
                    cycle = true;
            if (!cycle) {
                edge[u][v] = edge[v][u] = true;
                ans++;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;
    DFS(1);

    cout << ans << "\n";
    for (int i = 1; i <= N; i++)
        for (int j = i; j <= N; j++)
            if (edge[i][j])
                cout << i << " " << j << "\n";

}
