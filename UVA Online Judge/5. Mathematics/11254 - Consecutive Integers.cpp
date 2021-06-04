#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    long long n;

    while (cin >> n, n != -1) {
        //Encontramos a y k tales que
        // n = a + (a + 1) + ... + (a + k - 1)
        long long a, k;

        //Tenemos que
        // n = ak + (k - 1)k / 2 = k(2a + k - 1) / 2
        //de donde
        // 2n = k(2a + k - 1)
        //Asi pues, probamos todos los divisores de 2n hasta sqrt(2n).
        for (long long i = 1; i * i <= 2*n; ++i) 
            if ((2*n) % i == 0) {
                //Despejando a obtenemos que
                // 2a = 2n/k - k + 1
                //de donde vemos que 2n/k - k + 1 es par.
                long long b = 2*n/i - i + 1;
                
                //Si obtenemos un a valido, actualizamos k.
                if (b % 2 == 0) {
                    a = b / 2;
                    k = i;
                }
            }
        
        cout << n << " = " << a << " + ... + " << a + k - 1 << '\n';
    }

    return 0;
}