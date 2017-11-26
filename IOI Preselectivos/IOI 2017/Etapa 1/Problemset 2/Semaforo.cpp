#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int n, v, r, D;
    double v_min = 0;
    cin >> n >> v >> r;
    while (n--) {
        cin >> D;
        int t = D / v; //Tiempo en ir de un semaforo a otro
        t = (t / r) * r + r; //Redondea hacia arriba el tiempo a un multiplo de "r"
        double vi = (double) D / t; //Calcula la velocidad minima para ese mismo tiempo
        v_min = max(v_min, vi);
    }
    cout << fixed << setprecision(9) << v_min;
}
