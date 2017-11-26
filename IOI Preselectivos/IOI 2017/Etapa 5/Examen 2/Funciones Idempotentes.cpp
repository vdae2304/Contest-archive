#include <bits/stdc++.h>
using namespace std;
#define MAXN 201

int N, f[MAXN];
int max_c, vis[MAXN];
long long ans, mcm = 1;

int getCycle(int i) {
    int c = 0;
    memset(vis, 0, sizeof vis);
    while (!vis[i]) {
        vis[i] = c++;
        i = f[i];
    }
    max_c = max(max_c, vis[i]);
    return c - vis[i];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> f[i];

    for (int i = 1; i <= N; i++) {
        long long tmp = getCycle(i);
        mcm = mcm * tmp / __gcd(mcm, tmp);
    }

    while (ans < max_c)
        ans += mcm;
    cout << ans;
}
