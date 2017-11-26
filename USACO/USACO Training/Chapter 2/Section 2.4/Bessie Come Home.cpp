/*
ID: vdae_231
PROG: comehome
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("comehome.in");
    ofstream cout("comehome.out");
    int P;
    cin >> P;

    int path[128][128];
    for (int i = 0; i < 128; i++)
        for (int j = 0; j < 128; j++)
            path[i][j] = 1000000;

    while (P--) {
        char a, b; int d;
        cin >> a >> b >> d;
        path[a][b] = path[b][a] = min(path[a][b], d);
    }

    for (int k = 0; k < 128; k++)
        for (int i = 0; i < 128; i++)
            for (int j = 0; j < 128; j++)
                path[i][j] = min(path[i][j], path[i][k] + path[k][j]);

    char firstCow = 'A';
    for (char i = 'B'; i < 'Z'; i++)
        if (path[i]['Z'] < path[firstCow]['Z'])
            firstCow = i;

    cout << firstCow << " " << path[firstCow]['Z'] << "\n";
}
