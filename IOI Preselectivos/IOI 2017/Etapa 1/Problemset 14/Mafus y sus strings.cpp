#include <bits/stdc++.h>
using namespace std;

int resolver(int l1, int r1, int l2, int r2, int c = 30) {
    if (l1 > r1 || l2 > r2)
        return 0;

    int ans = max(min(r1, r2) - max(l1, l2) + 1, 0);
    int m = ((1 << c) - 1) / 2 + 1;

    if ((l1 <= l2 && r2 <= r1) || (l2 <= l1 && r1 <= r2))
        return ans;

    int l[4] = {min(l1, m), max(m + 1, l1) - m, min(l2, m), max(m + 1, l2) - m};
    int r[4] = {min(r1, m - 1), max(m, r1) - m, min(r2, m - 1), max(m, r2) - m};

    for (int i = 0; i < 2; i++)
        for (int j = 2; j < 4; j++)
            ans = max(ans, resolver(l[i], r[i], l[j], r[j], c - 1));

    return ans;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    cout << resolver(l1, r1, l2, r2);
}
