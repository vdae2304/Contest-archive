#include <bits/stdc++.h>
using namespace std;
#define MAXN 1001

int N, A, B, v[MAXN][MAXN];
int corner[4][MAXN * MAXN];

bool check(int i, int j, int c) {
    if (corner[0][i] <= corner[0][j]) {
        if (corner[1][i] <= corner[1][j]) {
            if (corner[0][j] <= corner[2][i] && corner[1][j] <= corner[3][i]) {
                for (int x = corner[0][j]; x <= min(corner[2][i], corner[2][j]); x++)
                    for (int y = corner[1][j]; y <= min(corner[3][i], corner[3][j]); y++)
                        if (v[x][y] == c)
                            return true;
            }
        }
        else {
            if (corner[0][j] <= corner[2][i] && corner[3][j] >= corner[1][i]) {
                for (int x = corner[0][j]; x <= min(corner[2][i], corner[2][j]); x++)
                    for (int y = corner[1][i]; y <= min(corner[3][j], corner[3][i]); y++)
                        if (v[x][y] == c)
                            return true;
            }
        }
    }
    return false;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("art.in");
    ofstream cout("art.out");
    cin >> N;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> v[i][j];

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            if (!corner[0][v[i][j]])
                corner[0][v[i][j]] = i;
            if (!corner[1][v[i][j]] || j < corner[1][v[i][j]])
                corner[1][v[i][j]] = j;
            corner[2][v[i][j]] = i;
            if (!corner[3][v[i][j]] || j > corner[3][v[i][j]])
                corner[3][v[i][j]] = j;
        }

    for (int i = 1; i <= N * N; i++) {
        if (!corner[0][i])
            A++;
        else {
            bool candidate = true;
            for (int j = 1; candidate && j <= N * N; j++)
                if (i != j && corner[0][j] && (check(i, j, i) || check(j, i, i)))
                    candidate = false;
            B += candidate;
        }
    }

    A += (A == N * N - 1 && B == 1) ? 0 : B;
    cout << A << "\n";
}
