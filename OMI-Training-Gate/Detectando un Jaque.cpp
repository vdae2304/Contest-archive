#include <bits/stdc++.h>
using namespace std;

char tab[8][8];

bool checar_pos(int i, int j, char c) {
    return (0 <= i && i < 8 && 0 <= j && j < 8 && tab[i][j] == c);
}

bool c_libre(int i, int j, int x, int y) {
    int a = 0, b = 0;
    if (i < x)
        a = 1;
    else if (i > x)
        a = -1;
    if (j < y)
        b = 1;
    else if (j > y)
        b = -1;

    i += a, j += b;
    while (!(i == x && j == y)) {
        if (tab[i][j] != '.')
            return false;
        i += a, j += b;
    }
    return true;
}

bool peon(int i, int j, char c) {
    int x = (c == 'p') ? 1 : -1;
    return (checar_pos(i + x, j - 1, c)|| checar_pos(i + x, j + 1, c));
}

bool torre(int i, int j, char c) {
    for (int k = 0; k < 8; k++)
        if ((checar_pos(i, k, c) && c_libre(i, j, i, k)) || (checar_pos(k, j, c) && c_libre(i, j, k, j)))
            return true;
    return false;
}

int movc[2][8] = {{-1, -2, -2, -1, 1, 2, 2, 1}, {-2, -1, 1, 2, -2, -1, 1, 2}};
bool caballo(int i, int j, char c) {
    for (int k = 0; k < 8; k++)
        if (checar_pos(i + movc[0][k], j + movc[1][k], c))
            return true;
    return false;
}

bool alfil(int i, int j, char c) {
    for (int k = -7; k < 8; k++)
        for (int l = -1; l <= 1; l++)
            if (l && checar_pos(i + k, j + l*k, c) && c_libre(i, j, i + k, j + l*k))
                return true;
    return false;
}

bool rey(int i, int j, char c) {
    for (int k = -1; k <= 1; k++)
        for (int l = -1; l <= 1; l++)
            if (checar_pos(i + k, j + l, c))
                return true;
    return false;
}

bool reina(int i, int j, char c) {
    return (torre(i, j, c) || alfil(i, j, c));
}

bool jaque(int i, int j, bool caso) {
    return (i != -1 && j != -1 &&
        (peon(i, j, caso ? 'P' : 'p')
        || torre(i, j, caso ? 'T' : 't')
        || caballo(i, j, caso ? 'C' : 'c')
        || alfil(i, j, caso ? 'A' : 'a')
        || rey(i, j, caso ? 'R' : 'r')
        || reina(i, j, caso ? 'E' : 'e')));
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int rbi = -1, rbj = -1, rni = -1, rnj = -1;

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++) {
            cin >> tab[i][j];
            if (tab[i][j] == 'R')
                rbi = i, rbj = j;
            else if (tab[i][j] == 'r')
                rni = i, rnj = j;
        }

    cout << jaque(rbi, rbj, 0) << "\n" << jaque(rni, rnj, 1);
}
