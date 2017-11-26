#include <bits/stdc++.h>
using namespace std;

int N, E, T;
vector<int> conexion[101];
bool visitado[101];

int salida() {
    int total = 0, t = 1;

    queue<int> cola;
    cola.push(N);
    visitado[N] = true;

    while (t++ < T && !cola.empty()) {
        int l = cola.size();
        for (int i = 0; i < l; i++) {
            for (int nxt : conexion[cola.front()])
                if (!visitado[nxt]) {
                    visitado[nxt] = true;
                    cola.push(nxt);
                    total++;
                }
            cola.pop();
        }
    }

    return total;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> E >> T;

    while (E--) {
        int a, b;
        cin >> a >> b;
        conexion[a].push_back(b);
        conexion[b].push_back(a);
    }

    cout << salida();
}
