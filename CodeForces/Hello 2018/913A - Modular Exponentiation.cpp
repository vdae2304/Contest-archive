#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    long long n, m;
    cin >> n >> m;
    if (n < 32)
        cout << m % (1ll << n);
    else
        cout << m;
    return 0;
}
