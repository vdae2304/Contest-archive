/*
ID: vdae_231
PROG: stall4
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
#define MAXN 402

int N, M, total;
int graph[MAXN][MAXN];
int flow[MAXN], parent[MAXN];
bool visited[MAXN];

void Dijkstra() {
    memset(parent, 0, sizeof(parent));
    memset(flow, 0, sizeof(flow));
    memset(visited, false, sizeof(visited));
    flow[0] = INFINITY;

    while (true) {
        int current = -1, max_flow = 0;
        for (int i = 0; i <= N + M + 1; i++)
            if (!visited[i] && flow[i] > max_flow)
                current = i, max_flow = flow[i];

        if (current == -1 || current == N + M + 1)
            return;
        visited[current] = true;

        for (int i = 0; i <= N + M + 1; i++)
            if (flow[i] < min(max_flow, graph[current][i])) {
                parent[i] = current;
                flow[i] = min(max_flow, graph[current][i]);
            }
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("stall4.in");
    ofstream cout("stall4.out");
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        graph[0][i] = 1;
    for (int i = 1; i <= M; i++)
        graph[N + i][N + M + 1] = 1;

    for (int i = 1; i <= N; i++) {
        int S, stall;
        cin >> S;
        while (S--) {
            cin >> stall;
            graph[i][N + stall] = 1;
        }
    }

    Dijkstra();
    while (flow[N + M  + 1]) {
        total += flow[N + M + 1];
        for (int i = N + M + 1; parent[i] != i; i = parent[i]) {
            graph[parent[i]][i] -= flow[N + M + 1];
            graph[i][parent[i]] += flow[N + M + 1];
        }
        Dijkstra();
    }

    cout << total << "\n";
}
