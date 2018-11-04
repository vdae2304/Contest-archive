#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
typedef pair<lld, lld> pii;
#define mod 998'244'353

lld N, x, ans = 1;
map<lld, lld> a, prime_fact;

lld nth_power(lld a, lld n) {
    lld r = 1;
    while (n--)
        r = (r > 2e18 / a) ? 2e18 : r * a;
    return r;
}

/*Returns nth-root if it's integer. -1 otherwise*/
lld is_nth_power(lld a, lld n) {
    lld l = 1, r = 3e18;
    while (l < r) {
        lld m = (l + r + 1) / 2;
        if (nth_power(m, n) > a)
            r = m - 1;
        else
            l = m;
    }
    if (nth_power(l, n) == a)
        return l;
    return -1;
}

/*Case 1: n = p^k, k = 2, 3, 4*/
bool Case1(pii n) {
    for (lld k = 4; k >= 2; k--) {
            lld p = is_nth_power(n.first, k);
            if (p != -1) {
                prime_fact[p] += k * n.second;
                return true;
            }
        }
    return false;
}

/*Case 2: n = pq*/
void Case2(pii n) {
    lld p = 1;
    for (pii x : a) //Look for prime factorization via gcd
        if (x != n)
            p = max(p, __gcd(n.first, x.first));
    if (p == 1)
        ans = (ans * (n.second + 1) * (n.second + 1)) % mod;
    else {
        prime_fact[p] += n.second;
        prime_fact[n.first / p] += n.second;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;
    while (N--) {
        cin >> x;
        a[x]++;
    }
    for (pii n : a)
        if (!Case1(n))
            Case2(n);
    for (pii n : prime_fact)
        ans = (ans * (n.second + 1)) % mod;
    cout << ans << endl;
    return 0;
}
