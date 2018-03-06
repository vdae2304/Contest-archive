#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N, ans = 1;
    cin >> N;

    int A[N];
    for (int i = 0; i < N; i++)
        cin >> A[i];
    sort (A, A + N);

    for (int i = N - 2; i >= 0; i--) {
        if (!A[i])
            break;
        if (A[i] != A[i + 1])
            ans++;
    }

    cout << ans;
    return 0;
}
