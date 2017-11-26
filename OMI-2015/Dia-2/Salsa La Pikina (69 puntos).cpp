#include <bits/stdc++.h>
using namespace std;

bool orden(int a, int b) {
    return a > b;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N, K;
    cin >> N >> K;

    int v[N];
    for (int i = 0; i < N; ++i)
        cin >> v[i];
    sort(v, v + N, orden);

    int max_rep = 0, number;
    for (int i = 0, j = 0; i < N; ++i) {
        while (j < N && K - v[i] + v[j] >= 0)
            K -= v[i] - v[j++];
        if (j - i >= max_rep) {
            max_rep = j - i;
            number = v[i];
        }
        K += (v[i] - v[i + 1]) * (j - i - 1);
    }
    cout << max_rep << " " << number;
}
