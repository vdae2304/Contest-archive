#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    int N;
    int dist[2][256][256];
    char me, prof;

    while (cin >> N, N != 0) {
        //Inicializa las distancias a "infinito".
        for (int t = 0; t < 2; ++t)
            for (char i = 'A'; i <= 'Z'; ++i)
                for (char j = 'A'; j <= 'Z'; ++j) 
                    dist[t][i][j] = 1e9;

        //Lee la entrada.
        while (N--) {
            char age, dir, from, to;
            int energy;
            cin >> age >> dir >> from >> to >> energy;

            dist[age == 'M'][from][to] = energy;
            if (dir == 'B')
                dist[age == 'M'][to][from] = energy;
        }

        //Calcula todos los pares de distancias mas cortas.
        for (int t = 0; t < 2; ++t) {
            for (char i = 'A'; i <= 'Z'; ++i)
                dist[t][i][i] = 0;
            for (char k = 'A'; k <= 'Z'; ++k)
                for (char i = 'A'; i <= 'Z'; ++i)
                    for (char j = 'A'; j <= 'Z'; ++j)
                        dist[t][i][j] = min(dist[t][i][j], dist[t][i][k] + dist[t][k][j]);
        }

        //Prueba todos los posibles puntos de reunion.
        int ans = 1e9;
        string places = "";
        cin >> me >> prof;

        for (char i = 'A'; i <= 'Z'; ++i) {
            int tmp = dist[0][me][i] + dist[1][prof][i];
            if (tmp < ans) {
                ans = tmp;
                places = i;
            }
            else if (tmp == ans) {
                places.push_back(' ');
                places.push_back(i);
            }
        }

        //Imprime la respuesta.
        if (ans < 1e9)
            cout << ans << ' ' << places << '\n';
        else
            cout << "You will never meet.\n";
    }

    return 0;
}