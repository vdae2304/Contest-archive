/*
ID: vdae_231
PROG: crypt1
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

bool digit[10];
bool valid(int N, int d) {
    while (N) {
        if (!digit[N % 10])
            return false;
        N /= 10;
        d--;
    }
    return !d;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("crypt1.in");
    ofstream cout("crypt1.out");
    int N, x, answer = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x;
        digit[x] = true;
    }

    for (int i = 100; i < 1000; i++)
        for (int j = 10; j < 100; j++)
            if (valid(i, 3) && valid(j, 2) && valid(i*(j % 10), 3) && valid(i*(j / 10), 3) && valid(i * j, 4))
                answer++;

    cout << answer << "\n";
}
