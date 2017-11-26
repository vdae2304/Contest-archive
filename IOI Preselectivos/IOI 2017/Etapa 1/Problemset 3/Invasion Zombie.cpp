#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, X, Y, C;

ll c(ll n) {
    return n * n;
}

ll g(ll n) {
    return n * (n + 1) / 2;
}

bool calcula(int d) {
    //Las distancias desde los extremos a los lados de la cuadricula
    int up_d = max(0, d + 1 - Y), left_d = max(0, d + 1 - X), down_d = max(0, d - (N - Y)), right_d = max(0, d - (N - X));

    //Calcula la longitud de los triangulos de las esquinas
    int up_left = max(0, up_d - X), down_left = max(0, down_d - X), up_right = max(0, up_d - (N - (X - 1))), down_right = max(0, down_d - (N - (X - 1)));

    //Calculamos el area
    ll area = c(d) + c(d + 1) - (c(up_d) + c(left_d) + c(down_d) + c(right_d)) + g(up_left) + g(down_left) + g(up_right) + g(down_right);

    return area >= C;
}

main() {
    cin >> N >> X >> Y >> C;

    //Realizamos una busqueda binaria
    int a = 0, b = 1 << 30;
    while (a < b) {
        int m = (a + b) / 2;
        if (calcula(m))
            b = m;
        else
            a = m + 1;
    }

    cout << a;
}
