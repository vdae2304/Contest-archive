#include <bits/stdc++.h>
using namespace std;
main() {
    ifstream cin("paint.in");
    ofstream cout("paint.out");
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b < c || d < a)
        cout << b - a + d - c;
    else
        cout << max(b, d) - min(a, c);
}
