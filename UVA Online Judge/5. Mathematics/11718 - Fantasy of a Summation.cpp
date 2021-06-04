#include <iostream>
using namespace std;

//Exponenciacion modular.
int pow(int base, int exp, int mod) {
    if (exp == 0)
        return 1;
    else if (exp % 2) 
        return (base * pow(base, exp - 1, mod)) % mod;
    else {
        int p = pow(base, exp / 2, mod);
        return (p * p) % mod;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    int T, n, K, mod;
    cin >> T;

    for (int ncase = 1; ncase <= T; ++ncase) {
        cin >> n >> K >> mod;
        
        //Calcula la suma de todos los numeros.
        int sum = 0, Ai;
        for (int i = 0; i < n; ++i) {
            cin >> Ai;
            sum = (sum + (Ai % mod)) % mod;
        }

        //Calcula cuantas veces se sumara cada numero: para ello, fijamos la posicion
        //de la tupla donde ira el numero, y escogemos los demas elementos arbitrariamente,
        //lo cual se puede hacer de K*n^(K-1) formas. 
        int cont = ((K % mod) * pow(n, K - 1, mod)) % mod;

        //Imprime la respuesta.
        cout << "Case " << ncase << ": " << (sum * cont) % mod << '\n';
    }

    return 0;
}