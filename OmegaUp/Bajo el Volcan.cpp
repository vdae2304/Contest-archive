#include <stdio.h>

int N, M, X, Y;
char volcan[100][100];

void Busqueda(int i, int j, char altura) {
    if (i < 0 || j < 0 || i >= N || j >= M || volcan[i][j] >= altura)
        return;

    for (int x = -1; x <= 1; x++)
        for (int y = -1; y <= 1; y++)
            if (x || y)
                Busqueda(i + x, j + y, volcan[i][j]);

    volcan[i][j] = 'X';
}

main() {
    scanf("%d %d %d %d", &N, &M, &X, &Y);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf(" %c", &volcan[i][j]);

    Busqueda(X - 1, Y - 1, volcan[X - 1][Y - 1] + 1);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            printf("%c ", volcan[i][j]);
        printf("\n");
    }
}
