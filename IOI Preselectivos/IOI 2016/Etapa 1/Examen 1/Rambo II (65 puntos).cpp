#include <iostream>
using namespace std;

bool casillas[1000000];

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int n, d, k, m;
    cin >> n >> d >> k >> m;

    int v[k];
    for (int i = 0; i < k; ++i) {
        cin >> v[i];
        casillas[v[i]] = true;
    }

    int mayor = 0, ci;
    for (int i = 0; i < k; ++i) {
        int cont = 0, pos = v[i];
        for (int j = 0; j < m; ++j) {
            if (casillas[pos])
                ++cont;
            pos = (pos + d) % n;
        }
        if (cont > mayor) {
            mayor = cont;
            ci = v[i];
        }
    }

    cout << mayor << " " << ci;
}
