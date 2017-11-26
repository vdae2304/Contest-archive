#include <bits/stdc++.h>
using namespace std;

int N, v[1000];
int DP[1000][1000];

int resolver(int a, int b) {
    int dia = N - b + a;
    if (a == b)
        return v[a] * dia;
    if (!DP[a][b])
        DP[a][b] = max(v[a] * dia + resolver(a + 1, b), v[b] * dia + resolver(a, b - 1));
    return DP[a][b];
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> v[i];
    cout << resolver(0, N - 1);
}
