#include <bits/stdc++.h>
using namespace std;
int v[1000000];
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N;
    cin >> N;

    for (int i = 0, x; i < N; i++) {
        cin >> x;
        v[x]++;
    }

    //Probamos cada i como maximo comun divisor
    for (int i = 1000000; i > 0; i--) {
        //Buscamos los multiplos mas grandes de i
        long long x = 0, y = 0;
        for (int j = i; j <= 1000000; j += i) {
            if (v[j] > 1)
                x = y = j;
            else if (v[j])
                x = y, y = j;
        }
        //Si los encontramos imprimimos su minimo comun multiplo
        if (x && y) {
            cout << x * y / i;
            return 0;
        }
    }
}
