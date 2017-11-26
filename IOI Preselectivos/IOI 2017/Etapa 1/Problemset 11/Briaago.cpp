#include <bits/stdc++.h>
using namespace std;

int N, v[1000];
long long DP[2][1001][1001];

void Briaago(int a, int b) {
    if (a <= b && !DP[0][a][b] && !DP[1][a][b]) {
        bool turno = (N - b + a) % 2;
        Briaago(a + 1, b); Briaago(a, b - 1);
        if (v[a] + DP[turno][a + 1][b] > v[b] + DP[turno][a][b - 1]) {
            DP[turno][a][b] = v[a] + DP[turno][a + 1][b];
            DP[!turno][a][b] = DP[!turno][a + 1][b];
        }
        else {
            DP[turno][a][b] = v[b] + DP[turno][a][b - 1];
            DP[!turno][a][b] = DP[!turno][a][b - 1];
        }
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> v[i];
        
    Briaago(0, N - 1);
    cout << DP[1][0][N - 1];
}
