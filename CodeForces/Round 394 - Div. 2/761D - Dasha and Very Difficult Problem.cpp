#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000

int N, l, r;
int A[MAXN], B[MAXN];
pair<int, int> C[MAXN];

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> l >> r;

    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++) {
        cin >> C[i].first;
        C[i].second = i;
    }
    sort(C, C + N);

    B[C[N - 1].second] = r;
    for (int i = N - 2; i >= 0; i--) {
        if (B[C[i + 1].second] - A[C[i + 1].second] + A[C[i].second] <= l) {
            cout << "-1\n";
            return 0;
        }
        B[C[i].second] = min(r, B[C[i + 1].second] - A[C[i + 1].second] + A[C[i].second] - 1);
    }

    for (int i = 0; i < N; i++)
        cout << B[i] << " ";
}
