#include <bits/stdc++.h>
using namespace std;

int N, S;
long long DP[65][65][2];

long long calcular(int i, int asegurado, bool ultimo) {
    if (i >= N)
        return asegurado == S;
    if (DP[i][asegurado][ultimo] == -1)
        DP[i][asegurado][ultimo] = calcular(i + 1, asegurado + 1, 1) + calcular(i + 1, asegurado - ultimo, 0);
    return DP[i][asegurado][ultimo];
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> S;
    memset(DP, -1, sizeof(DP));
    cout << calcular(0, 0, 0);
}
