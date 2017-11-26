#include <bits/stdc++.h>
using namespace std;

int N, M, R, C;
char Mapa[51][51];
int visitado[51][51];

bool posible(int i, int j, int h) {
    if (i < 1 || i > N || j < 1 || j > M || Mapa[i][j] == '.' || visitado[i][j] == h + 1)
        return false;
    if (i == R && j == C)
        return true;

    visitado[i][j] = h + 1;
    for (int k = 1; k <= h; k++)
        if (posible(i - k, j, h) || posible(i + k, j, h))
            return true;

    return posible(i, j - 1, h) || posible(i, j + 1, h);
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> M >> R >> C;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> Mapa[i][j];

    for (int i = 0; i <= N; i++)
        if (posible(N, M, i)) {
            cout << i;
            return 0;
        }
}
