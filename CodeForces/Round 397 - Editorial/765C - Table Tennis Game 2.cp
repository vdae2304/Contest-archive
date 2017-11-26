#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int K, A, B;
    cin >> K >> A >> B;
    if (A < K && B < K || (A % K && B < K) || (B % K && A < K))
        cout << "-1\n";
    else
        cout << A / K + B / K << "\n";
}
