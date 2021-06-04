#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    int n, ai;
    cin >> n;

    for (int ncase = 1; n != 0; ncase++) {
        //Calcula la suma.
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> ai;
            sum += ai;
        }
        cout << "Case " << ncase << ":\n";

        //Caso 1. La respuesta es un entero.
        if (sum % n == 0) {
            if (sum < 0)
                cout << "- ";
            cout << abs(sum) / n << '\n';
        }
        //Caso 2. La respuesta es una fraccion.
        else {
            //Signo.
            string sign = sum < 0 ? "- " : "";
            sum = abs(sum);
            //Parte entera.
            string a = sum < n ? "" : to_string(sum / n);
            sum %= n;
            //Parte fraccionaria.
            string b = to_string(sum / __gcd(sum, n));
            string c = to_string(n / __gcd(sum, n));

            //Numerador.
            for (int i = 0; i < sign.size() + a.size() + c.size() - b.size(); ++i)
                cout << ' ';
            cout << b << '\n';
            //Linea de quebrado.
            cout << sign << a;
            for (int i = 0; i < c.size(); ++i)
                cout << '-';
            cout << '\n';
            //Denominador.
            for (int i = 0; i < sign.size() + a.size(); ++i)
                cout << ' ';
            cout << c << '\n';
        }

        cin >> n;
    }
    return 0;
}
