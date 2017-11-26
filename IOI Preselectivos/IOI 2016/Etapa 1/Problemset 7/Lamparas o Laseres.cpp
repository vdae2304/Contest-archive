#include <bits/stdc++.h>
using namespace std;

int N, visitado[5][5];
int max_lamp, cont;
char Mapa[5][5];

bool ChecaH(int i, int j) {
    for (int a = j; a >= 0 && Mapa[i][a] != '*'; a--)
        if (Mapa[i][a] != '.')
            return false;
    for (int a = j; a < N && Mapa[i][a] != '*'; a++)
        if (Mapa[i][a] != '.')
            return false;
    return true;
}

void MarcaH(int i, int j, int c) {
    for (int a = j; a >= 0 && Mapa[i][a] != '*'; a--)
        visitado[i][a] += c;
    for (int a = j; a < N && Mapa[i][a] != '*'; a++)
        visitado[i][a] += c;
}

bool ChecaV(int i, int j) {
    for (int a = i; a >= 0 && Mapa[a][j] != '*'; a--)
        if (Mapa[a][j] != '.')
            return false;
    for (int a = i; a < N && Mapa[a][j] != '*'; a++)
        if (Mapa[a][j] != '.')
            return false;
    return true;
}

void MarcaV(int i, int j, int c) {
    for (int a = i; a >= 0 && Mapa[a][j] != '*'; a--)
        visitado[a][j] += c;
    for (int a = i; a < N && Mapa[a][j] != '*'; a++)
        visitado[a][j] += c;
}

void Busqueda(int i, int j, int k) {
    if (i >= N) {
        if (k > max_lamp)
            max_lamp = k, cont = 1;
        else if (k == max_lamp)
            cont++;
        return;
    }

    int si = i, sj = j + 1;
    if (j == N - 1)
        si = i + 1, sj = 0;

    Busqueda(si, sj, k);
    if (!visitado[i][j] && Mapa[i][j] != '*') {
        if (ChecaH(i, j)) {
            Mapa[i][j] = 'H';
            MarcaH(i, j, 1);
            Busqueda(si, sj, k + 1);
            MarcaH(i, j, -1);
            Mapa[i][j] = '.';
        }

        if (ChecaV(i, j)) {
            Mapa[i][j] = 'V';
            MarcaV(i, j, 1);
            Busqueda(si, sj, k + 1);
            MarcaV(i, j, -1);
            Mapa[i][j] = '.';
        }
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> Mapa[i][j];

    Busqueda(0, 0, 0);
    cout << max_lamp << " " << cont;
}
