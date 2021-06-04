#include <iostream>
#include <utility>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    int T, N, v[2000];
    pair<int, int> DP[2000];

    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; ++i)
            cin >> v[i];

        //Resuelve por programacion dinamica, donde cada estado DP[i] representa
        //la longitud de la mayor subsecuencia creciente (resp. decreciente)
        //que inicia en i.
        for (int i = N - 1; i >= 0; --i) {
            DP[i] = make_pair(1, 1);
            for (int j = i + 1; j < N; ++j) {
                if (v[i] < v[j])
                    DP[i].first = max(DP[i].first, DP[j].first + 1);
                else
                    DP[i].second = max(DP[i].second, DP[j].second + 1);
            }
        }

        //Imprime la mayor suma entre la subsecuencia creciente y decreciente mas larga.
        int ans = 0;
        for (int i = 0; i < N; ++i)
            ans = max(ans, DP[i].first + DP[i].second - 1);
        cout << ans << '\n';
    }

    return 0;
}