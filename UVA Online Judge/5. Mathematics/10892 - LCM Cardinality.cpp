#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int N;
long long C;
vector< pair<int, int> > factors;

//Encuentra la descomposicion canonica de n.
void prime_factor(int n) {
    factors.clear();
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) {
            factors.push_back(make_pair(i, 0));
            while (n % i == 0) {
                n /= i;
                factors[factors.size() - 1].second++;
            }
        }
    if (n > 1)
        factors.push_back(make_pair(n, 1));
}

// Notemos que si a = p1^e1 ... pk^ek y b = p1^f1 ... pk^fk, entonces
// lcm(a, b) = p1^max(e1,f1) ... pk^max(ek,fk). Asi pues, conociendo la descomposicion
// canonica de lcm, podemos reconstruir a y b de la siguiente manera:
// por cada factor primo, alguno de los dos tendra el mismo exponente que lcm.
void solve(int i, long long cum_prod) {
    if (i == factors.size())
        C += cum_prod;
    else {
        //Decidimos quien tendra el maximo exponente. El otro tendra un exponente entre 0 y max-1.
        solve(i + 1, 2 * cum_prod * factors[i].second);
        //Ambos tendran el maximo exponente.
        solve(i + 1, cum_prod);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    while (cin >> N, N != 0) {
        //Observacion: todos los pares, excepto el (N, N) son contados dos veces.
        C = 1;
        prime_factor(N);
        solve(0, 1);
        cout << N << ' ' << C / 2 << '\n';
    }
    return 0;
}
