#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N, U;
    cin >> N >> U;

    int E[N];
    for (int i = 0; i < N; i++)
        cin >> E[i];

    long double ans = -1;
    for (int i = 1; i < N; i++) {
        int j = distance(E, upper_bound(E, E + N, E[i - 1] + U)) - 1;
        if (j > i && E[j] - E[i - 1] <= U)
            ans = max(ans, (long double)(E[j] - E[i]) / (E[j] - E[i - 1]));
    }

    cout << setprecision(9) << ans << "\n";
    return 0;
}
