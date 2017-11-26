#include <bits/stdc++.h>
using namespace std;

int N;
short Piramide[100][100], Sumas[100][100];

short Calcular(int i, int j) {
    if (!Sumas[i][j]) {
        Sumas[i][j] = Piramide[i][j];
        if (i < N - 1)
            Sumas[i][j] += max(Calcular(i + 1, j), Calcular(i + 1, j + 1));
    }
    return Sumas[i][j];
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j <= i; ++j)
            cin >> Piramide[i][j];
    cout << Calcular(0, 0);
}
