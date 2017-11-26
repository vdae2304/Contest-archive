#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    string s;
    cin >> s;

    int ans[4] = {}, ri, bi, yi, gi;
    for (int i = 0; i < s.size(); i++)
        switch (s[i]) {
            case 'R': ri = i % 4; break;
            case 'B': bi = i % 4; break;
            case 'Y': yi = i % 4; break;
            case 'G': gi = i % 4; break;
            case '!': ans[i % 4]++;
        }

    cout << ans[ri] << " " << ans[bi] << " " << ans[yi] << " " << ans[gi] << "\n";
}
