#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    string s;
    long long ans = 0, K;
    cin >> K >> s;

    for (int i = 0, j = 0, k = 0, c = 0; i < s.size(); i++) {
        for (j = max(i, j); c < K && j < s.size(); j++)
            c += (s[j] == '1');
        if (c < K)
            break;
        for (k = max(k, j); k < s.size() && s[k] == '0'; k++);
        ans += k - j + (K != 0);
        c = max(0, c - (s[i] == '1'));
    }

    cout << ans << "\n";
}
