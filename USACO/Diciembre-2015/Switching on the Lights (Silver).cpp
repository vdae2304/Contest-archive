#include <bits/stdc++.h>
using namespace std;

struct point {
    int x, y;
};

int N, M, answer;
bool visited[102][102], on[102][102];
vector<point> switches[102][102];

bool hasVisitedNeighbor(int i, int j) {
    return visited[i - 1][j] || visited[i][j - 1] || visited[i][j + 1] || visited[i + 1][j];
}

void solve(int i, int j) {
    if (i < 1 || i > N || j < 1 || j > N || visited[i][j] || !on[i][j])
        return;
    visited[i][j] = true;
    for (point nx : switches[i][j]) {
        on[nx.x][nx.y] = true;
        if (hasVisitedNeighbor(nx.x, nx.y))
            solve(nx.x, nx.y);
    }
    solve(i - 1, j);
    solve(i, j - 1);
    solve(i, j + 1);
    solve(i + 1, j);
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("lightson.in");
    ofstream cout("lightson.out");
    cin >> N >> M;

    while (M--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        switches[x][y].push_back(point {a, b});
    }
    on[1][1] = true;
    solve(1, 1);

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (on[i][j])
                answer++;
    cout << answer;
}
