#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int P, N, M, A;
    cin >> P >> N >> M;

    int piedra[N][M], t = 0, x;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> piedra[i][j];

    cin >> A;
    bitset<3001> abierta;
    while (A--) {
        cin >> x;
        for (int i = 0; i < M; i++) {
            if (abierta[piedra[x - 1][i]]) {
                t--;
                abierta[piedra[x - 1][i]] = false;
            }
            else {
                t++;
                abierta[piedra[x - 1][i]] = true;
            }
        }
    }

    cout << t << "\n";
    for (int i = 1; i <= P; i++)
        if (abierta[i])
            cout << i << " ";
}
