#include <iostream>
using namespace std;
typedef unsigned long long ulli;

ulli mcd(ulli a, ulli b) {
    return b ? mcd(b, a % b) : a;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ulli N, a, b;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        if (mcd(max(a, b), min(a, b)) > 1)
            cout << "NO\n";
        else
            cout << "SI\n";
    }
}
