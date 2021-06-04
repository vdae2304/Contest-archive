#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    //Definimos:
    // sum[n][x]   - numero de formas distintas de sumar x con n dados.
    // least[n][x] - numero de formas distintas de sumar al menos x con n dados.
    long long sum[25][25*6], least[25][25*6]; 

    memset(sum, 0, sizeof sum);
    memset(least, 0, sizeof least);
    sum[0][0] = 1;
    least[0][0] = 1;

    for (int n = 1; n <= 24; ++n) {
        for (int x = n; x <= 6*n; ++x) 
            //Para sumar x con n dados, debimos haber sumado x - 6, ... , x - 1 con n - 1 dados.
            for (int k = max(0, x - 6); k < x ; ++k)
                sum[n][x] += sum[n - 1][k];
        
        //Sumas acumuladas.
        for (int x = 6*n; x >= 0; --x)
            least[n][x] = least[n][x + 1] + sum[n][x];
    }

    //Leemos los casos.
    int n, x;
    while (cin >> n >> x, !(n == 0 && x == 0)) {
        long long a = least[n][x] / __gcd(least[n][x], least[n][0]);
        long long b = least[n][0] / __gcd(least[n][x], least[n][0]);

        if (a % b == 0)
            cout << a/b << '\n';
        else 
            cout << a << '/' << b << '\n';
    }

    return 0;
}