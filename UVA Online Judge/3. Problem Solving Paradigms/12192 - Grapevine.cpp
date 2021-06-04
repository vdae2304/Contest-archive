#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    int N, M;
    int Q, L, U;
    int H[500][500];

    while (cin >> N >> M, !(N == 0 && M == 0)) {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                cin >> H[i][j];

        cin >> Q;
        while (Q--) {
            int ans = 0;
            cin >> L >> U;
            
            //Sea (i, j) la esquina superior izquierda del cuadrado.
            //Probamos todos los posibles valores de i.
            for (int i = 0; i < N; ++i) {
                //El valor de j lo encontramos con una busqueda binaria sobre el renglon.
                int j = lower_bound(H[i], H[i] + M, L) - H[i];

                //El tamaño del cuadrado lo encontramos con una busqueda binaria sobre
                //la diagonal.
                int l = 0, r = min(N - i, M - j);
                while (l < r) {
                    int m = (l + r + 1) / 2;
                    if (H[i + m - 1][j + m - 1] <= U)
                        l = m;
                    else
                        r = m - 1;
                }

                //Guardamos el mayor tamaño obtenido hasta ahora.
                ans = max(ans, l);
            }

            //Imprime la respuesta.
            cout << ans << '\n';
        }
        
        cout << "-\n";
    }

    return 0;
}