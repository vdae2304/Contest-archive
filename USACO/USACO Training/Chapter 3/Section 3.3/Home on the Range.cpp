/*
ID: vdae_231
PROG: range
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int N;
char c;
bool land[250][250], DP[250][250];

int check(int len) {
    int total = 0;
    for (int i = 0; i <= N - len; i++)
        for (int j = 0; j <= N - len; j++) {
            bool aux = DP[i][j];
            for (int k = 0; aux && k < len; k++)
                aux = aux && land[i + len - 1][j + k] && land[i + k][j + len - 1];
            DP[i][j] = aux;
            total += DP[i][j];
        }
    return total;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("range.in");
    ofstream cout("range.out");
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            cin >> c;
            land[i][j] = (c == '1');
        }
    memcpy(DP, land, sizeof(DP));

    for (int i = 2; i <= N; i++) {
        int cont = check(i);
        if (cont)
            cout << i << " " << cont << "\n";
    }
}
