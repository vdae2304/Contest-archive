#include <bits/stdc++.h>
using namespace std;

int N, max_pob;
int Moscas[60002], inicio = INFINITY, fin;

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int x, y;
    cin >> N;

    while (N--) {
        cin >> x >> y;
        for (int i = x; i < y; i++)
            Moscas[i]++;
        inicio = min(inicio, x);
        fin = max(fin, y);
    }

    x = INFINITY, y = 0;
    for (int i = inicio; i < fin; i++)
        max_pob = max(max_pob, Moscas[i]);

    cout << max_pob << "\n";
    for (int i = inicio; i <= fin; i++) {
        if (Moscas[i] == max_pob) {
            x = min(x, i);
            y = max(y, i);
        }
        else {
            if (x <= y)
                cout << x << " " << y + 1 << "\n";
            x = INFINITY;
            y = 0;
        }
    }
}
