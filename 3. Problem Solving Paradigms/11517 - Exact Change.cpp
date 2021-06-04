#include <iostream>
#include <cstring>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    int T, N, S;
    int DP[20001];
    
    cin >> T;
    while (T--) {
        cin >> S >> N;

        //Resolvemos con programacion dinamica, donde cada estado DP[i] representa
        //el menor numero de monedas/billetes requeridas para sumas i.
        memset(DP, -1, sizeof DP);
        DP[0] = 0;
        
        while (N--) {
            int x;
            cin >> x;

            for (int i = 20000; i >= x; --i)
                //Si podemos sumar i - x y esto reduce el numero de monedas, actualizamos.
                if (DP[i - x] != -1 && (DP[i] == -1 || DP[i - x] + 1 < DP[i]))
                    DP[i] = DP[i - x] + 1;
        }

        //Busca la menor cantidad que podamos sumar y la imprime.
        for (int i = S; i <= 20000; ++i)
            if (DP[i] != -1) {
                cout << i << ' ' << DP[i] << '\n';
                break;
            }
    }

    return 0;
}