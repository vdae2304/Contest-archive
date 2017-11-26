#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int L;
    string A, B;
    cin >> L >> A >> B;

    int desp[26] = {};
    for (int i = 0; i < L; i++)
        desp[(B[i] - A[i] + 26) % 26]++;

    int mayor = 0;
    for (int i = 1; i < 26; i++)
        if (desp[i] > desp[mayor])
            mayor = i;

    cout << mayor << "\n";
    for (int i = 0; i < L; i++)
        cout << char((A[i] - 'A' + mayor) % 26 + 'A');
}
