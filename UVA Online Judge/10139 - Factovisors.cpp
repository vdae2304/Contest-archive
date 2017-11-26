#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

vector<pii> canonica(int n) {
    vector<pii> out;
    for (int i = 2; i * i <= n; i++)
        if (!(n % i)) {
            int e = 0;
            while (!(n % i)) {
                n /= i;
                e++;
            }
            out.push_back(pii(i, e));
        }
    if (n != 1)
        out.push_back(pii(n, 1));
    return out;
}

bool divisible(int n, vector<pii> v) {
    for (int i = 0; i < v.size(); i++) {
        int s = 0;
        for (long long p = v[i].first; p <= n; p *= v[i].first)
            s += n / p;
        if (s < v[i].second)
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int m, n;
    while (cin >> n >> m) {
        if (m && (n >= m || divisible(n, canonica(m))))
            cout << m << " divides " << n << "!\n";
        else
            cout << m << " does not divide " << n << "!\n";
    }
}
