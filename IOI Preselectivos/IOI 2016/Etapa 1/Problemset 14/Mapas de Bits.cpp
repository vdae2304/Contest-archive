#include <bits/stdc++.h>
using namespace std;

int N, M;
char Mapa[2000][2000], c;

bool compara(char c, int a, int b, int x, int y) {
    for (int i = a; i < x; i++)
        for (int j = b; j < y; j++)
            if (Mapa[i][j] != c)
                return false;
    return true;
}

void convertirD(int a, int b, int x, int y) {
    if (a < x && b < y) {
        if (compara('1', a, b, x, y))
            cout << "1";
        else if (compara('0', a, b, x, y))
            cout << "0";
        else {
            cout << "D";
            int i = (a + x + 1) / 2, j = (b + y + 1) / 2;
            convertirD(a, b, i, j);
            convertirD(a, j, i, y);
            convertirD(i, b, x, j);
            convertirD(i, j, x, y);
        }
    }
}

void convertirB(int a, int b, int x, int y) {
    if (a < x && b < y) {
        cin >> c;
        if (c == '1' || c == '0') {
            for (int i = a; i < x; i++)
                for (int j = b; j < y; j++)
                    Mapa[i][j] = c;
        }
        else {
            int i = (a + x + 1) / 2, j = (b + y + 1) / 2;
            convertirB(a, b, i, j);
            convertirB(a, j, i, y);
            convertirB(i, b, x, j);
            convertirB(i, j, x, y);
        }
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> c >> N >> M;

    if (c == 'B') {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> Mapa[i][j];

        cout << "D " << N << " " << M << "\n";
        convertirD(0, 0, N, M);
    }
    else {
        convertirB(0, 0, N, M);
        cout << "B " << N << " " << M << "\n";

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cout << Mapa[i][j];
    }
}
