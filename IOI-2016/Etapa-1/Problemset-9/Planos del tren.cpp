#include <bits/stdc++.h>
using namespace std;

int F, R, C, S;
char Mapa[10][10];
bool visitado[10][10];

void Busqueda(int i, int j, int k) {
    if (Mapa[i][j] == '.')
        return;
    if (!visitado[i][j])
        S++;
    visitado[i][j] = true;

    if (Mapa[i][j] != '-' && k > 0) {
        if (i > 0 && Mapa[i - 1][j] != '-')
            Busqueda(i - 1, j, k - 1);
        if (i < R - 1 && Mapa[i + 1][j] != '-')
            Busqueda(i + 1, j, k - 1);
    }
    if (Mapa[i][j] != '|' && k > 0) {
        if (j > 0 && Mapa[i][j - 1] != '|')
            Busqueda(i, j - 1, k - 1);
        if (j < C - 1 && Mapa[i][j + 1] != '|')
            Busqueda(i, j + 1, k - 1);
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int x, y;
    cin >> F >> R >> C;

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) {
            cin >> Mapa[i][j];
            if (Mapa[i][j] == 'S')
                x = i, y = j;
        }

    Busqueda(x, y, F);
    cout << S;
}
