/*
ID: vdae_231
PROG: combo
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int N, answer;

bool range(int a, int b) {
    return (abs(a - b) <= 2 || abs(a - b) >= N - 2);
}

bool close(int i, int j, int k, int a, int b, int c) {
    return (range(i, a) && range(j, b) && range(k, c));
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("combo.in");
    ofstream cout("combo.out");
    int a, b, c, x, y, z;
    cin >> N >> a >> b >> c >> x >> y >> z;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            for (int k = 1; k <= N; k++)
                if (close(i, j, k, a, b, c) || close(i, j, k, x, y, z))
                    answer++;

    cout << answer << "\n";
}
