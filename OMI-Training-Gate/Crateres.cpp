#include <bits/stdc++.h>
using namespace std;

int N, M, num_crater;
int Mapa[500][500];

int crater(int i, int j) {
    int S = 0;
    queue<pair<int, int> > cola;
    cola.push(make_pair(i, j));

    while (!cola.empty()) {
        pair<int, int> q = cola.front();
        cola.pop();

        if (q.first < 0 || q.first >= N || q.second < 0 || q.second >= M || !Mapa[q.first][q.second])
            continue;

        S += Mapa[q.first][q.second];
        Mapa[q.first][q.second] = 0;

        cola.push(make_pair(q.first - 1, q.second));
        cola.push(make_pair(q.first, q.second - 1));
        cola.push(make_pair(q.first, q.second + 1));
        cola.push(make_pair(q.first + 1, q.second));
    }
    return S;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> Mapa[i][j];

    int num = 0, tam = 0;
    for (int j = 0; j < M; j++)
        for (int i = 0; i < N; i++)
            if (Mapa[i][j]) {
                int t = crater(i, j);
                num_crater++;
                if (t > tam) {
                    num = num_crater;
                    tam = t;
                }
            }

    cout << num << " " << tam;
}
