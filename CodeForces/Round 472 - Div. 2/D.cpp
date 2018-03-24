#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N;
    cin >> N;

    long long M[N + 1], marks[N + 1], ans = 0;
    marks[0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> M[i];
        marks[i] = max(marks[i - 1], M[i] + 1);
    }

    for (int i = N - 1; i >= 1; i--)
        marks[i] = max(marks[i], marks[i + 1] - 1);

    for (int i = 1; i <= N; i++)
        ans += marks[i] - M[i] - 1;

    cout << ans << "\n";
    return 0;
}