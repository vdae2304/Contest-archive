/*
ID: vdae_231
PROG: ariprog
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int N, M;
bool bisquare[125001];

bool valid(int i, int j) {
    for (int k = 0; k < N; k++)
        if (!bisquare[i + k * j])
            return false;
    return true;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("ariprog.in");
    ofstream cout("ariprog.out");
    cin >> N >> M;

    for (int i = 0; i <= M; i++)
        for (int j = 0; j <= M; j++)
            bisquare[i * i + j * j] = true;

    int MAXX = 2 * M * M, solutions = 0;
    for (int j = 1; j <= MAXX / (N - 1); j++)
        for (int i = 0; i <= MAXX - (N - 1) * j; i++)
            if (valid(i, j)) {
                cout << i << " " << j << "\n";
                solutions++;
            }

    if (!solutions)
        cout << "NONE\n";
}
