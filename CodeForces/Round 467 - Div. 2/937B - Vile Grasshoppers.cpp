#include <bits/stdc++.h>
using namespace std;

//Check if n has a prime factor not greater than p
bool primefact(int n, int p) {
    for (int i = 2; i <= p && i * i <= n; i++)
        if (!(n % i))
            return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int P, Y, q;
    cin >> P >> Y;

    for (q = Y; primefact(q, q); q--);
    if (P >= q)
        cout << "-1\n";
    else
        for (int i = Y; i >= q; i--)
            if (!primefact(i, P)) {
                cout << i << "\n";
                break;
            }

    return 0;
}
