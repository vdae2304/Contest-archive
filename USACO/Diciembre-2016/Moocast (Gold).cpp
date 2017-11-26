#include <bits/stdc++.h>
using namespace std;

int N;
bool visited[1000];
pair<int, int> v[1000];

int dist(pair<int, int> a, pair<int, int> b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int dfs(int node, int X) {
    int total = 1;
    visited[node] = true;    
    for (int i = 0; i < N; i++)
        if (!visited[i] && dist(v[node], v[i]) <= X)
            total += dfs(i, X);
    return total;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("moocast.in");
    ofstream cout("moocast.out");
    
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> v[i].first >> v[i].second;
    
    int a = 0, b = INT_MAX;
    while (a < b) {
        int m = (a + b) / 2;
        memset(visited, false, sizeof(visited));
        if (dfs(0, m) == N)
            b = m;
        else
            a = m + 1;
    }

    cout << a << "\n";
}
