#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int A, B, ans = INT_MAX;
    cin >> A >> B;

    if (A > B)
        swap (A, B);
    for (int i = A; i <= B; i++)
        ans = min(ans, (i - A)*(i - A + 1) / 2 + (B - i)*(B - i + 1) / 2);

    cout << ans << "\n";
    return 0;
}
