#include <bits/stdc++.h>
using namespace std;

int N, B, M;
int v[50], DP[51][50000];

int maximo(int i, int vol) {
    if (vol < 0 || vol > M)
        return -1;
    if (i == N)
        return vol;
    if (!DP[i][vol])
        DP[i][vol] = max(maximo(i + 1, vol + v[i]), maximo(i + 1, vol - v[i]));
    return DP[i][vol];
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> v[i];

    cin >> B >> M;
    cout << maximo(0, B);
}
