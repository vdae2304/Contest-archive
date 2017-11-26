#include <bits/stdc++.h>
using namespace std;

int H, L;
map<pair<int, int>, long long> DP;

long long cuenta(int h, int l) {
    if (l == 1)
        return h;
    if (DP.find(make_pair(h, l)) == DP.end())
        DP[make_pair(h, l)] = cuenta(h - 1, l / 2) + cuenta(h - 1, l - l / 2) + 2;
    return DP[make_pair(h, l)];
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> H >> L;
    cout << cuenta(H, L) + 1;
}
