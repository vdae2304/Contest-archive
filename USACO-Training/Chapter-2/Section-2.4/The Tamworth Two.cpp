/*
ID: vdae_231
PROG: ttwo
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

char grid[10][10];
int mov[2][4] = {{-1, 0, 1, 0}, {0, 1, 0, -1}};

bool valid_position(int i, int j) {
    return 0 <= i && i < 10 && 0 <= j && j < 10 && grid[i][j] != '*';
}

void next_move(int &i, int &j, int &k) {
    if (valid_position(i + mov[0][k], j + mov[1][k]))
        i += mov[0][k], j += mov[1][k];
    else
        k = ++k % 4;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("ttwo.in");
    ofstream cout("ttwo.out");
    int Fi, Fj, Fk, Ci, Cj, Ck, t;

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'F')
                Fi = i, Fj = j, Fk = 0;
            else if (grid[i][j] == 'C')
                Ci = i, Cj = j, Ck = 0;
        }

    for (t = 0; t < 160000 && (Fi != Ci || Fj != Cj); t++) {
        next_move(Fi, Fj, Fk);
        next_move(Ci, Cj, Ck);
    }

    if (Fi == Ci && Fj == Cj)
        cout << t << "\n";
    else
        cout << "0\n";
}
