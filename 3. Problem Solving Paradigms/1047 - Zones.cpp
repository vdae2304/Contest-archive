#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    int n, m, k;
    int tower[20], cmn_tower[10], cmn_area[10];

    //Precalcula el numero de bits encendidos para cada numero.
    int nbits[1 << 20];
    for (int n = 0; n < (1 << 20); ++n) {
        nbits[n] = 0;
        for (int i = 0; i < 20; ++i)
            if (n & (1 << i))
                nbits[n]++;
    }

    int ncase = 1;
    while (cin >> n >> k, !(n == 0 && k == 0)) {
        //Lee el numero de clientes por cada torre.
        for (int i = 0; i < n; ++i)
            cin >> tower[i];
        
        //Lee el numero de clientes por cada interseccion.
        cin >> m;
        for (int i = 0; i < m; ++i) {
            int sz, t;
            cin >> sz;
            cmn_tower[i] = 0;
            while (sz--) {
                cin >> t;
                cmn_tower[i] += 1 << (t - 1);
            }
            cin >> cmn_area[i];
        }

        //Prueba todos los subconjuntos de tamaño k.
        int best = 0, best_subset;
        for (int subset = 0; subset < (1 << n); ++subset) 
            if (nbits[subset] == k) {
                //Calcula el numero de clientes para el subconjunto dado.
                int total = 0;
                for (int i = 0; i < n; ++i)
                    if (subset & (1 << i))
                        total += tower[i];
                //Cada interseccion la estamos contando multiples veces, una por cada
                //torre que hay en la interseccion.
                for (int i = 0; i < m; ++i) 
                    total -= max(0, nbits[subset & cmn_tower[i]] - 1) * cmn_area[i];
                //Verifica si subset utiliza torres menores que best_subset.
                bool cmp;
                for (int i = 0; i < n; ++i)
                    if (bool(subset & (1 << i)) != bool(best_subset & (1 << i))) {
                        cmp = subset & (1 << i);
                        break;
                    }
                //Si obtenemos un numero de clientes estrictamente mayor, o igual pero
                //subset utiliza torres menores, actualizamos.
                if (total > best || (total == best && cmp)) {
                    best = total;
                    best_subset = subset;
                }
            }

        //Imprime la respuesta.
        cout << "Case Number  " << ncase++ << '\n';
        cout << "Number of Customers: " << best << '\n';
        cout << "Locations recommended:";
        for (int i = 0; i < n; ++i)
            if (best_subset & (1 << i))
                cout << ' ' << i + 1;
        cout << "\n\n";
    }

    return 0;
}