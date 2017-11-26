#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000001

int N, X, v[MAXN];
int STree[20 * MAXN], DP[MAXN], h[MAXN];
long long area, usos;

void RMQ(int node, int a, int b) {
    if (a == b)
        STree[node] = v[a];
    else {
        int m = (a + b) / 2, ChL = 2 * node + 1, ChR = 2 * node + 2;
        RMQ(ChL, a, m); RMQ(ChR, m + 1, b);
        STree[node] = min(STree[ChL], STree[ChR]);
    }
}

int Consulta(int node, int a, int b, int i, int j) {
    if (b < i || a > j)
        return INFINITY;
    else if (i <= a && b <= j)
        return STree[node];
    else {
        int m = (a + b) / 2;
        return min(Consulta(2 * node + 1, a, m, i, j), Consulta(2 * node + 2, m + 1, b, i, j));
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> X;

    for (int i = 0; i < N; i++)
        cin >> v[i];
    RMQ(0, 0, N - 1);

    for (int i = 0; i <= N - X; i++)
        DP[i] = Consulta(0, 0, N - 1, i, i + X - 1);

    for (int i = 0, j = 0; i <= N - X; i++)
        if (DP[i] > h[i] || DP[i] > v[i + X]) {
            usos++;
            h[j] = DP[i];
            for (; j < i + X && DP[j] <= h[i]; j++)
                h[j] = DP[i];
        }

    for (int i = 0; i < N; i++)
        area += v[i] - h[i];

    cout << area << "\n" << usos;
}
