/*
ID: vdae_231
PROG: frac1
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

bool order(pair<int, int> a, pair<int, int> b) {
    return a.first * b.second < b.first * a.second;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("frac1.in");
    ofstream cout("frac1.out");
    int N;
    cin >> N;

    vector<pair<int, int> > v;
    for (int j = 1; j <= N; j++)
        for (int i = 0; i <= j; i++)
            if (__gcd(i, j) == 1)
                v.push_back(make_pair(i, j));

    sort(v.begin(), v.end(), order);
    for (int i = 0; i < v.size(); i++)
        cout << v[i].first << "/" << v[i].second << "\n";
}
