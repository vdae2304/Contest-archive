/*
ID: vdae_231
PROG: ratios
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int mixture[4][3], ans[4] = {0, 0, 0, INT_MAX};
bool visited[100][100][100];

int getRatio(int S, int x) {
    if (x)
        return (!S || S % x) ? -1 : S / x;
    return S ? -1 : -2; //-1 = impossible, -2 = any number
}

bool check(int k1, int k2, int k3) {
    return k1 != -1 && k2 != -1 && k3 != -1 && (k1 == k2 || k1 == -2 || k2 == -2) && (k2 == k3 || k2 == -2 || k3 == -2);
}

void Solve(int C1, int C2, int C3) {
    if (C1 >= 100 || C2 >= 100 || C3 >= 100 || visited[C1][C2][C3])
        return;
    visited[C1][C2][C3] = true;

    int k1 = getRatio(C1 * mixture[1][0] + C2 * mixture[2][0] + C3 * mixture[3][0], mixture[0][0]);
    int k2 = getRatio(C1 * mixture[1][1] + C2 * mixture[2][1] + C3 * mixture[3][1], mixture[0][1]);
    int k3 = getRatio(C1 * mixture[1][2] + C2 * mixture[2][2] + C3 * mixture[3][2], mixture[0][2]);

    if (check(k1, k2, k3)) {
        int d = max(max(k1, k2), k3);
        if (d < ans[3])
            ans[0] = C1, ans[1] = C2, ans[2] = C3, ans[3] = d;
    }
    else {
        Solve(C1 + 1, C2, C3);
        Solve(C1, C2 + 1, C3);
        Solve(C1, C2, C3 + 1);
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("ratios.in");
    ofstream cout("ratios.out");
    
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 3; j++)
            cin >> mixture[i][j];
    Solve(0, 0, 0);

    if (ans[3] == INT_MAX)
        cout << "NONE\n";
    else
        cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << "\n";
}
