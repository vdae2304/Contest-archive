#include <iostream>
#include <cstring>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    int T;
    cin >> T;

    //Guarda las jerarquias.
    char defeats[256];
    defeats['R'] = 'S';
    defeats['S'] = 'P';
    defeats['P'] = 'R';

    while (T--) {
        int R, C, N;
        cin >> R >> C >> N;

        char grid[R][C], tmp[R][C];
        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
                cin >> grid[i][j];

        //Simula dia por dia.
        while (N--) {
            for (int i = 0; i < R; ++i)
                for (int j = 0; j < C; ++j)
                    //Verifica si es derrotado por algun vecino y actualiza.
                    if ((i > 0 && defeats[grid[i - 1][j]] == grid[i][j]) ||
                        (j > 0 && defeats[grid[i][j - 1]] == grid[i][j]) ||
                        (j < C - 1 && defeats[grid[i][j + 1]] == grid[i][j]) ||
                        (i < R - 1 && defeats[grid[i + 1][j]] == grid[i][j]))
                        tmp[i][j] = defeats[defeats[grid[i][j]]];
                    else
                        tmp[i][j] = grid[i][j];
            //Copia todo a la matriz original.
            memcpy(grid, tmp, sizeof(grid));
        }

        //Imprime la respuesta.
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j)
                cout << grid[i][j];
            cout << '\n';
        }
        if (T)
            cout << '\n';
    }
    return 0;
}
