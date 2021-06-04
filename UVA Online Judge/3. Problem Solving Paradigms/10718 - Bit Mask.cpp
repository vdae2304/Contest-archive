#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    unsigned int N, L, U;

    while (cin >> N >> L >> U) {
        //Generamos M bit por bit, empezando por el mas significativo.
        //Para maximizar el or, siempre nos conviene activar cada bit.
        unsigned int M = 0;
        for (unsigned int bit = 1 << 31; bit > 0; bit >>= 1) 
            //Activamos el bit si: activarlo no viola M <= U y, no activarlo viola
            //L <= M o N no tiene activado el bit.
            if (M + bit <= U && (M + bit - 1 < L || !(N & bit))) 
                M |= bit;
            
        //Imprime la respuesta.
        cout << M << '\n';
    }

    return 0;
}