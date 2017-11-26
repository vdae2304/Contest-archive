/*
ID: vdae_231
PROG: camelot
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
#define MAXR 34
#define MAXC 30

struct point {
    int x, y, t;
};

int N, M;
point Kpos;
vector<point> v;

int King[MAXR][MAXC][MAXR][MAXC];
int Knight[MAXR][MAXC][MAXR][MAXC];
int dX[8] = {-1, -2, -2, -1, 1, 2, 2, 1},
    dY[8] = {-2, -1, 1, 2, -2, -1, 1, 2};

void BFS_Knight(int r, int c) {
    queue<point> q;
    q.push(point {r, c, 0});
    Knight[r][c][r][c] = 0;
    while (!q.empty()) {
        for (int i = 0; i < 8; i++) {
            point nx = {q.front().x + dX[i], q.front().y + dY[i], q.front().t + 1};
            if (1 < nx.x && nx.x < N + 2 && 1 < nx.y && nx.y < M + 2 && Knight[r][c][nx.x][nx.y] == INT_MAX) {
                Knight[r][c][nx.x][nx.y] = Knight[nx.x][nx.y][r][c] = nx.t;
                q.push(nx);
            }
        }
        q.pop();
    }
}

void BFS_King(int r, int c) {
    queue<point> q;
    q.push(point {r, c, 0});
    King[r][c][r][c] = 0;
    while (!q.empty()) {
        for (int i = -1; i <= 1; i++)
            for (int j = -1; j <= 1; j++) {
                point nx = {q.front().x + i, q.front().y + j, q.front().t + 1};
                if (1 < nx.x && nx.x < N + 2 && 1 < nx.y && nx.y < M + 2 && King[r][c][nx.x][nx.y] == INT_MAX) {
                    King[r][c][nx.x][nx.y] = King[nx.x][nx.y][r][c] = nx.t;
                    q.push(nx);
                }
            }
        q.pop();
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("camelot.in");
    ofstream cout("camelot.out");
    cin >> N >> M;

    for (int i = 0; i < MAXR; i++)
        for (int j = 0; j <  MAXC; j++)
            for (int k = 0; k < MAXR; k++)
                for (int l = 0; l < MAXC; l++)
                    King[i][j][k][l] = Knight[i][j][k][l] = INT_MAX;

    for (int i = 2; i < N + 2; i++)
        for (int j = 2; j < M + 2; j++) {
            BFS_Knight(i, j);
            BFS_King(i, j);
        }

    char c; int r;
    cin >> c >> r;
    Kpos = {r + 1, c - 'A' + 2, 0};

    while (cin >> c >> r)
        v.push_back(point {r + 1, c - 'A' + 2, 0});

    long long ans = INFINITY;
    for (int i = 2; i < N + 2; i++)
        for (int j = 2; j < M + 2; j++) {
            long long total = King[Kpos.x][Kpos.y][i][j];
            for (int k = 0; k < v.size(); k++)
                total += Knight[v[k].x][v[k].y][i][j];
            ans = min(ans, total);

            for (int k = 0; k < v.size(); k++)
                for (int l = -2; l <= 2; l++)
                    for (int m = -2; m <= 2; m++) {
                        ans = min(ans, total - King[Kpos.x][Kpos.y][i][j] - Knight[v[k].x][v[k].y][i][j]
                                  + Knight[v[k].x][v[k].y][Kpos.x + l][Kpos.y + m] + King[Kpos.x][Kpos.y][Kpos.x + l][Kpos.y + m]
                                  + Knight[Kpos.x + l][Kpos.y + m][i][j]);
                    }
        }

    cout << ans << "\n";
}
