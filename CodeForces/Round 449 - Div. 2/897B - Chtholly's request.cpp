#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    long long k, p, sum = 0;
    cin >> k >> p;
    vector<long long> zcy;

    for (int i = 1; i <= 1e5; i++) {
        stringstream toStr, toLong;
        string s;
        long long aux;

        toStr << i;
        toStr >> s;
        reverse(s.begin(), s.end());
        toLong << i << s;
        toLong >> aux;

        zcy.push_back(aux);
    }
    sort(zcy.begin(), zcy.end());

    for (int i = 0; i < k; i++)
        sum = (sum + zcy[i]) % p;
    cout << sum << "\n";
    return 0;
}
