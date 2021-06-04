#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    int L, U, R;
    int RV[10];
    int ncase = 1;

    while (cin >> L >> U >> R, !(L == 0 && U == 0 && R == 0)) {
        for (int i = 0; i < R; ++i)
            cin >> RV[i];

        //Para cada codigo guardamos el numero de pasos necesarios para desbloquear.
        int nsteps[10000];
        memset(nsteps, -1, sizeof nsteps);
        
        //Realizamos una BFS para calcular nsteps.
        queue<int> Q;
        Q.push(L);
        nsteps[L] = 0;

        while (!Q.empty()) {
            int curr = Q.front();
            Q.pop();
            for (int i = 0; i < R; ++i) {
                int nxt = (curr + RV[i]) % 10000;
                if (nsteps[nxt] == -1) {
                    nsteps[nxt] = nsteps[curr] + 1;
                    Q.push(nxt);
                }
            }
        }

        //Imprime la respuesta.
        if (nsteps[U] != -1)
            cout << "Case " << ncase++ << ": " << nsteps[U] << '\n';
        else
            cout << "Case " << ncase++ << ": Permanently Locked\n";
    }

    return 0;
}