#include <bits/stdc++.h>
using namespace std;

int N, v[21], ans = INFINITY;
bitset<2010> visitado[21][2010];

vector<int> suma(vector<int> P, int i, int x) {
    P[i] += x;
    sort(P.begin(), P.end());
    return P;
}

void calcular(int i, vector<int> P) {
    if (i == N)
        ans = min(P[2], ans);
    else if (!visitado[i][P[0]][P[1]]) {
        visitado[i][P[0]][P[1]] = true;
        for (int j = 0; j < 3; j++)
            calcular(i + 1, suma(P, j, v[i]));
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> v[i];
    calcular(0, vector<int> (3, 0));
    cout << ans;
}
