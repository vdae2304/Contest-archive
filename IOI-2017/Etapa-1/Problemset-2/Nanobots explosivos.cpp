#include <bits/stdc++.h>
using namespace std;

bool ordenarPorMayor(pair<int, int> A, pair<int, int> B) {
    if (A.second == B.second)
        return A.first < B.first;
    return A.second < B.second;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N, K;

    cin >> N;
    pair<int, int> nb[N];
    for (int i = 0; i < N; i++)
        cin >> nb[i].first >> nb[i].second; //Minimo, Maximo
    sort(nb, nb + N, ordenarPorMayor);

    cin >> K;
    pair<int, int> cp[K];
    for (int i = 0; i < K; i++)
        cin >> cp[i].first >> cp[i].second; //Oxigeno, Capacidad
    sort(cp, cp + K);

    //Calculamos los nanobots que entran en cada capsula
    vector<int> G[K];
    for (int i = 0; i < K; i++)
        for (int j = 0; j < N; j++)
            if (nb[j].first <= cp[i].first && cp[i].first <= nb[j].second)
                G[i].push_back(j);

    //Calculamos el maximo
    int S = 0;
    bitset<2500> usado(0);
    for (int i = 0; i < K; i++) {
        int W = G[i].size();
        //Eliminamos los nanobots que ya hayan sido usados
        for (int j = 0 ; j < G[i].size(); j++)
            if (usado[G[i][j]]) {
                G[i][j] = -1;
                W--;
            }
        //Transferimos la nanobots que sobren a la siguiente capsula
        if (i < K - 1) {
            int j = G[i].size() - 1, k = G[i + 1].size() - 1;
            while (W > cp[i].second && j >= 0 && k >= 0) {
                if (G[i][j] == -1)
                    j--;
                else if (G[i + 1][k] == -1)
                    k--;
                else if (G[i][j] == G[i + 1][k]) {
                    G[i][j] = -1;
                    W--, j--, k--;
                }
                else if (G[i][j] > G[i + 1][k])
                    j--;
                else
                    k--;
            }
        }
        W = min(W, cp[i].second);
        //Guardamos los que se puedan
        for (int j = 0; j < G[i].size() && W > 0; j++)
            if (G[i][j] != -1) {
                usado[G[i][j]] = true;
                S++, W--;
            }
    }

    cout << S;
}
