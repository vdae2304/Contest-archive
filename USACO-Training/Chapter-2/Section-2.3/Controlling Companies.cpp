/*
ID: vdae_231
PROG: concom
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int N, owns[101][101];
bool controls[101][101];

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("concom.in");
    ofstream cout("concom.out");
    cin >> N;

    while (N--) {
        int i, j, p;
        cin >> i >> j >> p;
        owns[i][j] = p;
    }

    for (int i = 1; i <= 100; i++)
        for (int j = 1; j <= 100; j++)
            if (i != j && !controls[i][j] && owns[i][j] > 50) {
                controls[i][j] = true;
                for (int k = 1; k <= 100; k++) {
                    owns[i][k] += owns[j][k];
                    if (controls[j][k])
                        controls[i][k] = true;
                }
                j = 0;
            }

    for (int i = 1; i <= 100; i++)
        for (int j = 1; j <= 100; j++)
            if (i != j && controls[i][j])
                cout << i << " " << j << "\n";
}
