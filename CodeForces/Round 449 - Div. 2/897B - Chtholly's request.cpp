#include <bits/stdc++.h>
using namespace std;

long long zcy_numer(int n) {
    long long a = n, b = 0, p = 1;
    while (n) {
        b = 10*b + n%10;
        n /= 10;
        p *= 10;
    }
    return a*p + b;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    long long k, p, s = 0;
    cin >> k >> p;

    for (int i = 1; i <= k; i++)
        s = (s + zcy_numer(i)) % p;

    cout << s << "\n";
}
