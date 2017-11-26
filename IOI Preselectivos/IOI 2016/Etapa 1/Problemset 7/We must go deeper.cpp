#include <bits/stdc++.h>
using namespace std;

int tab[9][9];

void resolver(int i, int j) {
    //Buscamos el siguiente sin llenar
    while (i < 9 && tab[i][j]) {
        i += ++j / 9;
        j %= 9;
    }

    //Ya no hay mas cuadros vacios
    if (i >= 9) {
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++)
                cout << tab[i][j] << " ";
            cout << "\n";
        }
        exit(0);
    }

    //Checamos que numeros se pueden usar
    bool uses[10] = {};
    for (int r = 0; r < 9; r++) {
        uses[tab[i][r]] = true;
        uses[tab[r][j]] = true;
    }

    int a = 3 * (i / 3), b = 3 * (j / 3);
    for (int r = a; r < a + 3; r++)
        for (int c = b; c < b + 3; c++)
            uses[tab[r][c]] = true;

    for (int r = 1; r < 10; r++)
        if (!uses[r]) {
            tab[i][j] = r; //Si se puede usar la probamos
            resolver(i, j);
            tab[i][j] = 0; //Regresamos a su estado anterior
        }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> tab[i][j];
    resolver(0, 0);
}
