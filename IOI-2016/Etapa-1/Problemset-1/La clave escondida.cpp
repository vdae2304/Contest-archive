#include <bits/stdc++.h>
using namespace std;
int suma[2][1000];
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    char x;
    int N;
    string L;

    for (int i = 0; i < 2; i++) {
        cin >> x >> N >> L;
        for (int j = 0; j < L.size(); j++) {
            L[j] = toupper(L[j]);
            suma[i][j % N] = (suma[i][j % N] + L[j] - 'A' + 1) % 10;
        }

        int m = 1;
        for (int j = 0; j < N; j++)
            m = (m * (suma[i][j] + 1)) % 10;

        if (i == 0)
            cout << m + 1 << "-";
        else
            cout << char(m + 'A');
    }
}
