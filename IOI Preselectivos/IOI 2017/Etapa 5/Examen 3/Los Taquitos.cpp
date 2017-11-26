#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001

int N, M;
long long A[MAXN], B[MAXN], S[MAXN], ans;

int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < M; i++)
        cin >> B[i];

    sort(B, B + M);
    for (int i = 0; i < M; i++)
        S[i + 1] = S[i] + B[i];

    for (int i = 0; i < N; i++) {
        int k = (upper_bound(B, B + M, A[i]) - B);
        ans += A[i] * (2 * k - M) + S[M] - 2 * S[k];
    }

    cout << ans;
}
