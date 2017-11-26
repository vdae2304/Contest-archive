#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N, H, B;
    cin >> N >> H >> B;

    int v[N], x = 1 << 30;
    long long S = 0;
    for (int i = 0, cont = 0; i < N; i++) {
        cin >> v[i];
        if (v[i] >= H) {
            cont++;
            x = min(x, v[i]);
        }
        else
            cont = 0;
        if (cont >= B) {
            cout << "0\n";
            return 0;
        }
    }

    for (int i = 0; i < N; i++)
        S += max((long long) (x - v[i]) * (i + 1), 0ll);
    cout << S;
}
