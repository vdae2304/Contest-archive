/*
ID: vdae_231
PROG: agrinet
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int N, cost;
int weight[100][100];
int dist[100];
bool inTree[100];

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("agrinet.in");
    ofstream cout("agrinet.out");
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> weight[i][j];
    fill(dist + 1, dist + N, 1 << 30);

    for (int i = 0; i < N; i++) {
        int node = -1;
        for (int j = 0; j < N; j++)
            if (!inTree[j] && (node == -1 || dist[j] < dist[node]))
                node = j;
        inTree[node] = true;
        cost += dist[node];
        for (int j = 0; j < N; j++)
            dist[j] = min(dist[j], weight[node][j]);
    }

    cout << cost << "\n";
}
