#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ulli;

ulli divide(ulli &N, ulli i) {
    ulli S = 1;
    for (ulli j = i; !(N % i); j *= i) {
        S += j;
        N /= i;
    }
    return S;
}

ulli divisores(ulli N) {
    ulli p = divide(N, 2) * divide(N, 3);

    for (ulli i = 5; i * i <= N; i += 6)
        p *= divide(N, i) * divide(N, i + 2);

    return N == 1 ? p : p * (N + 1);
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ulli N;
    cin >> N;
    cout << divisores(N) - N;
}
