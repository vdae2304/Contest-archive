#include <bits/stdc++.h>
using namespace std;

int N, M;
char Mapa[50][50];
bool visitado[50][50];

void Busqueda(int x, int y, int i, int j, int d) {
    if (i == x && j == y && d >= 4) {
        cout << "Yes";
        exit(0);
    }

    if (visitado[i][j])
        return;
    visitado[i][j] = true;

    if (i > 0 && Mapa[i][j] == Mapa[i - 1][j])
        Busqueda(x, y, i - 1, j, d + 1);
    if (j > 0 && Mapa[i][j] == Mapa[i][j - 1])
        Busqueda(x, y, i, j - 1, d + 1);
    if (j < M - 1 && Mapa[i][j] == Mapa[i][j + 1])
        Busqueda(x, y, i, j + 1, d + 1);
    if (i < N - 1 && Mapa[i][j] == Mapa[i + 1][j])
        Busqueda(x, y, i + 1, j, d + 1);

    visitado[i][j] = false;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> Mapa[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            Busqueda(i, j, i, j, 0);

    cout << "No";
}
