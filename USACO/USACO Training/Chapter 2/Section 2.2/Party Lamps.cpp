/*
ID: vdae_231
PROG: lamps
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int N, C;
int isOn, known;
int Button[4] = {63, 42, 21, 36};
bool nSolutions, isSolution[64];

void solve(int lights, int i) {
    if (i++ >= C) {
        if ((lights & known) == isOn)
            isSolution[lights] = true;
    }
    else {
        for (int j = 0; j < 4; j++)
            solve(lights ^ Button[j], i);
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("lamps.in");
    ofstream cout("lamps.out");
    cin >> N >> C;

    int a, b = 1;
    while (cin >> a) {
        if (a == -1)
            b = 0;
        else {
            a = 5 - (--a % 6);
            if (b)
                isOn |= 1 << a;
            known |= 1 << a;
        }
    }

    C = min(C, 3);
    solve(63, 0);

    for (int i = 0; i < 64; i++)
        if (isSolution[i]) {
            nSolutions = true;
            for (int j = 0; j < N; j++)
                cout << bool(i & (1 << (5 - (j % 6))));
            cout << "\n";
        }

    if (!nSolutions)
        cout << "IMPOSSIBLE\n";
}
