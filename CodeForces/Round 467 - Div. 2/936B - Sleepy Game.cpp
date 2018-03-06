#include <bits/stdc++.h>
using namespace std;
#define MAXN 200'000

int N, M, S;
vector<int> DAG[MAXN];
int DP[MAXN][2], vis[MAXN], cycle;

void DFS(int u, int p, bool dist) {
    if (vis[u])
        cycle = true;
    if (DP[u][dist])
        return;

    DP[u][dist] = p;
    vis[u] = true;
    for (int v : DAG[u])
        DFS(v, u, !dist);
    vis[u] = false;
}

int Solution() {
    for (int i = 1; i <= N; i++)
        if (!DAG[i].size() && DP[i][1])
            return i;
    return 0;
}

void Print(int u, int dist) {
    if (u != -1) {
        Print(DP[u][dist], !dist);
        cout << u << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> M;

    for (int i = 1, j, c; i <= N; i++) {
        cin >> c;
        while (c--) {
            cin >> j;
            DAG[i].push_back(j);
        }
    }

    cin >> S;
    DFS(S, -1, 0);

    if (Solution()) {
        cout << "Win\n";
        Print(Solution(), 1);
        cout << "\n";
    }
    else if (cycle)
        cout << "Draw\n";
    else
        cout << "Lose\n";
    return 0;
}
