/*
ID: vdae_231
PROG: nuggets
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
#define LIM 66000

int N, v[10], A, B;
bool possible[2 * LIM];

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("nuggets.in");
    ofstream cout("nuggets.out");
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> v[i];

    possible[0] = true;
    for (int i = 0; i < 2 * LIM; i++) {
        if (possible[i]) {
            for (int j = 0; j < N; j++)
                if (i + v[j] < 2 * LIM)
                    possible[i + v[j]] = true;
        }
        else if (i < LIM)
            A = i;
        else
            B = i;
    }

    if (A && !B)
        cout << A << "\n";
    else
        cout << "0\n";
}
