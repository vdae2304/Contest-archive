#include <bits/stdc++.h>
using namespace std;
#define MAXN 100

int N, M;
char grid[MAXN][MAXN];
bool R[MAXN], C[MAXN];

void Operation(int r) {
    queue<int> row, col;
    row.push(r);
    R[r] = true;

    while (!row.empty()) {
        r = row.front();
        row.pop();

        for (int i = 0; i < M; i++)
            if (grid[r][i] == '#') {
                if (!C[i])
                    col.push(i);
                C[i] = true;
            }

        while (!col.empty()) {
            int c = col.front();
            col.pop();

            for (int i = 0; i < N; i++)
                if (grid[i][c] == '#') {
                    if (!R[i])
                        row.push(i);
                    R[i] = true;
                }
        }
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (R[i] && C[j] && grid[i][j] != '#') {
                cout << "No\n";
                exit(0);
            }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> grid[i][j];

    for (int i = 0; i < N; i++) {
        memset(R, false, sizeof R);
        memset(C, false, sizeof C);
        Operation(i);
    }

    cout << "Yes\n";
    return 0;
}
