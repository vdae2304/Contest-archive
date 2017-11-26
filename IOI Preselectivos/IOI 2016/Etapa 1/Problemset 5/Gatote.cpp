#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

int P, J, L;
bool win[2];
vector<pair<int, int> > v[2];

//Checa si existe una linea horizontal/vertical/diagonal
bool busca(int i, int a, int b) {
    int line = 0, k;
    for (int j = 0; line < L && j < v[i].size(); j++) {
        //Checa si existe un punto adyacente
        bool l = true;
        for (k = 1; l && k <= L; k++)
            l = binary_search(v[i].begin(), v[i].end(), make_pair(v[i][j].x + k * a, v[i][j].y + k * b));
        line = max(line, k - 1);
    }
    return line >= L;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> P;

    while (P--) {
        cin >> J >> L;

        for (int i = 0, a, b; i < J; i++) {
            cin >> a >> b;
            v[i % 2].push_back(make_pair(a, b));
        }

        //Checa si gano el jugador i
        for (int i = 0; i < 2; i++) {
            sort(v[i].begin(), v[i].end());
            win[i] = busca(i, 1, 0) || busca(i, 0, 1) || busca(i, 1, 1) || busca(i, 1, -1);
        }

        //Reinicia el vector
        v[0].clear(); v[1].clear();

        //Imprime los resultados
        if (win[0] && win[1])
            cout << "-1\n";
        else if (win[0])
            cout << "1\n";
        else if (win[1])
            cout << "2\n";
        else
            cout << "0\n";
    }
}
