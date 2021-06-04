#include <iostream>
#include <map>
using namespace std;

//Regresa la factorizacion en primos de un numero.
map<int, int> prime_factors(int n) {
    map<int, int> factors;
    for (int i = 2; i * i <= n; ++i)    
        while (n % i == 0) {
            factors[i]++;
            n /= i;
        }
    if (n != 1)
        factors[n] = 1;
    return factors;
}

//Regresa el menor B (o -1 si no existe) tal que lcm(A, B) = C.
int solve(int A, int C) {
    map<int, int> A_factors = prime_factors(A), C_factors = prime_factors(C);
    map<int, int>::iterator it;
    
    //Si A es divisible por una potencia de primo que no divide a C, entonces no existe B.
    for (it = A_factors.begin(); it != A_factors.end(); ++it) 
        if (C_factors[it->first] < it->second)
            return -1;

    //Si C es divisible por una potencia de primo que no divide a A, entonces la agregamos a B.
    int B = 1;
    for (it = C_factors.begin(); it != C_factors.end(); ++it) 
        if (A_factors[it->first] < it->second) {
            for (int i = 0; i < it->second; ++i)
                B *= it->first;
        }

    return B;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    int T, A, C;
    cin >> T;

    while (T--) {
        cin >> A >> C;
        int B = solve(A, C);
        if (B != -1)
            cout << B << '\n';
        else
            cout << "NO SOLUTION\n";
    }

    return 0;
}