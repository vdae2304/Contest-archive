#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int a = 2*A, b = 2*B, c = max(C, D);
    if ((D <= a && 2*D < a) && (D <= b && 2*D < b) && c <= 2*C && c <= 2*D)
        cout << a << "\n" << b << "\n" << c << "\n";
    else
        cout << "-1\n";
    return 0;
}
