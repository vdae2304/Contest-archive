/*
ID: vdae_231
PROG: cowtour
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
#define inf 1000000

int N;
int X[150], Y[150];
double dist[150][150];
double diameter[150], ans = inf;

double getDistance(int i, int j) {
    double dx = X[i] - X[j], dy = Y[i] - Y[j];
    return sqrt(dx * dx + dy * dy);
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("cowtour.in");
    ofstream cout("cowtour.out");
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> X[i] >> Y[i];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            char c;
            cin >> c;
            if (c == '1')
                dist[i][j] = getDistance(i, j);
            else if (i != j)
                dist[i][j] = inf;
        }

    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (dist[i][j] != inf)
                diameter[i] = max(diameter[i], dist[i][j]);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (dist[i][j] == inf)
                ans = min(ans, diameter[i] + diameter[j] + getDistance(i, j));

    for (int i = 0; i < N; i++)
        ans = max(ans, diameter[i]);

    cout << fixed << setprecision(6) << ans << "\n";
}
