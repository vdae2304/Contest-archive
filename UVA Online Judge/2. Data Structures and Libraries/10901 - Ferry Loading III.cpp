#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    int T;
    cin >> T;

    while (T--) {
        int n, t, m;
        cin >> n >> t >> m;

        //Crea dos colas representando los carros en espera en cada lado.
        queue< pair<int, int> > cars[2];
        for (int i = 0; i < m; ++i) {
            int arrival;
            string side;
            cin >> arrival >> side;
            cars[side == "right"].push(make_pair(arrival, i));
        }

        int tcurr = 0; //Minuto actual.
        bool side = 0; //Lado donde esta el ferry (0 - izquierda, 1 - derecha).
        int ans[m];    //Tiempo de llegada de cada carro.

        //Simula el viaje del ferry.
        while (!cars[0].empty() || !cars[1].empty()) {
            //Si habia carros esperando, los recoje.
            if (!cars[side].empty() && cars[side].front().first <= tcurr) {
                int i = 0;
                while (i < n && !cars[side].empty() && cars[side].front().first <= tcurr) {
                    ans[cars[side].front().second] = tcurr + t;
                    cars[side].pop();
                    i++;
                }
                tcurr += t;
                side = !side;
            }
            //Si habia carros esperando del otro lado, se mueve a ese lado.
            else if (!cars[!side].empty() && cars[!side].front().first <= tcurr) {
                tcurr += t;
                side = !side;
            }
            //Espera a que haya carros en algun lado.
            else {
                int nxt_t = 1 << 30;
                if (!cars[side].empty() && cars[side].front().first < nxt_t)
                    nxt_t = cars[side].front().first;
                if (!cars[!side].empty() && cars[!side].front().first < nxt_t)
                    nxt_t = cars[!side].front().first;
                tcurr = nxt_t;
            }
        }

        //Imprime la respuesta.
        for (int i = 0; i < m; ++i)
            cout << ans[i] << '\n';
        if (T)
            cout << '\n';
    }

    return 0;
}
