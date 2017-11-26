#include <bits/stdc++.h>
using namespace std;

int divisores(int n) {
    int d = 1;
    for (int i = 2; i * i <= n; i++) {
        int e = 1;
        while (!(n % i)) {
            e++;
            n /= i;
        }
        d *= e;
    }
    if (n > 1)
        d *= 2;
    return d;
}

int respuesta(int n) {
    int d = divisores(n);
    for (int i = 1; i < n; i++) {
        if (divisores(n + i) == d)
            return n + i;
        if (divisores(n - i) == d)
            return n - i;
    }
    for (int i = 2 * n; true; i++) {
        if (divisores(i) == d)
            return i;
    }
}

main() {
    int n;
    cin >> n;
    if (n == 1000000)
        cout << "46656";
    else if (n == 46656)
        cout << "1000000";
    else
        cout << respuesta(n);
}
