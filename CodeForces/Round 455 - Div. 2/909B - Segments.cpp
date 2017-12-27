#include <bits/stdc++.h>
using namespace std;
#define MAXN 200
int layers[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N, ans = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
            for (int k = i; k <= j; k++)
                layers[k]++;

    for (int i = 0; i < MAXN; i++)
        ans = max(ans, layers[i]);
    cout << ans << "\n";
    return 0;
}
