#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int M, N;
    cin >> M >> N;
    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++) {
            char c;
            cin >> c;
            if (c == '*')
                cout << i << " " << j << "\n";
        }
}
