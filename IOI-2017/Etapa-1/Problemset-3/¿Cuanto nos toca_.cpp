#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N, A;
    cin >> N >> A;

    int C[N], a = 1, b = 100000;
    for (int i = 0; i < N; i++)
        cin >> C[i];

    //Realizamos una busqueda binaria
    while (a <= b) {
        //Verificamos si hay chocolate suficiente para trozos de "m" unidades
        int m = (a + b) / 2, S = 0;
        for (int i = 0; i < N; i++)
            S += C[i] / m;

        if (S >= A)
            a = m + 1;
        else
            b = m - 1;
    }

    cout << b;
}
