/*
ID: vdae_231
PROG: maze1
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int N, M;
char Maze[201][77];
int mov[2][4] = {{-1, 0, 0, 1}, {0, -1, 1, 0}};
queue<pair<int, int> > bfs;

int solve() {
    int steps = 0;
    while (!bfs.empty()) {
        int l = bfs.size();
        steps++;
        for (int i = 0; i < l; i++) {
            pair<int, int> q = bfs.front();
            bfs.pop();

            if (q.first < 0 || q.first >= M || q.second < 0 || q.second >= N || Maze[q.first][q.second] != ' ')
                continue;
            Maze[q.first][q.second] = '#';

            for (int j = 0; j < 4; j++)
                bfs.push(make_pair(q.first + mov[0][j], q.second + mov[1][j]));
        }
    }
    return (steps - 1) / 2;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("maze1.in");
    ofstream cout("maze1.out");
    cin >> N >> M;
    cin.get();

    N = 2 * N + 1;
    M = 2 * M + 1;

    for (int i = 0; i < M; i++)
        cin.getline(Maze[i], N + 1);

    for (int i = 0; i < M; i++) {
        if (Maze[i][0] == ' ')
            bfs.push(make_pair(i, 0));
        if (Maze[i][N - 1] == ' ')
            bfs.push(make_pair(i, N - 1));
    }
    for (int j = 0; j < N; j++) {
        if (Maze[0][j] == ' ')
            bfs.push(make_pair(0, j));
        if (Maze[M - 1][j] == ' ')
            bfs.push(make_pair(M - 1, j));
    }

    cout << solve() << "\n";
}
