#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int a, b;
    cin >> a >> b;
    if (abs(a - b) <= 1 && (a || b))
        cout << "YES\n";
    else
        cout << "NO\n";
}
