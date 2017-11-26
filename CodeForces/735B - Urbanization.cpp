#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N, N1, N2;
    cin >> N >> N1 >> N2;

    double  v[N], A = 0, B = 0;
    for (int i = 0; i < N; i++)
        cin >> v[i];
    sort(v, v + N);

    if (N2 < N1)
        swap(N1, N2);
    for (int i = N - 1; i >= N - N1; i--)
        A += v[i];
    for (int i = N - N1 - 1; i >= N - N1 - N2; i--)
        B += v[i];

    cout << setprecision(6) << fixed << A / N1 + B / N2;
}
