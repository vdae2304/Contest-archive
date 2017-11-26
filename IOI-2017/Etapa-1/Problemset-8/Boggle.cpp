#include <bits/stdc++.h>
using namespace std;

int N, total;
int puntos[17] = {0, 0, 0, 1, 1, 2, 3, 5, 11, 11, 11, 11, 11, 11, 11, 11, 11};

char tab[4][4];
bool visitado[4][4], solucion;

void Busqueda(int i, int j, string &s, string p) {
    if (i < 0 || i > 3 || j < 0 || j > 3 || visitado[i][j] || tab[i][j] != s[p.size()] || solucion)
        return;

    p.push_back(tab[i][j]);
    if (s == p) {
        solucion = true;
        return;
    }

    visitado[i][j] = true;

    for (int x = -1; x <= 1; x++)
        for (int y = -1; y <= 1; y++)
            Busqueda(i + x, j + y, s, p);

    visitado[i][j] = false;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cin >> tab[i][j];

    cin >> N;
    while (N--) {
        string s;
        cin >> s;
        solucion = false;

        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                Busqueda(i, j, s, "");

        if (solucion)
            total += puntos[s.size()];
    }

    cout << total;
}
