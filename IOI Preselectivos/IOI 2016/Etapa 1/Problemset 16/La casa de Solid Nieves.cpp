#include <bits/stdc++.h>
using namespace std;
#define inf 1 << 25

int P, F, C;
int menor = inf, mejor;
int Dem[501], Dist[501][501];

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> P >> F >> C;

    for (int i = 0; i < F; i++)
        cin >> Dem[i];

    for (int i = 1; i <= P; i++)
        for (int j = 1; j <= P; j++)
            if (i != j)
                Dist[i][j] = inf;

    for (int i = 0; i < C; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        Dist[a][b] = Dist[b][a] = d;
    }

    for (int k = 1; k <= P; k++)
        for (int i = 1; i <= P; i++)
            for (int j = 1; j <= P; j++)
                Dist[i][j] = min(Dist[i][j], Dist[i][k] + Dist[k][j]);

    for (int i = 1; i <= P; i++) {
        int S = 0;
        for (int j = 0; j < F; j++)
            S += Dist[i][Dem[j]];

        if (S < menor) {
            menor = S;
            mejor = i;
        }
    }

    cout << mejor;
}
