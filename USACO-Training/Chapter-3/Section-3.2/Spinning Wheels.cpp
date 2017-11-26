/*
ID: vdae_231
PROG: spin
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int speed, W, start, extention;
bool alignment[5][360][360]; //Check if i-th wheel occupies position j at second k

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("spin.in");
    ofstream cout("spin.out");

    for (int i = 0; i < 5; i++) {
        cin >> speed >> W;
        for (int j = 0; j < W; j++) {
            cin >> start >> extention;
            for (int k = 0; k < 360; k++)
                for (int l = 0; l <= extention; l++)
                    alignment[i][(start + speed * k + l) % 360][k] = true;
        }
    }

    for (int k = 0; k < 360; k++)
        for (int j = 0; j < 360; j++) {
            bool aux = true;
            for (int i = 0; i < 5; i++)
                if (!alignment[i][j][k])
                    aux = false;
            if (aux) {
                cout << k << "\n";
                return 0;
            }
        }
    cout << "none\n";
}
