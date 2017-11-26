#include <bits/stdc++.h>
using namespace std;

int N, K, total;
bool usado[16];

void cuenta(int diagonal, int alfiles) {
    if (!alfiles)
        total++;
    else if (diagonal + alfiles <= 2 * N) {
        int a, b;
        if (diagonal <= N)
            a = N - diagonal + 1, b = N + diagonal - 1;
        else
            a = diagonal - N + 1, b = 3 * N - diagonal - 1;

        for (int i = a; i <= b; i += 2)
            if (!usado[i]) {
                usado[i] = true;
                cuenta(diagonal + 1, alfiles - 1);
                usado[i] = false;
            }
        cuenta(diagonal + 1, alfiles);
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> K;
    cuenta(1, K);
    cout << total;
}
