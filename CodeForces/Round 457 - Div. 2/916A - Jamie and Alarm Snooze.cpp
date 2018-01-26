#include <bits/stdc++.h>
using namespace std;

int h, m, x, ans;

bool check(int a) {
    while (a) {
        if (a % 10 == 7)
            return true;
        a /= 10;
    }
    return false;
}

void substract() {
    if (m >= x)
        m -= x;
    else {
        m += 60 - x;
        if (h > 0)
            h--;
        else
            h = 23;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> x >> h >> m;

    while (!check(h) && !check(m)) {
        substract();
        ans++;
    }
    cout << ans << "\n";
    return 0;
}
