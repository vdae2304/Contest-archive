#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N;
    multiset<int> v[2];
    cin >> N;

    while (N--) {
        int a, b, l = v[0].size() + v[1].size();
        cin >> a;
        if (a == 1) {
            cin >> b;
            if (v[0].empty() || v[1].empty() || b < *v[1].begin())
                v[0].insert(b);
            else
                v[1].insert(b);
            if (++l >= 3) {
                while (v[0].size() < 2 * l / 3) {
                    v[0].insert(v[0].end(), *v[1].begin());
                    v[1].erase(v[1].begin());
                }
                while (v[0].size() > 2 * l / 3) {
                    v[1].insert(v[1].begin(), *prev(v[0].end()));
                    v[0].erase(prev(v[0].end()));
                }
            }
        }
        else if (l < 3)
            cout << "No hay suficientes calificaciones\n";
        else
            cout << *v[1].begin() << "\n";
    }
}
