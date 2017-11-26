#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N;
    cin >> N;

    int mayor = 0, cuenta = 0, x;
    for (int i = 0; i < N; i++) {
        cin >> x;
        if (cuenta > 0)
            cuenta += x;
        else
            cuenta = x;
        mayor = max(mayor, cuenta);
    }

    cout << mayor;
}
