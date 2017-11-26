#include <bits/stdc++.h>
using namespace std;

long long Modular_Product(long long a, long long b, long long m) {
    long long ans = 0;
    for (; b; a = (2 * a) % m, b /= 2)
        if (b % 2)
            ans = (ans + a) % m;
    return ans;
}

long long Modular_Exponentiation(long long b, long long e, long long m) {
    if (!e)
        return 1;
    else {
        long long p = Modular_Exponentiation(b, e / 2, m);
        p = Modular_Product(p, p, m);
        return e % 2 ? Modular_Product(b, p, m) : p;
    }
}

void Euclidean_Algorithm(long long a, long long b, long long &x, long long &y) {
    if (!(a % b))
        x = 0, y = 1;
    else {
        Euclidean_Algorithm(b, a % b, y, x);
        y -= (a / b) * x;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    long long n, e, m, message;
    long long p, q, d, phi, max_m;
    cin >> n >> e >> m;

    for (p = 2; n % p; p++);
    q = n / p;
    phi = (p - 1) * (q - 1);

    Euclidean_Algorithm(phi, e, max_m, d);
    d = (d + phi) % phi;
    for (max_m = 0; 100*max_m + 25 <= n; max_m = 100*max_m + 25);

    while (m--) {
        string ans;
        cin >> message;
        message = Modular_Exponentiation(message, d, n);

        for (long long i = max_m; i > 100 * message; i /= 100)
            cout << "A";
        for (; message; message /= 100)
            ans.push_back((message % 100) + 'A');
        for (int i = ans.size() - 1; i >= 0; i--)
            cout << ans[i];
    }
}
