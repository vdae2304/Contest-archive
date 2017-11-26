#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int C, V;
    cin >> C >> V;

    queue<int> votos[V];
    for (int i = 0; i < V; i++)
        for (int j = 0, x; j < C; j++) {
            cin >> x;
            votos[i].push(x - 1);
        }

    int restantes = C, ganador = 0;
    bitset<50> eliminado;
    while (!ganador && restantes) {
        int total[C], menor = INFINITY;
        memset(total, 0, sizeof(total));

        for (int i = 0; i < V; i++) {
            while (eliminado[votos[i].front()])
                votos[i].pop();
            total[votos[i].front()]++;
        }

        for (int i = 0; i < C; i++) {
            if (total[i] > V / 2)
                ganador = i + 1;
            if (!eliminado[i] && total[i] < menor)
                menor = total[i];
        }

        for (int i = 0; i < C; i++)
            if (menor == total[i]) {
                eliminado[i] = true;
                restantes--;
            }
    }

    cout << ganador;
}
