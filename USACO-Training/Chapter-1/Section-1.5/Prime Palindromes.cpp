/*
ID: vdae_231
PROG: pprime
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int a, b;

bool prime(int p) {
    if (p < a || p > b)
        return false;
    for (int i = 2; i * i <= p; i++)
        if (!(p % i))
            return false;
    return true;
}

void gen_pal(int d, int m, ofstream &cout) {
    if (d-- <= 0) {
        int N = m;
        while (m >= 10) {
            m /= 10;
            N = 10 * N + (m % 10);
        }
        if (prime(N))
            cout << N << "\n";
    }
    else
        for (int i = 0; i < 10; i++)
            gen_pal(d, 10 * m + i, cout);
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("pprime.in");
    ofstream cout("pprime.out");
    cin >> a >> b;

    for (int i = 3; i <= 11; i += 2)
        if (i != 9 && a <= i && i <= b)
            cout << i << "\n";

    for (int i = 2; i <= 5; i++)
        for (int j = 1; j < 10; j += 2)
            gen_pal(i - 1, j, cout);
}
