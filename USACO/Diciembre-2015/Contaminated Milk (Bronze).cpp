#include <bits/stdc++.h>
using namespace std;

int N, M, D, S;
int p, m, t, mayor;
int bebio[51][51], enfermo[51];

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("badmilk.in");
    ofstream cout("badmilk.out");
    cin >> N >> M >> D >> S;

    for (int i = 0; i < D; ++i) {
        cin >> p >> m >> t;
        bebio[p][m] = t;
    }

    for (int i = 0; i < S; ++i) {
        cin >> p >> t;
        enfermo[p] = t;
    }

    for (int i = 1; i <= M; ++i) {
        bool p = true;

        for (int j = 1; p && j <= N; ++j)
            if (enfermo[j] && (!bebio[j][i] || enfermo[j] <= bebio[j][i]))
                p = false;

        if (p) {
            int m = 0;
            for (int j = 1; j <= N; ++j)
                if (bebio[j][i])
                    ++m;
            mayor = max(mayor, m);
        }
    }

    cout << mayor;
}
