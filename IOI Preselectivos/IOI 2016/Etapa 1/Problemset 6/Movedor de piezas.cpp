#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> punto;

struct pos {
    vector<punto> pza;
    int t;
};

queue<pos> cola;
set<vector<punto> > estados;
bool Mapa[5][5], visitado[5][5];
int mov[2][4] = {{-1, 0, 0, 1}, {0, -1, 1, 0}};

//Retorna el numero de piezas que estan juntas
int floodfill(int i, int j) {
    if (i < 0 || j < 0 || i > 4 || j > 4 || visitado[i][j] || !Mapa[i][j])
        return 0;
    visitado[i][j] = true;
    return 1 + floodfill(i - 1, j) + floodfill(i, j - 1) + floodfill(i, j + 1) + floodfill(i + 1, j);
}

//Checa si todas las piezas estan conectadas
bool conectado(vector<punto> P) {
    memset(Mapa, false, sizeof(Mapa));
    memset(visitado, false, sizeof(visitado));
    for (int i = 0; i < P.size(); i++)
        Mapa[P[i].first][P[i].second] = true;
    return floodfill(P[0].first, P[0].second) == P.size();
}

//Checa si hay piezas fuera del mapa, si hay 2 en un mismo lugar o si ya hemos usado esa configuracion
bool posible(vector<punto> P) {
    for (int i = 0; i < P.size(); i++) {
        if (P[i].first < 0 || P[i].first > 4 || P[i].second < 0 || P[i].second > 4)
            return false;
        for (int j = i + 1; j < P.size(); j++)
            if (P[i] == P[j])
                return false;
    }
    return estados.find(P) == estados.end();
}

void Busqueda(pos q) {
    cola.pop();
    if (conectado(q.pza)) {
        cout << q.t;
        exit(0);
    }

    for (int i = 0; i < q.pza.size(); i++)
        for (int j = 0; j < 4; j++) {
            pos p = q; p.t++;

            p.pza[i].first += mov[0][j];
            p.pza[i].second += mov[1][j];
            sort(p.pza.begin(), p.pza.end());

            if (posible(p.pza)) {
                cola.push(p);
                estados.insert(p.pza);
            }
        }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    pos q; q.t = 0;
    char c;

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) {
            cin >> c;
            if (c == '*')
                q.pza.push_back(make_pair(i, j));
        }

    cola.push(q);
    while (!cola.empty())
        Busqueda(cola.front());
}
