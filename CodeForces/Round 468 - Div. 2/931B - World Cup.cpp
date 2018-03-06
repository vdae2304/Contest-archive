#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N, round = 1, a, b;
    cin >> N >> a >> b;

    bool win[N + 1];
    memset(win, true, sizeof win);

    while (true) {
        for (int i, j = 0; ; round++) {
            for (i = j + 1; i <= N && !win[i]; i++);
            for (j = i + 1; j <= N && !win[j]; j++);

            if (j > N)
                break;

            if (i == a && j == b || i == b && j == a) {
                if (count(win + 1, win + N + 1, 1) == 2)
                    cout << "Final!";
                else
                    cout << round;
                return 0;
            }
            else if (i == a || i == b)
                win[j] = false;
            else
                win[i] = false;
        }
    }

    return 0;
}
