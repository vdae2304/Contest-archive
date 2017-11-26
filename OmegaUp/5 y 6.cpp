#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int a[2] = {}, b[2] = {};
    string n[2];
    cin >> n[0] >> n[1];

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n[i].size(); j++) {
            if (n[i][j] == '5' || n[i][j] == '6') {
                a[i] = 10 * a[i] + 5;
                b[i] = 10 * b[i] + 6;
            }
            else {
                a[i] = 10 * a[i] + n[i][j] - '0';
                b[i] = 10 * b[i] + n[i][j] - '0';
            }
        }

    cout << a[0] + a[1] << " " << b[0] + b[1];
}
