#include <bits/stdc++.h>
using namespace std;
#define MAXN 5001

int N, ans, v[MAXN];
bool vis[MAXN][MAXN];
long long dist[MAXN];

int Checar(int x, int y, int d) {
    for (int ini = x, ret = 1; ret <= N; ret++) {
        if (vis[x][y] || y == -1 || dist[N] % d)
            return 0;
        vis[x][y] = vis[y][x] = true;
        if (y == ini)
            return ret;
        int z = binary_search(dist, dist + N, (dist[y] + d) % dist[N]) ?
                lower_bound(dist, dist + N, (dist[y] + d) % dist[N]) - dist : -1;
        x = y;
        y = z;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> v[i];
        dist[i] = dist[i - 1] + v[i];
    }

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            ans = max(ans, Checar(i, j, dist[j] - dist[i]));
    cout << ans;
}
