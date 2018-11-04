#include <bits/stdc++.h>
using namespace std;
typedef long long lld;

bool prime(lld n) {
    for (lld i = 2; i * i <= n; i++)
        if (!(n % i))
            return false;
    return n > 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    lld t, a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        if (a - b == 1 && prime(a + b))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
