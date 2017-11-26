#include <bits/stdc++.h>
using namespace std;

bool esprimo(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (!(n % i))
            return false;
    return true;
}

bool subprimo(int n) {
    int d = 0;
    for (int i = 2; i * i <= n; i++) {
        while (!(n % i)) {
            d++;
            n /= i;
        }
    }
    if (n > 1)
        d++;
    return esprimo(d);
}

main() {
    int a, b, c = 0;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
        if (subprimo(i))
            c++;
    cout << c;
}
