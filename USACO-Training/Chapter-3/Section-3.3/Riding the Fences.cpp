/*
ID: vdae_231
PROG: fence
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int F, u, v;
int Degree[501], graph[501][501];
vector<int> circuit;

void Eulerian_Tour(int node) {
    for (int i = 1; i <= 500; i++)
        while (graph[node][i]) {
            graph[node][i]--;
            graph[i][node]--;
            Eulerian_Tour(i);
        }
    circuit.push_back(node);
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("fence.in");
    ofstream cout("fence.out");
    cin >> F;

    while (F--) {
        cin >> u >> v;
        graph[u][v]++;
        graph[v][u]++;
        Degree[u]++;
        Degree[v]++;
    }
    
    u = INFINITY;
    for (int i = 1; i <= 500; i++)
        if (Degree[i] % 2) {
            u = i;
            break;
        }
        else if (Degree[i] > 0)
            u = min(u, i);
    
    Eulerian_Tour(u);
    for (int i = circuit.size() - 1; i >= 0; i--)
        cout << circuit[i] << "\n";
}
