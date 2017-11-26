#include <stdio.h>

char s[101];
int mov[2][8] = {{-1, -2, -2, -1, 1, 2, 2, 1}, {-2, -1, 1, 2, -2, -1, 1, 2}};
bool visitado[100][4][10][4][10];
char tecla[2][4][11] = {{"qwertyuiop", "asdfghjkl;", "zxcvbnm,./", "**      **"},
                        {"QWERTYUIOP", "ASDFGHJKL:", "ZXCVBNM<>?", "**      **"}};

bool posible(int l, int i, int j, int x, int y) {
    if (s[l] == '\0')
        return true;

    if (visitado[l][i][j][x][y])
        return false;
    visitado[l][i][j][x][y] = true;

    for (int k = 0; k < 8; k++) {
        int ni = i + mov[0][k];
        int nj = j + mov[1][k];

        if (0 <= ni && ni < 4 && 0 <= nj && nj < 10 && !(ni == x && nj == y)) {
            if (tecla[0][ni][nj] == '*') {
                if (posible(l, ni, nj, x, y))
                    return true;
            }
            else if (tecla[tecla[0][x][y] == '*'][ni][nj] == s[l]) {
                if (posible(l + 1, ni, nj, x, y))
                    return true;
            }
        }
    }

    return posible(l, x, y, i, j);
}

main() {
    gets(s);
    printf("%d\n", posible(0, 3, 0, 3, 9));
}
