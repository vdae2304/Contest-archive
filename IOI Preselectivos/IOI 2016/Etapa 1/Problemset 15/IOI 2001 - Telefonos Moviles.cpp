#include <bits/stdc++.h>
using namespace std;

int N, c;
int v[1025][1025];

void actualizar(int x, int y, int m) {
    for (int i = x; i <= N; i += (i & -i))
        for (int j = y; j <= N; j += (j & -j))
            v[i][j] += m;
}

int area(int x, int y) {
    if (!x || !y)
        return 0;

    int S = 0;
    for (int i = x; i > 0; i -= (i & - i))
        for (int j = y; j > 0; j -= (j & -j))
            S += v[i][j];

    return S;
}

int cuenta(int i, int j, int x, int y) {
    return area(x, y) - area(x, j) - area(i, y) + area(i, j);
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> c >> N >> c;

    while (c != 3) {
        int i, j, x, y, m;
        if (c == 1) {
            cin >> i >> j >> m;
            actualizar(i + 1, j + 1, m);
        }
        else {
            cin >> i >> j >> x >> y;
            cout << cuenta(i, j, x + 1, y + 1) << "\n";
        }
        cin >> c;
    }
}
