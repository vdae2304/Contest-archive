#include <bits/stdc++.h>
using namespace std;
#define MAXN 301

int N, M, X, maxOro = -1, minArea;
int v[MAXN][MAXN], DP[MAXN][MAXN];

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> M >> X;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) {
            cin >> v[i][j];
            DP[i][j] = v[i][j] + DP[i][j - 1] + DP[i - 1][j] - DP[i - 1][j - 1];
        }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            for (int x = i; x <= N; x++) {
                int y1 = j, y2 = M;
                while (y1 < y2) {
                    int y = (y1 + y2 + 1) / 2;
                    int Oro = DP[x][y] - DP[x][j - 1] - DP[i - 1][y] + DP[i - 1][j - 1];
                    if (Oro > X)
                        y2 = y - 1;
                    else
                        y1 = y;
                }

                int Oro = DP[x][y1] - DP[x][j - 1] - DP[i - 1][y1] + DP[i - 1][j - 1];
                if (X >= Oro && Oro > maxOro) {
                    maxOro = Oro;
                    minArea = (x - i + 1) * (y1 - j + 1);
                }
                else if (Oro == maxOro)
                    minArea = min(minArea, (x - i + 1) * (y1 - j + 1));
            }

    cout << maxOro << " " << minArea;
}
