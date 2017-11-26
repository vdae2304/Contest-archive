/*
ID: vdae_231
PROG: sprime
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

bool prime(int p) {
    for (int i = 2; i * i <= p; i++)
        if (!(p % i))
            return false;
    return true;
}

void gen_sprime(int m, int d, ofstream &cout) {
    if (!prime(m))
        return;
    if (d-- <= 0)
        cout << m << "\n";
    else
        for (int i = 1; i < 10; i += 2)
            gen_sprime(10 * m + i, d, cout);
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("sprime.in");
    ofstream cout("sprime.out");
    int N;
    cin >> N;
    for (int i = 2; i < 10; i++)
        gen_sprime(i, N - 1, cout);
}
