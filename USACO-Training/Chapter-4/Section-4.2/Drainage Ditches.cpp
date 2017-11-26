/*
ID: vdae_231
PROG: ditch
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
#define MAXM 201

int N, M, total;
int capacity[MAXM][MAXM];
int flow[MAXM], parent[MAXM];
bool visited[MAXM];

void Dijkstra() {
    memset(parent, 0, sizeof(parent));
    memset(flow, 0, sizeof(flow));
    memset(visited, false, sizeof(visited));
    flow[1] = INFINITY;

    while (true) {
        int current = -1, max_flow = 0;
        for (int i = 1; i <= M; i++)
            if (!visited[i] && flow[i] > max_flow)
                current = i, max_flow = flow[i];

        if (current == -1 || current == M)
            return;
        visited[current] = true;

        for (int i = 1; i <= M; i++)
            if (flow[i] < min(max_flow, capacity[current][i])) {
                parent[i] = current;
                flow[i] = min(max_flow, capacity[current][i]);
            }
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("ditch.in");
    ofstream cout("ditch.out");
    cin >> N >> M;

    while (N--) {
        int S, E, C;
        cin >> S >> E >> C;
        capacity[S][E] += C;
    }

    Dijkstra();
    while (flow[M]) {
        total += flow[M];
        for (int node = M; parent[node] != node; node = parent[node]) {
            capacity[parent[node]][node] -= flow[M];
            capacity[node][parent[node]] += flow[M];
        }
        Dijkstra();
    }

    cout << total << "\n";
}
