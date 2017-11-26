#include <bits/stdc++.h>
using namespace std;

int a, b, c;

void gen_num(int n, int i, int d) {
    if (d++ > 4)
        return;
    if (a <= n && n <= b)
        c++;
    for (int j = i + 1; j < 25; j++)
        gen_num(n + (1 << j), j, d);
}

main() {
    cin >> a >> b;
    gen_num(0, -1, 0);
    cout << c;
}
